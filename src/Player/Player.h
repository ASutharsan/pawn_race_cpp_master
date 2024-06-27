#ifndef PAWN_RACE_CPP_PLAYER_H
#define PAWN_RACE_CPP_PLAYER_H

#include "Game.cpp"

Color get_color();
bool is_computer_playing();
int number_pawns();
Square **get_all_pawns();
void print_all_valid_moves(Move *moves);
void add_valid_move(int x, int y, int new_x, int new_y, bool is_capture, bool is_enPassant);
Move *get_all_valid_moves();
bool is_passant(int x, int y);
bool is_passed_pawn(Square square);
void make_move(Move *moves);


#endif //PAWN_RACE_CPP_PLAYER_H