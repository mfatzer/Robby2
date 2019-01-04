/*
 * Balancer.cpp
 *
 *  Created on: 04.01.2018
 *      Author: Martin
 */

#include "Balancer.h"


Balancer::Balancer(const float kp, const float kd, const float ki, const int zeroAngleOffset)
: kp(kp), kd(kd), ki(ki), zeroAngleOffset(zeroAngleOffset),
  targetAngle(DEFAULT_TARGET_ANGLE),
  lastTime(0),
  currentSpeed(0) {
}

Balancer::~Balancer() {

}

void Balancer::setup() {
	speedController.setup();

	pid.setKp(kp);
	pid.setKd(kd);
	pid.setKi(ki);

	shake();

	lastTime = micros();
}

void Balancer::tick(float currentAngle) {
	unsigned long currentTime = micros();
	float dt = currentTime - lastTime;

	if (dt >= CONTROL_INTERVAL_IN_MICROS) {
		float output = pid.control(dt / 1000000.0, currentAngle, getCurrentTargetAngle());
		integrateCurrentSpeed(output);
		lastTime = currentTime;
	}
}

void Balancer::integrateCurrentSpeed(double controlOutput) {
	controlOutput = constrain(controlOutput, -MAX_ACCELERATION, MAX_ACCELERATION);
	const int newSpeed = constrain(controlOutput + currentSpeed, -255, 255);
//	Serial.print("NewSpeed: ");
//	Serial.println(newSpeed);
	setMotorSpeed(newSpeed);
}

void Balancer::shake() {
	for (int i = 0; i < 4; ++i) {
		setMotorSpeed(100);
		delay(50);
		setMotorSpeed(-100);
		delay(30);
	}
	setMotorSpeed(0);
}

void Balancer::resetSpeed() {
	setMotorSpeed(0);
	pid.reset();
}

int Balancer::getCurrentTargetAngle() {
	return targetAngle + zeroAngleOffset;
}

void Balancer::stopMotors() {
	setMotorSpeed(0);
}

void Balancer::setMotorSpeed(int speed) {
	currentSpeed = speed;
	speedController.setSpeedOfLeftMotor(speed);
	speedController.setSpeedOfRightMotor(speed);
}

void Balancer::enableMotors(boolean enable) {
	speedController.enableMotors(enable);
}
