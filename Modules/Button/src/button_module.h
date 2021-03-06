#include "../../../SharedDependancies/color.h"
#include "../../../SharedDependancies/random.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// Definitions
typedef enum ButtonLabel{
    PRESS,
    HOLD,
    ABORT,
    DETONATE
}ButtonLabel;

typedef struct Button{
    bool successLED;
    bool pressed;
    Color stripColor;
    Color buttonColor;
    ButtonLabel label;
}Button;

// Ctor
Color generateColor(){
    return roll(0,3);
}

ButtonLabel generateButtonLabel(){
    return roll(0,3);
}

Button generateButton(){
    Button butt;

    initRand();
    butt.successLED = false;
    butt.pressed = false;
    butt.stripColor = generateColor();
    butt.buttonColor = generateColor();
    butt.label = generateButtonLabel();
    return butt;
}

// Dtor
// TODO

// Serializer
char *buttonLabelToString(ButtonLabel bl){
    switch (bl){
        case PRESS :
            return "PRESS";
        case HOLD :
            return "HOLD";
        case ABORT :
            return "ABORT";
        case DETONATE :
            return "DETONATE";
        default :
            return "ERR";
    }
}

char *buttonToString(Button butt){
    char *bStr = (char *)malloc(50);
    char *tmp = (char *)malloc(15);

    sprintf(tmp, "pressed: %d; ", butt.pressed); //12
    strcpy(bStr, tmp);

    sprintf(tmp, "%s ", colorToString(butt.buttonColor)); //14
    strcat(bStr, tmp);

    sprintf(tmp, "\"%s\" button; ", buttonLabelToString(butt.label)); //9
    strcat(bStr, tmp);

    sprintf(tmp, "%s strip; ", colorToString(butt.stripColor)); //13
    strcat(bStr, tmp);

    return bStr;
}

// Display
void displayButton(Button *butt){
    // TODO
    // Switch on LEDs + Set colors + ...
    printf("%s\n", buttonToString(butt));
}

// "Detonate"   >1 bat.     Press/Release
// lit.FRK      >2 bat.     Press/Release
// Red          "Hold"      Press/Release
// --Else--                 Hold
//                          Blue    4
//                          Yellow  5
//                          -Else-  1
