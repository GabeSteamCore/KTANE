#include "difficulty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Definition
typedef struct Strikes{
  int failures;
  int maxFailures;
}Strikes;

// Ctor
Strikes *generateStrikes(Difficulty dif/*, int nbModules*/){
  Strikes *s = (Strikes *)malloc(sizeof(Strikes));

  s->failures = 0;
  s->maxFailures = 3-dif;

  return s;
}

// Dtor
// TODO

//Function
bool strike(Strikes *s){
  s->failures += 1;
  return (s->failures >= s->maxFailures);
}

// Serializer
char *strikesToString(Strikes *s){
  char *strikesStr = (char *)malloc(4);
  sprintf(strikesStr, "%d/%d", s->failures, s->maxFailures);

  return strikesStr;
}