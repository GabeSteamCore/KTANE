#include <time.h>
#include <stdlib.h>

void initRand(){
  srand((unsigned) time(NULL));
}

int roll(int max){
  //srand(time(NULL));
  return (rand() % max);
}
