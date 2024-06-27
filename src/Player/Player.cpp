#include "Player.h"
#include "stdlib.h"
#include <string>
#include <iostream>

class Player {
private:
    Game *game = (Game *) malloc(sizeof(Game));
    Board *board = (Board *) malloc(sizeof(Board));
    Color color;
    bool is_computer_player;
    int number_moves = 0;
    int number_pawns = 0;

public:
    Player(Game *game_arg, Board *board_arg, Color color_arg, bool isComputerPlayer) {
        game = game_arg;
        board = board_arg;
        color = color_arg;
        is_computer_player = isComputerPlayer;
    }

    void set__opponent(Player opponent) {
        Color opponent_color = color == WHITE ? BLACK : WHITE;
        opponent.color = opponent_color;
    }

    //Returns the player's Color. This may only ever be BLACK or WHITE.
    Color get_color() {
        assert(color != NONE);
        return color;
    }

    //Returns true iff this colour is played by a computer.
    bool is_computer_playing() {
        return is_computer_player;
    }

    int number_pawns_game() {
        int pawns = 0;
        for (int x = 0; x <= BORDER_MAX; x++) {
            for (int y = 0; y <= BORDER_MAX; y++) {
                if (board->get_square(x, y)->occupied_by() == color) {
                    pawns++;
                }
            }
        }
        return pawns;
    }

    //Returns an array of all Squares which are occupied by this player's pawns.
    Square **get_all_pawns() {
        int pawns = 0;
        number_pawns = number_pawns_game();
        auto **all_pawns = (Square **) malloc(sizeof(Square *) * number_pawns);
        for (int x = 0; x <= BORDER_MAX; x++) {
            for (int y = 0; y <= BORDER_MAX; y++) {
                if (board->get_square(x, y)->occupied_by() == color) {
                    all_pawns[pawns] = board->get_square(x, y);
                    pawns++;
                }
            }
        }
        return all_pawns;
    }

    void add_valid_move(Move *all_valid_moves, int x, int y, int new_x, int new_y, bool is_capture,
            bool is_enPassant) {
        auto *from = new Square(x, y);
        auto *to   = new Square(new_x, new_y);
        auto *valid_move = new Move(*from, *to, is_capture, is_enPassant);
        all_valid_moves[number_moves] = *valid_move;
    }

    Move *get_all_valid_moves() {
        Color opponent_color = color == WHITE ? BLACK : WHITE;
        auto *all_valid_moves = (Move *) malloc(sizeof(Move)*50);
        int forward = color == WHITE ? -1 : 1;

        number_pawns = number_pawns_game();

        for (int i = 0; i < number_pawns; i++) {

            Square *square = get_all_pawns()[i];

            int x = square->get_x();
            int y = square->get_y();

            //step forward by one step
            if (board->get_square(x + forward, y)->occupied_by() == NONE) {
                add_valid_move(all_valid_moves, x, y, x + forward, y, false, false);
                number_moves++;
                //2_steps possibility
                if ((x == BLACK_INIT_POS && color == BLACK) || (x == WHITE_INIT_POS && color == WHITE)) {
                    if (board->get_square(x + (2 * forward), y)->occupied_by() == NONE) {
                        add_valid_move(all_valid_moves, x, y, x + (2 * forward), y, false, false);
                        number_moves++;
                    }
                }
            }

            //not en passant
            //left diagonal
            if (y > 0 && (x + forward) >= BORDER_MIN && (x + forward) <= BORDER_MAX) {
                if (board->get_square(x + forward, y - 1)->occupied_by() == opponent_color) {
                    add_valid_move(all_valid_moves, x, y, x + forward, y - 1, true, false);
                    number_moves++;
                }
            }


            //right diagonal
            if (y < 7 && (x + forward) >= BORDER_MIN && (x + forward) <= BORDER_MAX) {
                if (board->get_square(x + forward, y + 1)->occupied_by() == opponent_color) {
                    add_valid_move(all_valid_moves, x, y, x + forward, y + 1, true, false);
                    number_moves++;
                }
            }

            //check if can eat someone en passant
            if ((x == BLACK_TWO_STEP && color == WHITE) || (x == WHITE_TWO_STEP && color == BLACK)) {
                //if last move was 2 steps

                int last_to_x = game->get_last_move()->get_to().get_x();
                int last_to_y = game->get_last_move()->get_to().get_y();

                //check if opponent is next to pawn
                if (abs(last_to_y - y) == 1) {
                    add_valid_move(all_valid_moves, x, y, x + forward, last_to_y, false, true);
                    number_moves++;
                }
            }
        }

        return all_valid_moves;
    }

    void print_all_valid_moves(Move *moves) {
        std::cout << "\nPlayer: ";
        if (color == BLACK) {
            std::cout << "BLACK. ";
        } else {
            std::cout << "WHITE. ";
        }
        std::cout << "All valid moves are:\n";
        for (size_t i = 0; i < number_moves; i++) {
            std::cout << moves[i].getSAN() << ", ";
        }
        std::cout << "\n\n";
    }

    //Check if pawn did a 2 step move
    bool is_passant(int x, int y) {
        if ((x == WHITE_TWO_STEP && color == WHITE) || (x == BLACK_TWO_STEP && color == BLACK)) {
            int last_to_x = game->get_last_move()->get_to().get_x();
            int last_to_y = game->get_last_move()->get_to().get_y();
            //check if it is a 2-step move
            if (abs(game->get_last_move()->get_from().get_x() - last_to_x) > 1) {
                //check if the 2-step move is made by the pawn in the argument
                if ((x == last_to_x) && (y == last_to_y)) {
                    return true;
                }
            }
        }
        return false;

    }

    bool is_passed_pawn(Square square) {
        Color opponent_color = color == WHITE ? BLACK : WHITE;
        //pawn is WHITE
        if (color == WHITE) {
            int left_y = 0;
            int right_y = 7;
            int current_y = square.get_y();
            if (square.get_y() - 1 > BORDER_MIN) {
                left_y = square.get_y() - 1;
            }
            if (square.get_y() + 1 <= BORDER_MAX) {
                right_y = square.get_y() + 1;
            }

            for (int x = square.get_x() - 1; x > BORDER_MIN; x--) {
                for (int y = left_y; y <= right_y; y++) {
                    if (board->get_square(x, y)->occupied_by() == opponent_color) {
                        return false;
                    }
                }
            }
        }
        //pawn is BLACK
        else if (color == BLACK){
            int left_y = BORDER_MIN;
            int right_y = BORDER_MAX;
            int current_y = square.get_y();
            int current_x = square.get_x();
            if (square.get_y() - 1 > BORDER_MIN) {
                left_y = square.get_y() - 1;
            }
            if (square.get_y() + 1 <= BORDER_MAX) {
                right_y = square.get_y() + 1;
            }

            for (int x = square.get_x() + 1; x < BORDER_MAX; x++) {
                for (int y = left_y; y <= right_y; y++) {
                    if (board->get_square(x, y)->occupied_by() == opponent_color) {
                        return false;
                    }
                }
            }
        }

        //check if can be eaten en_passant
        if (is_passant(square.get_x(), square.get_y())) {
            if (square.get_y() + 1 <= BORDER_MAX) {
                if (board->get_square(square.get_x(), square.get_y() + 1)->occupied_by() == opponent_color) {
                    return false;
                }
            }

            if (square.get_y() - 1 > BORDER_MIN) {
                if (board->get_square(square.get_x(), square.get_y() - 1)->occupied_by() == opponent_color) {
                    return false;
                }
            }

        }
        return true;
    }

    void make_move(Move *moves) {
        //computer is playing
        if (is_computer_player) {
           // Move *moves = get_all_valid_moves();
            print_all_valid_moves(moves);
            int choose_move = rand() % number_moves;
            //number_moves = 0;
            Move move = moves[choose_move];
            std::cout << move.getSAN() << '\n';
            int x_from = move.get_to().get_x();
            int y_from = move.get_to().get_y();
            game->apply_move_game(move);
        }
    }

    int get_number_moves() {
        return number_moves;
    }

    void set_number_moves(int number) {
        number_moves = number;
    }

    int get_number_pawns() {
        return number_pawns;
    }

};