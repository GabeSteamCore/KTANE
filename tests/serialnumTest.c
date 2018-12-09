#include <stdio.h>
#include <string.h>
#include "../src/serialnum.h"

void testgenerateSerialString(){
  printf("\nTESTING generateSerialString\n");
  char *str = generateSerialString();

  printf("%s\n", str);
  free(str);
}

void testisOdd(){
  printf("\nTESTING isOdd\n");
  int even = 2;
  int odd = 13;

  if(isOdd(even)){
    printf("FAILED : isOdd(even) != false\n");
  }

  if(!isOdd(odd)){
    printf("FAILED : isOdd(odd) != true\n");
  }
}

void testcontainsVowel(){
  printf("\nTESTING containsVowel\n");
  char notvowel[2] = {'X', '\0'};
  char vowelA[2] = {'A', '\0'};
  char vowelE[2] = {'E', '\0'};
  char vowelI[2] = {'I', '\0'};
  char vowelO[2] = {'O', '\0'};
  char vowelU[2] = {'U', '\0'};
  char vowelY[2] = {'Y', '\0'};
  char toolong[8] = {'X', 'X', '3', 'X', 'X', '0', 'E', '\0'};

  if (containsVowel(notvowel)){
    printf("FAILED : containsVowel(notvowel) != false\n");
  }

  if (!containsVowel(vowelA)){
    printf("FAILED : containsVowel(vowelA) != true\n");
  }
  if (!containsVowel(vowelE)){
    printf("FAILED : containsVowel(vowelE) != true\n");
  }
  if (!containsVowel(vowelI)){
    printf("FAILED : containsVowel(vowelI) != true\n");
  }
  if (!containsVowel(vowelO)){
    printf("FAILED : containsVowel(vowelO) != true\n");
  }
  if (!containsVowel(vowelU)){
    printf("FAILED : containsVowel(vowelU) != true\n");
  }
  if (!containsVowel(vowelY)){
    printf("FAILED : containsVowel(vowelY) != true\n");
  }

  if (!containsVowel(toolong)){
    printf("FAILED : containsVowel(toolong) != true\n");
  }
}

void testgenerateSerialNum(){
  printf("\nTESTING generateSerialNum\n");
  SerialNum ser = generateSerialNum();

  if(!(strlen(ser.c)==6)){
    printf("FAILED : strlen(ser.c) != 6\n");
  }
  printf("%s\n", ser.c);
  printf("ser.isLastDigitOdd = %d\n", ser.isLastDigitOdd);
  printf("ser.containsVowel = %d\n", ser.containsVowel);

  ser = generateSerialNum();

  if(!(strlen(ser.c)==6)){
    printf("FAILED : strlen(ser.c) != 6\n");
  }
  printf("%s\n", ser.c);
  printf("ser.isLastDigitOdd = %d\n", ser.isLastDigitOdd);
  printf("ser.containsVowel = %d\n", ser.containsVowel);

  ser = generateSerialNum();

  if(!(strlen(ser.c)==6)){
    printf("FAILED : strlen(ser.c) != 6\n");
  }
  printf("%s\n", ser.c);
  printf("ser.isLastDigitOdd = %d\n", ser.isLastDigitOdd);
  printf("ser.containsVowel = %d\n", ser.containsVowel);
}

void testserialnumToString(){
  printf("\nTESTING serialnumToString\n");
  SerialNum ser = generateSerialNum();
  printf("%s\n", serialnumToString(ser));

  free(ser.c);
  ser = generateSerialNum();
  printf("%s\n", serialnumToString(ser));

  free(ser.c);
  ser = generateSerialNum();
  printf("%s\n", serialnumToString(ser));
}

void main(){
  printf("LOG : serialnumTest.c/main\n");

  initRand();

  testgenerateSerialString();
  testisOdd();
  testcontainsVowel();
  testgenerateSerialNum();
  testserialnumToString();
}