#ifndef PAWN_RACE_CPP_BOARD_H
#define PAWN_RACE_CPP_BOARD_H

#include "Move.cpp"

Square get_square(int x, int y);
void apply_move(Move move);
void unapply_move(Move move);
static void print_numbers(int i);
static void print_letters(int j);
void display();
void free_board();


#endif //PAWN_RACE_CPP_BOARD_H
