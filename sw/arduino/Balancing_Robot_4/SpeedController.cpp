/*
 * SpeedController.cpp
 *
 *  Created on: 30.12.2018
 *      Author: Martin
 */

#include "Arduino.h"
#include "SpeedController.h"
#include "BoardSetup.h"
#include "Motor.h"
#include "Math.h"

int SpeedController::MAX_SPEED = 255;

const float PROC_CLOCK = 16000000;
const float PRE_SCALE = 256;
const float STEP_TIME = 1 / PROC_CLOCK * PRE_SCALE * 1000000;

const int MINIMAL_DELAY_IN_MICROS = 100; //60;
const long MAXIMUM_DELAY_IN_MILLIS = 16000;


Motor leftMotor(MOTOR_LEFT_DIR, MOTOR_LEFT_STEP, false);
Motor rightMotor(MOTOR_RIGHT_DIR, MOTOR_RIGHT_STEP, true);


ISR(TIMER1_COMPA_vect) {
	leftMotor.step();
}

ISR(TIMER3_COMPA_vect) {
	rightMotor.step();
}

Direction getDirection(int speed) {
	if (speed > 0) {
		return Direction::FORWARD;
	} else if (speed < 0) {
		return Direction::REVERSE;
	} else {
		return Direction::NOT_MOVING;
	}
}

long getCounter(int speed) {
//	Serial.print("Speed: ");
//	Serial.println(speed);

	speed = abs(speed);
	speed = constrain(speed, 0, SpeedController::MAX_SPEED);

//	Serial.print("Speed: ");
//	Serial.println(speed);


	const float exponent = (SpeedController::MAX_SPEED - speed) / 51.0;
	const float stepIntervalInMicros = pow(2, exponent) * MINIMAL_DELAY_IN_MICROS;

	const long counter = (long) (stepIntervalInMicros / STEP_TIME);

//	Serial.print("Counter: ");
//	Serial.println(counter);
	return counter;
}

SpeedController::SpeedController() {
	// Nothing to do
}

SpeedController::~SpeedController() {
	this->enableMotors(false);
}


void SpeedController::setup() {
	leftMotor.setup();
	rightMotor.setup();

	this->enableMotors(false);

	noInterrupts();

	// Initialize Timer 1 for leftMotor
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	OCR1A = 1000;            // compare match register 16MHz/256/2Hz
	TCCR1B |= (1 << WGM12);   // CTC mode
	TCCR1B |= (1 << CS12);    // 256 prescaler
	TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt

	// Initialize Timer 3 for rightMotor
	TCCR3A = 0;
	TCCR3B = 0;
	TCNT3 = 0;

	OCR3A = 1000;            // compare match register 16MHz/256/2Hz
	TCCR3B |= (1 << WGM12);   // CTC mode
	TCCR3B |= (1 << CS12);    // 256 prescaler
	TIMSK3 |= (1 << OCIE1A);  // enable timer compare interrupt

	interrupts();
}

// Valid value of speed: -255 ... 255
void SpeedController::setSpeedOfLeftMotor(int speed) {
	leftMotor.setDirection(getDirection(speed));
	OCR1A = getCounter(speed);
	if (TCNT1 > OCR1A) {
		TCNT1 = 0;
	}
}

// Valid value of speed: -255 ... 255
void SpeedController::setSpeedOfRightMotor(int speed) {
	rightMotor.setDirection(getDirection(speed));
	OCR3A = getCounter(speed);
	if (TCNT3 > OCR3A) {
		TCNT3 = 0;
	}
}

void SpeedController::enableMotors(boolean enable) {
	Serial.println("SpeedController::enableMotors: " + enable ? "H" : "L");
	digitalWrite(MOTOR_ENABLE_PIN, ! enable);
	if (! enable) {
		this->setSpeedOfLeftMotor(0);
		this->setSpeedOfRightMotor(0);
	}
}

