#include<stdio.h>
#include <iostream>

#include "../Player/Player.cpp"


int main(int number_args, char **args) {

    bool is_comp_player1 = strcmp(args[2], "P") != 0;
    bool is_comp_player2 = strcmp(args[3], "P") != 0;

    auto *board = new Board(args[4][0], args[5][0]);
    auto *game = new Game(board);

    auto *player1 = new Player(game, board, WHITE, is_comp_player1);
    auto *player2 = new Player(game, board, BLACK, is_comp_player2);

    bool is_current_player1;
    bool is_current_comp;

    bool is_game_finished = false;

    do {
        board->display();
        is_current_player1 = game->get_current_player() == WHITE;
        Player *current_player = is_current_player1 ? player1 : player2;
        Player *other_player = is_current_player1 ? player2 : player1;
        //If current player is not a computer:
        is_current_comp = is_current_player1 ? is_comp_player1 : is_comp_player2;


        //Check if players are stuck
        Move *move = nullptr;
        Move *moves = current_player->get_all_valid_moves();

        if (current_player->get_number_moves() == 0) {
            other_player->get_all_valid_moves();
            if (other_player->get_number_moves() == 0) {
                std::cout << "STALEMATE. ";
            } else if (is_current_player1) {
                std::cout << "The winner is: BLACK. ";
            } else {
                std::cout << "The winner is: WHITE. ";
            }
            is_game_finished = true;
        }


        if (!is_current_comp) {
            //ask for the move to be made:

            current_player->print_all_valid_moves(moves);
            std::string player_move;
            bool is_contained = false;
            const char *san;

            do {
                std::cout << "Enter your move: ";
                std::getline(std::cin, player_move);
                san = player_move.c_str();

                for(int a = 0; a < current_player->get_number_moves(); a++) {
                    if (moves[a].getSAN().size() == strlen(san)) {
                        if (!strcmp(moves[a].getSAN().c_str(), san)) {
                            is_contained = true;
                        }
                    }
                }

                if (!is_contained) {
                    std::cout << "This is not a valid move. ";
                }

            } while (!is_contained);
            move = game->parse_move(san);
            std::cout << "\nThank you, this is your move: '" << player_move << "'.\n" << std::endl;

            game->apply_move_game(*move);


        }
        else if (is_current_player1) {
            player1->make_move(moves);

        } else {
            player2->make_move(moves);

        }


        //Check if game is finished by a pawn getting in last row
        if (game->is_finished()) {
            if (game->get_game_result() == BLACK) {
                std::cout << "The winner is: BLACK. ";
            } else if (game->get_game_result() == WHITE) {
                std::cout << "The winner is: WHITE. ";
            } else {
                std::cout << "STALEMATE. ";
            }
            is_game_finished = true;
        }

        //Check if passed pawn
        else {
            //Go through the board and check if any pawn is a passed pawn.
            int steps_needed_to_win = 10;
            Color winning_color = NONE;

            //Check all pawns from player 1
            for (int i = 0; i < player1->get_number_pawns(); i++) {
                Square *square = player1->get_all_pawns()[i];
                int x = square->get_x();
                int y = square->get_y();

                if (player1->is_passed_pawn(*board->get_square(x, y))) {
                    if (x < steps_needed_to_win) {
                        steps_needed_to_win = x;
                        winning_color = WHITE;
                    }
                }
            }

            //Check all pawns from player 2
            for (int j = 0; j < player2->get_number_pawns(); j++) {
                Square *square = player2->get_all_pawns()[j];
                int x = square->get_x();
                int y = square->get_y();

                if (player2->is_passed_pawn(*board->get_square(x, y))) {
                    if (x < steps_needed_to_win) {
                        steps_needed_to_win = x;
                        winning_color = BLACK;
                    }
                }
            }

            if (winning_color == WHITE) {
                std::cout << "The winner is: WHITE. ";
                is_game_finished = true;
            }
            else if (winning_color == BLACK) {
                std::cout << "The winner is: BLACK. ";
                is_game_finished = true;
            }

        }
        current_player->set_number_moves(0);
    } while (!is_game_finished);

    std::cout << "\n";
    board->display();

    board->free_board();

    return 0;
}