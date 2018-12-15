#include "button_module.h"
#include "../../../SharedDependancies/communication.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define DEFAULT_STATE INIT

// Definitions
Button butt;
int batteries = 0;
int isLitFRK = false;

enum States {
    INIT,
    PRESS_AND_RELEASE,
    HOLD,
	LIT_STRIP,
	FAILURE,
	SUCCES,
	SOLVED
}state;

enum events {
	IDLE,
    HELD,
	PRESSED_AND_RELEASED,
}event;

// States
int machineInit(int batteries, bool isLitFRK){
	event = IDLE;

	if ((butt.label == DETONATE && batteries > 1) ||
		(butt.buttonColor == RED && butt.label == HOLD) ||
		(isLitFRK && batteries > 2)){
		return PRESS_AND_RELEASE;
	}else{
		return HOLD;
	}
	
}

int pressAndRelease(){
	while (event == IDLE){}

	switch (event){
		case HELD :
			return FAILURE;
		case PRESSED_AND_RELEASED:
			return SUCCES;
		default :
			return DEFAULT_STATE;
	}
}

int hold(){
	while (event == IDLE){}

	switch (event){
		case HELD :
			return LIT_STRIP;
		case PRESSED_AND_RELEASED:
			return FAILURE;
		default :
			return DEFAULT_STATE;
	}
}

int lit_strip(){
	// TODO : Switch strip ON
	while (event == HELD){}

	switch (butt.stripColor){
		case BLUE :
			if (timerContains(4)){
				return SUCCES;
			}else{
				return FAILURE;
			}
		case YELLOW :
			if (timerContains(5)){
				return SUCCES;
			}else{
				return FAILURE;
			}
		default :
			if (timerContains(1)){
				return SUCCES;
			}else{
				return FAILURE;
			}
	}
}

int failure(){
	sendStrike();
	return INIT;
}

int success(){
	// TODO : Switch On success LED
	sendSuccess();
	return SOLVED;
}

// State manager
void step_state(int batteries, bool isLitFRK) {
    switch(state) {
		case INIT:
			state = machineInit(batteries, isLitFRK);
			break;

		case PRESS_AND_RELEASE:
			state = pressAndRelease();
			break;

		case HOLD:
			state = hold();
			break;

		case LIT_STRIP:
			state = lit_strip();
			break;

		case FAILURE:
			state = failure();
			break;

		case SUCCES:
			state = success();
			break;

		case SOLVED:
			state = SOLVED;
			break;

		default:
			state = DEFAULT_STATE;
			break;
    }
}