#include "difficulty.h"
#include "utility.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MULT_EASY 1
#define MULT_MEDI 0.9
#define MULT_HARD 0.8
#define MEAN_TIME 27

//Definition
typedef struct Timer{
  int m;
  int s;
}Timer;

// Ctor
Timer *generateTimer(Difficulty dif, int nbModules){
  Timer *t = (Timer *)malloc(sizeof(Timer));
  int tps = (nbModules * MEAN_TIME);
  float mult = 0.0f;

  switch (dif){
  case EASY:
      mult = MULT_EASY;
      break;
  case MEDIUM:
      mult = MULT_MEDI;
      break;
  case HARD:
      mult = MULT_HARD;
      break;
  default:
      mult = MULT_EASY;
      break;
  }
  tps = roundToNearest((tps*mult),30);

  if(tps < 45){
      tps = 45;
  }

  t->m = tps / 60;
  t->s = tps % 60;

  return t;
}

// Dtor
// TODO

//Serializer
char *timerToString(Timer *t){
  char *tmrStr = (char *)malloc(4);
  char s[3];
  strcpy(tmrStr, "");

  sprintf(s, "%d", t->m);
  strcat(tmrStr, s);

  strcat(tmrStr, ":");

  sprintf(s, "%02d", t->s);
  strcat(tmrStr, s);

  return tmrStr;
}

// Functions
void timerDecrement(Timer *t){
  if(t->s <= 0){
    t->s = 59;
    t->m -= 1;
  }
  t->s -= 1;
}

bool timerContains(Timer *t, int x){
  int s_d, s_u;
  s_d = t->s / 10;
  s_u = t->s % 10;

  return ((t->m == x) || (s_d == x) || (s_u == x));
}