#include "random.h"
#include <stdlib.h>
#include <string.h>

#define PROBA_NULL_BATTERY 50
#define NB_BATTERIES 4

// Definition
typedef enum Battery{
  NOB,
  AA,
  D  
}Battery;

// Ctor
Battery *generateBatteriesArray(){
  Battery *bat = (Battery *)malloc(NB_BATTERIES*sizeof(Battery));

  initRand();

  for(int i=0; i<NB_BATTERIES; i++){
    if(roll(1,100)<PROBA_NULL_BATTERY){
      bat[i] = roll(1,2);
    }else{
      bat[i] = 0;
    }
  }
  return bat;
}

// Dtor
/*void destroyBatteryArray(){

}*/

// Serializers
char *batteryToString(Battery bat){
  switch (bat){
    case NOB:
      return "";
    case AA:
      return "AA";
    case D:
      return "D";
    default:
      return "Battery_ERROR";
  }
}

char *batteryArrayToString(Battery *bat){
  char *str = (char *)malloc(5*NB_BATTERIES+1);
  strcpy(str, "");

  for (int i=0; i<NB_BATTERIES; i++){
    if (bat[i]){
      strcat(str, batteryToString(bat[i]));
      strcat(str, "; ");
    }
  }
  return str;
}

//Batteries
//2D, 1D, 1D 3x2AA, 1x2AA, 1D, 2D, X,