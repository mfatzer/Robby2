/*
 * SbrStateMachine.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#include "Arduino.h"
#include "SbrStateMachine.h"

SbrStateMachine::SbrStateMachine(Balancer& balancer)
: standbyState(balancer), readyState(balancer) {
	setState(State::STANDBY);
}

SbrStateMachine::~SbrStateMachine() {
}

void SbrStateMachine::onAngle(float angle) {
	State newState = this->currentState->onAngle(angle);
	setState(newState);
}

void SbrStateMachine::setState(State newState) {
	if (newState == State::READY) {
		setState(&readyState);
	} else if (newState == STANDBY) {
		setState(&standbyState);
	}
}

void SbrStateMachine::setState(SbrState* newState) {
	if (newState != currentState) {
		currentState = newState;
		currentState->onInit();
		Serial.println("New State: " + currentState->getName());
	}
}

boolean SbrStateMachine::isReady() {
	return currentState == &readyState;
}
