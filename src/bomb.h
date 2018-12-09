#include <stdbool.h>
#include <stdio.h>
#include "serialnum.h"
//#include "time.h"
//#include "indicator.h"
//#include "battery.h"
//#include "port.h"
//#include "module.h"
//#include "strikes.h"

//#define PROBA_NULL_INDICATOR 50
//#define NB_INDICATORS 10
//#define NB_PORTS 5
//#define NB_BATTERIES 2

typedef struct Bomb{
  //Indicator indicators[NB_INDICATORS];
  SerialNum serialnum;
  //Batteries batteries[NB_BATTERIES];
  //Port ports[NB_PORTS];
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

Bomb generateBomb(){
  Bomb b;
  b.serialnum = generateSerialNum();
  // Generate Indicators
  //strncpy(b.indicators, generateIndicatorsArray());
  //b.ports = generatePorts();
  //b.timer = generateTimer();
  //b.modules = set();
  //b.batteries = set();
  //b.strikes = generateStrikes(int difficulty, int ...);
  return b;
}

char *bombToString(Bomb b){
    char *str = (char*)malloc(100); //TODO ajust malloc
    strcpy(str, "Bomb :\n"); //+7
    strcat(str, "  Serial# : "); //+12
    strcat(str, serialnumToString(b.serialnum)); //+19

    return str;
}

/*bool isExploded(Bomb b){
  return b.strikes.difficulty == b.strikes.failures;
}*/
