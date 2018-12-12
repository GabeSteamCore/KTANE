#include "random.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROBA_NULL_INDICATOR 50
#define NB_INDICATORS 5

// Definitions
typedef enum Label{
  SND,
  CLR,
  CAR,
  IND,
  FRQ,
  SIG,
  NSA,
  MSA,
  TRN,
  BOB,
  FRK
}Label;

typedef struct Indicator{
  Label label;
  bool led;
}Indicator;

// Ctors
Label generateLabel(){
  Label lab = roll(0, 10);
  return lab;
}

bool generateLed(){
  bool led = roll(0, 1);
  return led;
}

Indicator *generateIndicator(){
  Indicator *ind = (Indicator *)malloc(sizeof(Indicator));
  ind->label = generateLabel();
  ind->led = generateLed();
  return ind;
}

Indicator **generateIndicatorArray(){
  Indicator **ind = (Indicator **)malloc(NB_INDICATORS*sizeof(Indicator));
  initRand();
  for(int i=0; i<NB_INDICATORS; i++){
    if(roll(1,100)<PROBA_NULL_INDICATOR){
      ind[i] = generateIndicator();
    }else{
      ind[i] = NULL;
    }
  }
  return ind;
}

// Serializers
char *labelToString(Label l){
  switch(l){
    case SND:
      return "SND";
    case CLR:
      return "CLR";
    case CAR:
      return "CAR";
    case IND:
      return "IND";
    case FRQ:
      return "FRQ";
    case SIG:
      return "SIG";
    case NSA:
      return "NSA";
    case MSA:
      return "MSA";
    case TRN:
      return "TRN";
    case BOB:
      return "BOB";
    case FRK:
      return "FRK";
    default:
      return "LABEL_ERROR";
  }
}

char *ledToString(bool led){
  if (led){
    return "On";
  }else{
    return "Off";
  }
}

// Serializers
char *indicatorToString(Indicator *ind){
  char *str = (char *) malloc(13);
  char *ledstr = ledToString(ind->led);
  char *labelstr = labelToString(ind->label);

  strcpy(str, ledstr);
  strcat(str, ";");
  strcat(str, labelstr);

  return str;
}

char *indicatorArrayToString(Indicator **ind){
  char *str = (char *)malloc(10);
  strcpy(str, "");

  for (int i=0; i<NB_INDICATORS; i++){
    if (ind[i]){
      strcat(str, "[");
      strcat(str, indicatorToString(ind[i]));
      strcat(str, "]; ");
    }
  }

  return str;
}
