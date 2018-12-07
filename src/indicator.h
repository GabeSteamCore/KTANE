#include "random.h"
#include <string.h>
#include <stdlib.h>

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

typedef enum Led{
  ON,
  OFF
}Led;

typedef struct Indicator{
  Label label;
  Led led;
}Indicator;

Label generateLabel(){
  Label l = roll(10);
  return l;
}

Led generateLed(){
  Led l = roll(1);
  return l;
}

Indicator generateIndicator(){
  Indicator i;
  i.label = generateLabel();
  i.led = generateLed();
  return i;
}

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

char *ledToString(Led l){
  switch (l){
    case ON:
      return "ON";
    case OFF:
      return "OFF";
    default :
      return "ERR_LED";
  }
}

char *indicatorToString(Indicator i){
  char *s = (char *) malloc(8);
  char *led = ledToString(i.led);
  char *label = labelToString(i.label);
  strcpy(s, led);
  strcat(s, ";");
  strcat(s, label);
  return s;
}
