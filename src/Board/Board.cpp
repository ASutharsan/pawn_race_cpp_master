#include "Board.h"

class Board {
private:
    char white_gap;
    char black_gap;
    Square ***board;


public:
    Board(char white_gap_arg, char black_gap_arg) {
        white_gap = white_gap_arg;
        black_gap = black_gap_arg;
        board = (Square ***) malloc(sizeof(Square**) * 8);
        assert(board);
        for (int x = 0; x <= BORDER_MAX; x++) {
            board[x] = (Square **) malloc(sizeof(Square *) * 8);
            for (int y = 0; y <= BORDER_MAX; y++) {
                //auto *board[x][y] = new Square(x,y);
                board[x][y] = new Square(x,y);
                //Sets up white pawns
                if (x == BLACK_INIT_POS) {
                    if (y != (black_gap - 'A')) {
                        board[x][y]->set_occupier(BLACK);

                    }
                }

               //Sets up black pawns
               else if (x == WHITE_INIT_POS) {
                   if (y != (white_gap - 'A')) {
                       board[x][y]->set_occupier(WHITE);
                   }
               }

               //No pawn
               else {
                   board[x][y]->set_occupier(NONE);
               }

            }
        }
    }


    Square *get_square(int x, int y) {

        assert(board);

        return board[x][y];
    }

    void apply_move(Move move) {
        int x_from = move.get_from().get_x();
        int y_from = move.get_from().get_y();
        Color occupier = board[x_from][y_from]->occupied_by();
        board[x_from][y_from]->set_occupier(NONE);
        int x_to = move.get_to().get_x();
        int y_to = move.get_to().get_y();
        board[x_to][y_to]->set_occupier(occupier);
        if(move.get_isEnPassantCapture()) {
            if (occupier == BLACK) {
                assert(x_to - 1 <= BORDER_MAX);
                board[x_to - 1][y_to]->set_occupier(NONE);
            } else {
                assert(x_to + 1 <= BORDER_MAX);
                board[x_to + 1][y_to]->set_occupier(NONE);
            }
        }
    }

    void unapply_move(Move move) {
        int x_to = move.get_to().get_x();
        int y_to = move.get_to().get_y();
        Color occupier = board[x_to][y_to]->occupied_by();
        int x_from = move.get_from().get_x();
        int y_from = move.get_from().get_y();
        board[x_to][y_to]->set_occupier(occupier);

        if(move.get_isEnPassantCapture()) {
            board[x_to][y_to]->set_occupier(NONE);
            if (occupier == BLACK) {
                assert(y_to + 1 <= BORDER_MAX);
                board[x_to][y_to + 1]->set_occupier(NONE);
            } else {
                assert(y_to - 1 <= BORDER_MAX);
                board[x_to][y_to - 1]->set_occupier(NONE);
            }
        }

         if (move.get_isCapture()) {
            if (occupier == BLACK) {
                board[x_to][y_to]->set_occupier(WHITE);
            } else {
                board[x_to][y_to]->set_occupier(BLACK);
            }
        }

         else {
            board[x_to][y_to]->set_occupier(NONE);
        }
         board[x_from][y_from]->set_occupier(occupier);
    }


    void display() {
        char white = (char) 'W';
        char black = (char) 'B';
        printf("\t");
        for (int i = 0; i <= BORDER_MAX; i++) {
            char letter = (char) ('A' + i);
            printf("%c\t", letter);
        }
        printf("\n");
        for (int j = 0; j <= BORDER_MAX; j++) {
            printf("%d\t", j + 1);
            for (int k = 0; k <= BORDER_MAX; k++) {
                if (board[j][k]->occupied_by() == WHITE) {
                    printf("%c\t", white);
                }
                else if (board[j][k]->occupied_by() == BLACK) {
                    printf("%c\t", black);
                }
                else {
                    printf(".\t");
                }
            }
            printf("%d\n", j + 1);
        }
        printf("\t");
        for (int i = 0; i <= BORDER_MAX; i++) {
            char letter = (char) ('A' + i);
            printf("%c\t", letter);
        }
        printf("\n");
    }

    void free_board() {
        for (int i = 0; i <= BORDER_MAX; i++) {
                free(board[i]);
            }
        free(board);
    }



};
