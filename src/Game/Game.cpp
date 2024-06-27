#include <iostream>
#include "Game.h"

class Game {
private:
    int index;
    Board *board;
    Move *moves;
    Color current_player;

public:
    Game(Board *board_arg) {
        board = board_arg;
        index = 0;
        moves = (Move *) malloc(sizeof(Move) * 1000);
        current_player = WHITE;
    }

    Color get_current_player() {
        return current_player;
    }

    Move *get_last_move() {
        if (!index) {
            return nullptr;
        }
        return &moves[index - 1];
    }

    void apply_move_game(Move move) {
        moves[index] = move;
        board->apply_move(move);
        current_player = current_player == BLACK ?  WHITE : BLACK;
        index++;
    }

    Color winning_player() {
        for (int y = 0; y < 8; y++) {
            if (board->get_square(0, y)->occupied_by() == WHITE) {
                return WHITE;
            }
            if (board->get_square(7, y)->occupied_by() == BLACK) {
                return BLACK;
            }
        }
        return NONE;
    }

    bool is_finished() {
        //pawn was promoted to the last rank
        return winning_player() != NONE;
    }

    Color get_game_result() {
        return winning_player();
    }

    bool valid_dir_and_steps(int from_x, int to_x, int from_y, int to_y) {
        //check if move was in correct direction
        if (current_player == BLACK) {
            if (from_x < to_x) {
                return false;
            }
        } else {
            if (from_x > to_x) {
                return false;
            }
        }

        //check that only one step was made
        return (abs(from_x - to_x) < 2 && abs(from_y - to_y) < 2);
    }

    //Takes a move in standard algebraic notation and returns the corresponding Move object.
    Move *parse_move(const char *san) {
        int from_x = 0;
        int from_y = 0;
        int to_x = 0;
        int to_y = 0;
        bool is_capture = false;
        bool is_enPassantCapture = false;

        //row behind current player after move
        int back = current_player == WHITE ? 1 : -1;

        //Pawn is captured
        if (san[1] == 'x') {
            assert(san[4] == '\0');
            assert(isalpha(san[0]));
            assert(isalpha(san[2]));
            assert(!isalpha(san[3]));

            to_y   = san[2] - 'a';
            to_x   = san[3] - '1';
            from_y = san[0] - 'a';
            from_x = to_x + back;

            //en passant capture
            if (board->get_square(to_x, to_y)->occupied_by() == NONE) {
                is_enPassantCapture = true;
            }

            //diagonal capture
            else if (board->get_square(to_x, to_y)->occupied_by() != NONE) {
                is_capture = true;
            }

            //invalid move otherwise
            else {
                return nullptr;
            }

            auto *from = new Square(from_x, from_y);
            auto *to   = new Square(to_x, to_y);
            auto *move  = new Move(*from, *to, is_capture, is_enPassantCapture);

            return move;
        }

        //no capture
        assert(san[2] == '\0');
        assert(isalpha(san[0]));
        assert(!isalpha(san[1]));
        to_y     = san[0] - 'a';
        to_x     = san[1] - '1';
        auto *to = new Square(to_x, to_y);

        //invalid move because the square is occupied
        if(to->occupied_by() != NONE) {
            return nullptr;
        }

        //check if the current player (white) pawn advanced by 2 steps
        if (to_x == WHITE_TWO_STEP && current_player == WHITE) {
            if (board->get_square(to_x + 1, to_y)->occupied_by() == NONE) {
                from_x = to_x + 2;
            }
        }

        //check if the current player (black) pawn advanced by 2 steps
        else if (to_x == BLACK_TWO_STEP && current_player == BLACK) {
            if (board->get_square(to_x - 1, to_y)->occupied_by() == NONE) {
                from_x = to_x - 2;
            }
        }

        else {
            from_x = to_x + back;
        }

        from_y = to_y;

        auto *from = new Square(from_x, from_y);
        auto *move  = new Move(*from, *to, is_capture, is_enPassantCapture);

        return move;
    }

};