#include "random.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NB_PORTS 5

typedef enum Port{
  NOP,
  PS2,
  RJ45,
  DVID,
  SERIAL,
  PARALLEL,
  STEREORCA
}Port;

// Ctors
Port generatePort(){
  return roll(1,6);
}

Port *generatePortArray(){
  Port *p = (Port*)malloc(NB_PORTS*sizeof(Port));
  Port tmp = 0;
  int first = 0;
  bool found = false;

  initRand();

  //Initialize array
  for (int i=0; i<NB_PORTS; i++){
    p[i]=0;
  }

  for(int i=0; i<NB_PORTS; i++){
    tmp = generatePort();

    for (int j=NB_PORTS-1; j>=0; j--){
      if(p[j] == tmp){ //Is tmp in array
        found = true;
      }
      if((p[j] == 0)&&(found==false)){ //first empty array field
        first = j;
      }
    }
    if(!found){ //Assign tmp to first empty field
      found = false;
      p[first] = tmp;
    }
  }

  return p;
}

// Dtor
void destoyPorts(Port *p){
  free(p);
}

// Serializers
char *portToString(Port p){
  switch(p){
    case NOP:
      return NULL;
    case DVID:
      return "DVI-D";
    case PARALLEL:
      return "Parallel";
    case PS2:
      return "PS2";
    case RJ45:
      return "RJ45";
    case SERIAL:
      return "Serial";
    case STEREORCA:
      return "Stereo RCA";
    default:
      return "Port_ERROR";
  }
}

char *portArrayToString(Port *p){
  char *portsStr = (char*)malloc(95);
  int i=0;

  strcpy(portsStr,"");

  while((p[i] != 0)&&(i<NB_PORTS)){
    strcat(portsStr, portToString(p[i]));
    strcat(portsStr, "; ");
    i++;
  }

  return portsStr;
}

/* Exemples
[Parallel PS2 RCA RJ45] [PS2 RJ45] [Serial] []

*/