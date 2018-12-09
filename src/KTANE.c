#include "bomb.h"

int main(){
    Bomb boom = generateBomb();

    char *str = bombToString(boom);
    printf("%s\n", str);
    free(str);
    return 0;
}
