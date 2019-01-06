/*
 * SbrReady.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#include "SbrReady.h"
#include "Balancer.h"


SbrReady::SbrReady(Balancer& balancer)
: balancer(balancer) {
}

SbrReady::~SbrReady() {
}

String SbrReady::getName() {
	return "Ready";
}

void SbrReady::onInit() {
	balancer.enableMotors(true);
	balancer.shake();
	balancer.resetSpeed();
}

State SbrReady::onAngle(float angle) {
	if (angle > MIN_VALID_ANGLE && angle < MAX_VALID_ANGLE) {
		balancer.tick(angle);
		return State::READY;
	}
	else {
		balancer.stopMotors();
		return State::STANDBY;
	}
}
