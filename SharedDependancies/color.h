#include <string.h>

typedef enum Color{
    BLUE,
    WHITE,
    YELLOW,
    RED
}Color;

char *colorToString(Color c){
    switch (c){
        case BLUE:
            return "Blue";
        case WHITE:
            return "White";
        case YELLOW:
            return "Yellow";
        case RED:
            return "Red";
        default :
            return "ERR";
    }
}