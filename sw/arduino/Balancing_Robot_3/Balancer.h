/*
 * Balancer.h
 *
 *  Created on: 04.01.2018
 *      Author: Martin
 */

#ifndef BALANCER_H_
#define BALANCER_H_

#include "Arduino.h"
#include "PidController.h"
#include "SpeedController.h"


class Balancer {
private:
	const int DEFAULT_TARGET_ANGLE = 0;
	const double MAX_SPEED = 255;
	const double ZERO_SPEED = 0;
	const double MAX_ACCELERATION = 255;

	const unsigned long CONTROL_INTERVAL_IN_MICROS = 10000;

public:
	Balancer(const float kp, const float kd, const float ki, const int zeroAngleOffset);
	virtual ~Balancer();

	void setup();
	void tick(float currentAngle);
	void stopMotors();
	void shake();
	void resetSpeed();
	int getCurrentTargetAngle();
	void enableMotors(boolean enable);

private:
	void setMotorSpeed(int speed);
	void integrateCurrentSpeed(double controlOutput);

private:
	SpeedController speedController;
	const float kp;
	const float kd;
	const float ki;
	const int zeroAngleOffset;
	int targetAngle;
	PidController pid;
	unsigned long lastTime;
	long currentSpeed;
};

#endif /* BALANCER_H_ */
