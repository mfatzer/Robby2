/*
 * Motor.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "Arduino.h"


enum Direction { NOT_MOVING, FORWARD, REVERSE };

class Motor {
public:
	Motor(unsigned short directionPin, unsigned short stepPin, boolean revertDirection);
	virtual ~Motor();

	void setup();
	void step();
	void rotate(long steps);
	void setDirection(Direction dir);

private:
	const unsigned short directionPin;
	const unsigned short stepPin;
	Direction direction;
	boolean revertDirection;
};

#endif /* MOTOR_H_ */
