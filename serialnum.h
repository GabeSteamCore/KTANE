#include <stdbool.h>
#include <string.h>
#define SERIAL_SIZE 6

typedef struct SerialNum{
  char c[SERIAL_SIZE];
  bool isLastDigitOdd;
  bool containsVowel;
}SerialNum;

SerialNum generateSerial(){
  /* Exemples
  W21PL1
  EC6CX3
  GU0FX5
  NV0BW4
  G99AB2
  // Pattern L = lettre, C = chiffre, X = Lettre ou Chiffre
  LXCLLC
  */
}

bool isOdd(int n){
  return n & 1;
}

bool containsVowel(char s[]){
  int size = strlen(s)/sizeof(s[0]);

  for(int i; i<size; i++){
    if ((s[i] == 'A') || (s[i] == 'E') || (s[i] == 'I') || (s[i] == 'O') || (s[i] == 'U') || (s[i] == 'Y')){
      return true;
    }
  }
  return false;
}
