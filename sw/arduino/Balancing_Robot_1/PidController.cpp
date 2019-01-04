/*
 * PidController.cpp
 *
 *  Created on: 07.11.2017
 *      Author: Martin
 */
#include "Arduino.h"
#include "PidController.h"


PidController::PidController()
: Kp(0.0), Kd(0.0), Ki(0.0) {
	reset();
}

PidController::~PidController() {
}

float PidController::control(float dt, float input, float setPoint) {
	const float error = setPoint - input;
	errorSum += error * dt;

//	Serial.print("dt: ");
//	Serial.print(dt);

	const float pValue = Kp * error;
//	Serial.print(" pValue: ");
//	Serial.print(pValue);
	const float dValue = Kd * (error - errorOld) / dt;
//	Serial.print(" dValue: ");
//	Serial.print(dValue);
	const float iValue = Ki * errorSum;
//	Serial.print(" iValue: ");
//	Serial.println(iValue);

	errorOld = error;

	return pValue + dValue + iValue;
}

void PidController::setKp(float kp) {
	Kp = kp;
}

void PidController::setKd(float kd) {
	Kd = kd;
}

void PidController::setKi(float ki) {
	Ki = ki;
}

void PidController::reset() {
	errorOld = 0.0;
	errorSum = 0.0;
}
