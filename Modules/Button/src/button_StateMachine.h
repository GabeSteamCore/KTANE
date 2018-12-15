#include "button_module.h"
#include <stdlib.h>

// Definitions
enum states {
    INIT,
    PRESS_AND_RELEASE,
    HOLD,
	BLUE_STRIP,
	YELLOW_STRIP,
	OTHER_STRIP,
	FAILURE,
	SUCCES,
} state;

enum events {
    PR_CONDITION,
    HELD,
    PRESSED_AND_RELEASED,
	HELD_BLUE,
	HELD_YELLOW,
	HELD_OTHER,
	RELEASED_4,
	RELEASED_5,
	RELEASED_1,
	RELEASED_X,
};

// State manager
void step_state(enum events event, Button *butt) {
    switch(state) {
    case INIT:
    case PRESS_AND_RELEASE:
    case HOLD:
	case BLUE_STRIP:
	case YELLOW_STRIP:
	case OTHER_STRIP:
	case FAILURE:
	case SUCCES:
	default:
        break;
    }
}

// States
events init(){
	events evt = INIT;
	//TODO
	return evt
}

events pressAndRelease(){
	events evt = INIT;
	//TODO
	return evt
}

events success(){
	events evt = INIT;
	//TODO
	return evt
}

events hold(){
	events evt = INIT;
	//TODO
	return evt
}

events blue_strip(){
	events evt = INIT;
	//TODO
	return evt
}

events yellow_strip(){
	events evt = INIT;
	//TODO
	return evt
}

events other_strip(){
	events evt = INIT;
	//TODO
	return evt
}

events failure(){
	events evt = INIT;
	//TODO
	return evt
}

events success(){
	events evt = INIT;
	//TODO
	return evt
}
