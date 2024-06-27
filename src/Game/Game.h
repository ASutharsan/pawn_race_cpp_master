#ifndef PAWN_RACE_CPP_GAME_H
#define PAWN_RACE_CPP_GAME_H

#include "Board.cpp"

Color get_current_player();
Move *get_last_move();
void apply_move_game(Move move);
Color winning_player();
bool is_finished();
Color get_game_result();
bool valid_dir_and_steps(int from_x, int to_x, int from_y, int to_y);
Move *parse_move(const char *san);


#endif //PAWN_RACE_CPP_GAME_H
