#include "../../SharedDependancies/random.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define NB_MODULES_MAX 11

// Definitions
typedef struct Module{
  bool solved; //true = solved; false = unsolved
  //Pin ID ?
}Module;

// Ctor
Module *generateModule(){
  Module *mod = (Module *)malloc(sizeof(Module));
  mod->solved = false;
  return mod;
}

Module **generateModuleArray(){
  Module **mods = (Module **)malloc(NB_MODULES_MAX*sizeof(Module));

  for (int i=0; i<NB_MODULES_MAX; i++){
    mods[i] = generateModule();
    printf("mods[%d].solved = %d\n", i, mods[i]->solved);
  }

  return mods;
}

// Dtor

// Serializers
char *moduleToString(Module *mod){
  char *modStr = (char *)malloc(9);

  strcpy(modStr, "");
  
  if(mod->solved){
    strcat(modStr, "Solved");
  }else{
    strcat(modStr, "Unsolved");
  }
  return modStr;
}

char *moduleArrayToString(Module **mod){
  char *modStr = (char *)malloc(13);
  
  strcpy(modStr, "");

  for(int i=0; i<NB_MODULES_MAX; i++){
    strcat(modStr, "[");
    strcat(modStr, moduleToString(mod[i]));
    strcat(modStr, "]; ");
    printf("mod[%d].solved = %d; modStr = %s\n", i, mod[i]->solved, modStr);
  }
  
  return modStr;
}