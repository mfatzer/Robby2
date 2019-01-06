/*
 * Motor.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#include "Motor.h"

// 16 single cycle instructions
// Leonardo: 16Mhz
void delayOneMicro()
{
  __asm__ __volatile__ (
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop" "\n\t"
    "nop");
}

Motor::Motor(unsigned short directionPin, unsigned short stepPin, boolean revertDirection)
: directionPin(directionPin), stepPin(stepPin), direction(NOT_MOVING), revertDirection(revertDirection) {
}

Motor::~Motor() {
}

void Motor::setup() {
	pinMode(directionPin, OUTPUT);
	pinMode(stepPin, OUTPUT);
	setDirection(Direction::NOT_MOVING);
}

void Motor::step() {
	if (direction != NOT_MOVING) {
		boolean dir = (direction == FORWARD);
		digitalWrite(directionPin, dir ^ revertDirection);

		digitalWrite(stepPin, false);
		delayOneMicro();
		digitalWrite(stepPin, true);
	}
}

void Motor::rotate(long steps) {
	for (int i = 0; i < steps; ++i) {
		step();
	}
}

void Motor::setDirection(Direction dir) {
	direction = dir;
}
