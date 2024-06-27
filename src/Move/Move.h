#ifndef PAWN_RACE_CPP_MOVE_H
#define PAWN_RACE_CPP_MOVE_H

#include "Square.cpp"

Square get_from();
Square get_to();
bool get_isCapture();
bool get_isEnPassantCapture();
static char get_letter(int number);
std::string getSAN();


#endif //PAWN_RACE_CPP_MOVE_H
