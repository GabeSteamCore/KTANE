#ifndef RANDOM
#define RANDOM

#include <stdlib.h>
#include <time.h>

void initRand(){
  srand((unsigned) time(NULL));
}

/*
Generates random integer numbers in range [min; max] included
 */
int roll(int min, int max){
  return (rand() % (max+1-min))+min;
}

#endif