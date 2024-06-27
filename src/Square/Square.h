#ifndef PAWN_RACE_CPP_SQUARE_H
#define PAWN_RACE_CPP_SQUARE_H

enum Color {
    BLACK = 1,
    WHITE = 2,
    NONE = 3
};

int get_x();
int get_y();
Color occupied_by();
void set_occupier(Color color);


#define WHITE_INIT_POS 6
#define BLACK_INIT_POS 1
#define BORDER_MIN     0
#define BORDER_MAX     7
#define WHITE_TWO_STEP 4
#define BLACK_TWO_STEP 3


#endif //PAWN_RACE_CPP_SQUARE_H
