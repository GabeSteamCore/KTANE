#include "port.h"
#include <stdio.h>

//#define NB_PORTS 5

void main(){
  initRand();
  Port *p = generatePorts();

  printf("Ports = %s\n", portArrayToString(p));
  printf("\n");
}
