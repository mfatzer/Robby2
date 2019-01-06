/*
 * SbrStandby.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#include "SbrStandby.h"
#include "Balancer.h"


SbrStandby::SbrStandby(Balancer& balancer)
: balancer(balancer) {
}

SbrStandby::~SbrStandby() {
}

String SbrStandby::getName() {
	return "Standby";
}

void SbrStandby::onInit() {
	balancer.stopMotors();
	balancer.enableMotors(false);
}

State SbrStandby::onAngle(float angle) {
	if (angle > MIN_READY_ANGLE && angle < MAX_READY_ANGLE) {
		return State::READY;
	}
	else {
		return State::STANDBY;
	}
}
