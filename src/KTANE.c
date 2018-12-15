#include "bomb.h"
#include <stdio.h>

#define BOMB_LVL HARD
#define NB_MODULES 7

int main(){
    printf("%s\n", bombToString(generateBomb(BOMB_LVL, NB_MODULES)));
    
    return 0;
}
