#include "button_StateMachine.h"
#include "../../../SharedDependancies/indicator.h"
#include <stdio.h>

void ISR_Button(/*bouton change*/){
	// TODO
	//butt.pressed = ButtonPortValue
	if(butt.pressed){
		// TODO : Partir un timer
	}else{
		event = IDLE;
	}
}

void ISR_Timer(/*Timer OVF*/){
	// TODO
	if(butt.pressed){
		event = HELD;
	}else{
		event = PRESSED_AND_RELEASED;
	}
}

void init(){
	butt = generateButton();
	state = INIT;
	// TODO
	//batteries = getBatteries();
	//isLitFRK = isIndicator(true, FRK);
}

int main() {
	init();

	while(state != SOLVED){
		step_state(batteries, isLitFRK); // Change state
	}

	//TODO : Switch On Success LED
	while(1){} // Module solved

	return 0;
}