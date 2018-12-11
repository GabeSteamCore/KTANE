#include "serialnum.h"
#include "port.h"
//#include "time.h"
//#include "indicator.h"
//#include "battery.h"
//#include "module.h"
//#include "strikes.h"
#include <stdbool.h>
#include <stdio.h>

//#define PROBA_NULL_INDICATOR 50
//#define NB_INDICATORS 10
//#define NB_BATTERIES 2

typedef struct Bomb{
  SerialNum serialnum;
  Port *ports;
  //Indicator indicators[NB_INDICATORS];
  //Batteries batteries[NB_BATTERIES];
  //Module modules[11];
  //Time timer;
  //Strikes strikes;
}Bomb;

/*Indicator generateIndicatorsArray(){
  Indicator indicators[NB_INDICATORS];
  int rol;
  initRand();

  for (int i = 0; i < NB_INDICATORS; i++){
    rol = roll(99);
    if(rol<PROBA_NULL_INDICATOR){
      indicators[i] = generateIndicator();
    }
    printf("%d\n", rol);
    printf("indicators[%d] = %s\n", i, indicatorToString(indicators[i]));
  }
  return *indicators;
}*/

// Ctor
Bomb generateBomb(){
  Bomb b;

  b.serialnum = generateSerialNum();
  b.ports = generatePorts();

  // Generate Indicators
  //strncpy(b.indicators, generateIndicatorsArray());
  //b.timer = generateTimer();
  //b.modules = set();
  //b.batteries = set();
  //b.strikes = generateStrikes(int difficulty, int ...);
  return b;
}

// Dtor
/*void destoyBomb(){
  destoyPorts(Port *p){
  free(b);
}*/

//Serializer
char *bombToString(Bomb b){
    char *str = (char*)malloc(150); //TODO ajust malloc
    strcpy(str, "Bomb :\n"); //+7
    strcat(str, "  Serial# : "); //+12
    strcat(str, serialnumToString(b.serialnum)); //+19 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Ports : "); //+10
    strcat(str, portArrayToString(b.ports)); //+60 (max)
    strcat(str, "\n"); //+1

    return str;
}

/*bool isExploded(Bomb b){
  return b.strikes.difficulty == b.strikes.failures;
}*/
