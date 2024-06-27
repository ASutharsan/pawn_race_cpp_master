#include <string>
#include "Move.h"
#include "stdbool.h"
#include "string.h"


class Move {
private:
    int from_x;
    int from_y;
    int to_x;
    int to_y;
    bool is_capture;
    bool is_enPassantCapture;

public:
    //Constructor: Creates a new Move with all relevant information about a move.
    Move(Square from, Square to, bool isCapture, bool isEnPassantCapture) {
        from_x = from.get_x();
        from_y = from.get_y();
        to_x = to.get_x();
        to_y = to.get_y();
        is_capture = isCapture;
        is_enPassantCapture = isEnPassantCapture;
    }

    //Returns the originating Square of the move.
    Square get_from() {
        return Square(from_x, from_y);
    }

    //Returns the target Square of the move.
    Square get_to() {
        return Square(to_x, to_y);
    }

    //Returns whether this move is a capture.
    bool get_isCapture() {
        return is_capture;
    }

    //Returns whether this move was an en passant capture.
    bool get_isEnPassantCapture() {
        return is_enPassantCapture;
    }


    static char get_letter(int number) {
        switch(number) {
            case 0:
                return 'a';
            case 1:
                return 'b';
            case 2:
                return 'c';
            case 3:
                return 'd';
            case 4:
                return 'e';
            case 5:
                return 'f';
            case 6:
                return 'g';
            case 7:
                return 'h';
            default:
                return 'a';
        }
    }

    //Returns the short algebraic notation for this move.
    std::string getSAN() {
        auto new_x = std::to_string(to_x + 1);

        if (is_capture || is_enPassantCapture) {
            return get_letter(from_y) + std::string("x") + get_letter(to_y) + new_x ;
        }

        return get_letter(to_y) + new_x;
    }

};
