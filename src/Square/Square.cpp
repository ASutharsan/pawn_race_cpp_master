#include <assert.h>
#include "Square.h"

class Square {

private:
    int x_coord;
    int y_coord;
    Color occupier_color;

public:
    //Constructor Square: Initialises an empty square with the given coordinates.
    Square(int x, int y) {
        assert(x <= 7);
        assert(x >= 0);
        assert(y <= 7);
        assert(y >= 0);
        x_coord = x;
        y_coord = y;
        occupier_color = NONE;
    }

    int get_x() {
        return x_coord;
    }

    int get_y() {
        return  y_coord;
    }

    Color occupied_by() {
        assert(occupier_color);
        return occupier_color;
    }

    void set_occupier(Color color) {
        occupier_color = color;
    }
};