#include "random.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PROBA_NULL_BATTERY 50
#define NB_BATTERIES 4

// Definition
typedef enum Battery{
  NOB,
  AA,
  D  
}Battery;

// Ctor
Battery generateBattery(){
  //int r = ;
  //printf("generateBattery : %d\n", r);
  return roll(1,2);
}

Battery *generateBatteriesArray(){
  Battery *bat = (Battery *)malloc(NB_BATTERIES*sizeof(Battery));
  int j=0;

  initRand();

  //Initialize array
  for (int i=0; i<NB_BATTERIES; i++){
    bat[i]=0;
  }

  for(int i=0; i<NB_BATTERIES; i++){
    if(roll(1,100)<PROBA_NULL_BATTERY){
      bat[j] = generateBattery();
      j++;
    }
  }
  return bat;
}

// Dtor
void destroyBatteryArray(Battery *bat){
  free(bat);
}

// Serializers
char *batteryToString(Battery bat){
  switch (bat){
    case NOB:
      return NULL;
    case AA:
      return "AA";
    case D:
      return "D";
    default:
      return "Battery_ERROR";
  }
}

char *batteryArrayToString(Battery *bat){
  char *batStr = (char *)malloc(5*NB_BATTERIES+1);
  int i=0;

  strcpy(batStr, "");

  while((bat[i] != 0) && (i<NB_BATTERIES)){
    strcat(batStr, batteryToString(bat[i]));
    strcat(batStr, "; ");
    i++;
  }

  return batStr;
}

//Batteries
//2D, 1D, 1D 3x2AA, 1x2AA, 1D, 2D, X,