#ifdef false

#include "random.h"
#include <string.h>
#include <stdlib.h>

#define PROBA_NULL_INDICATOR 50
#define NB_INDICATORS 10

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
  Indicator *i = (Indicator *)malloc(sizeof(Indicator));
  i->label = generateLabel();
  i->led = generateLed();
  return i;
}

Indicator *generateIndicatorArray(){
  Indicator *ind = (Indicator *)malloc(NB_INDICATORS*sizeof(Indicator));

  for(int i=0; i<NB_INDICATORS; i++){
    if(roll(1,100)<PROBA_NULL_INDICATOR){
      ind[i] = generateIndicator();
    }else{
      ind[i] = NULL;
    }
  }
  return i;
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

char *ledToString(Indicator i){
  switch (i.led){
    case false:
      return "Off"
    case true:
      return "On"
    default:
      return "LED_ERROR"
  }
}

// Serializers
char *indicatorToString(Indicator i){
  char *str = (char *) malloc(13);
  char *ledstr = ledToString(i.led);
  char *labelstr = labelToString(i.label);
  strcpy(str, ledstr);
  strcat(str, ";");
  strcat(str, labelstr);
  return str;
}

char *indicatorArrayToString(Indicator *i){
  char *str = (char *)malloc(10);
  strcpy(str, "");
  return str;
}

#endif
