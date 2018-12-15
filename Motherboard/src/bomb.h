#include "serialnum.h"
#include "port.h"
#include "indicator.h"
#include "battery.h"
#include "timer.h"
#include "difficulty.h"
#include "strikes.h"
#include "module.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct Bomb{
  SerialNum serialnum;
  Port *ports;
  Battery *batteries;
  Indicator **indicators;
  Module **modules;
  Timer *timer;
  Strikes *strikes;
}Bomb;

// Ctor
Bomb generateBomb(Difficulty lvl, int nMods){
  Bomb b;

  b.serialnum = generateSerialNum();
  b.ports = generatePortArray();
  b.batteries = generateBatteriesArray();
  b.indicators = generateIndicatorArray();
  b.modules = generateModuleArray();
  b.timer = generateTimer(lvl, nMods);
  b.strikes = generateStrikes(lvl);
  return b;
}

// Dtor
/*void destoyBomb(){
  destoyPorts(Port *p){
  free(b);
}*/

//Serializer
char *bombToString(Bomb b){
    char *str = (char*)malloc(256); //TODO ajust malloc
    strcpy(str, "Bomb :\n"); //+7
    strcat(str, "  Serial# : "); //+12
    strcat(str, serialnumToString(b.serialnum)); //+19 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Ports : "); //+10
    strcat(str, portArrayToString(b.ports)); //+60 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Batteries : "); //+14
    strcat(str, batteryArrayToString(b.batteries));//+21 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Indicators : "); //+15
    strcat(str, indicatorArrayToString(b.indicators)); //+35 (max)
    strcat(str, "\n"); //+1
    strcat(str, "  Timer : "); //+10
    strcat(str, timerToString(b.timer)); //+4
    strcat(str, "\n"); //+1
    strcat(str, "  Strikes : "); //+12
    strcat(str, strikesToString(b.strikes)); //+4
    strcat(str, "\n"); //+1
    strcat(str, "  Modules : "); //+12
    strcat(str, moduleArrayToString(b.modules)); //+13
    strcat(str, "\n"); //+1

    return str;
}

/*bool isExploded(Bomb b){
  return b.strikes.difficulty == b.strikes.failures;
}*/
