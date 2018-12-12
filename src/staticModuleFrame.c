#ifdef false
#include "module.h"
#define HIGH 1
#define LOW 0

ModuleState state;
... statePin;

void init(){
  state = UNSOLVED;
  statePin = HIGH;

  //Set Up Module
}

void main(){
  init();

  //Unsolved loop
  while(1/*Solving condition*/){

  }

  //statePin = LOW
  //Solved loop
  while(1);
}

#endif