#include "button_module.h"
#include <stdio.h>

// "Detonate"   >1 bat.     Press/Release
// lit.FRK      >2 bat.     Press/Release
// Red          "Hold"      Press/Release
// --Else--                 Hold
//                          Blue    4
//                          Yellow  5
//                          -Else-  1
// State Machine ?

int main() {
	printf("%s", buttonToString(generateButton()));
	return 0;
}