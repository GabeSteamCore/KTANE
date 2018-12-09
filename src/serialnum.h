#include <stdbool.h>
#include <string.h>
#include "random.h"

typedef struct SerialNum{
  char *c;
  bool isLastDigitOdd;
  bool containsVowel;
}SerialNum;

char *generateSerialString(){
  char *str = (char *)malloc(7);

  //Generate upper case letter
  str[0] = roll(65, 90);

  //Generate letter or number
  if (roll(0,1)){
    str[1] = roll(65, 90);
  }else{
    str[1] = roll(48, 57);
  }

  //Generate number
  str[2] = roll(48, 57);

  //Generate upper case letter
  str[3] = roll(65, 90);

  //Generate upper case letter
  str[4] = roll(65, 90);

  //Generate number
  str[5] = roll(48, 57);

  str[6] = '\0';

  return str;
}

bool isOdd(int n){
  return n & 1;
}

bool containsVowel(char s[]){
  int size = strlen(s);

  for(int i=0; i<size; i++){
    if ((s[i] == 'A') || (s[i] == 'E') || (s[i] == 'I') || (s[i] == 'O') || (s[i] == 'U') || (s[i] == 'Y')){
      return true;
    }
  }
  return false;
}

SerialNum generateSerialNum(){
  SerialNum ser;
  ser.c = generateSerialString();
  ser.isLastDigitOdd = isOdd(ser.c[5]);
  ser.containsVowel = containsVowel(ser.c);

  return ser;
}

char *serialnumToString(SerialNum ser){
  char *str = (char*)malloc(20);
  strcpy(str, ser.c);

  if (ser.isLastDigitOdd){
    strcat(str, ";Odd;");
  }else{
    strcat(str, ";Even;");
  }

  if(ser.containsVowel){
    strcat(str, "Vowel");
  }else{
    strcat(str, "NoVowel");
  }

  return str;
}


/* Exemples
  W21PL1; EC6CX3; GU0FX5; NV0BW4; G99AB2
  // Pattern L = lettre, N = Number, X = Lettre or Number
  LXNLLN
  */
