#include <stdbool.h>
#include "time.h"
#include "serialnum.h"
#include "indicator.h"
#include "battery.h"
#include "port.h"
#include "module.h"
#include "strikes.h"

#define PROBA_NULL_INDICATOR 50
#define NB_INDICATORS 10
#define NB_PORTS 5
#define NB_BATTERIES 2

typedef struct Bomb{
  Indicator indicators[NB_INDICATORS];
  SerialNum serial;
  Batteries batteries[NB_BATTERIES];
  Port ports[NB_PORTS];
  Module modules[11];
  Time timer;
  Strikes strikes;
}Bomb;

bool isExploded(Bomb b){
  return b.strikes.difficulty == b.strikes.failures;
}

Bomb generateBomb(){
  Bomb b;
  int rol;
  initRand();

  // Generate Indicators
  for (int i = 0; i < NB_INDICATORS; i++){
    rol = roll(99);
    if(rol<PROBA_NULL_INDICATOR){
      b.indicators[i] = generateIndicator();
    }
    printf("%d\n", rol);
    printf("indicators[%d] = %s\n", i, indicatorToString(b.indicators[i]));
  }

  b.serial = generateSerial();


  //b.ports = generatePorts();
  //b.timer = generateTimer();
  //b.modules = set();
  //b.batteries = set();
  //b.strikes = generateStrikes(int difficulty, int ...);
  return b;
}

void printBomb(Bomb b){
  char *indStr = indicatorToString(b.indicators[0]);

  printf("Bomb :\n");
  //Print Indicator
  for (int i = 1; i<NB_INDICATORS; i++){
    if (indStr){
      printf("  Indicator = %s\n", indStr);
      free(indStr);
    }else{
      printf("  Indicator = ERROR\n");
    }
  }

  //Print Serial number
  //Print Batteries
  //Print Ports
  //Print Modules
  //Print Timer

  //Print Strikes
  //printf("  Strikes = %d\n", b.strikes);
}