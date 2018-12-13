#include "serialnum.h"
#include "port.h"
#include "indicator.h"
#include "battery.h"
#include <stdbool.h>
#include <stdio.h>

//#define NB_BATTERIES 2

typedef struct Bomb{
  SerialNum serialnum;
  Port *ports;
  Battery *batteries;
  Indicator **indicators;
  //Module modules[11];
  //Time timer;
  //Strikes strikes;
}Bomb;

// Ctor
Bomb generateBomb(){
  Bomb b;

  b.serialnum = generateSerialNum();
  b.ports = generatePortArray();
  b.batteries = generateBatteriesArray();
  b.indicators = generateIndicatorArray();
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
    char *str = (char*)malloc(187); //TODO ajust malloc
    strcpy(str, "Bomb :\n"); //+7
    strcat(str, "  Serial# : "); //+12
    strcat(str, serialnumToString(b.serialnum)); //+19 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Ports : "); //+10
    strcat(str, portArrayToString(b.ports)); //+60 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Batteries : "); //+14
    strcat(str, batteryArrayToString(b.batteries));//+21(max)
    strcat(str, "\n"); //+1
    strcat(str, "  Indicators : "); //+15
    strcat(str, indicatorArrayToString(b.indicators)); //+35 (max)
    strcat(str, "\n"); //+1

    return str;
}

/*bool isExploded(Bomb b){
  return b.strikes.difficulty == b.strikes.failures;
}*/
