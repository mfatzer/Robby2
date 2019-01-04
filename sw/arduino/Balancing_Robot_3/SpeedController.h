/*
 * SpeedController.h
 *
 *  Created on: 30.12.2018
 *      Author: Martin
 */

#ifndef SPEEDCONTROLLER_H_
#define SPEEDCONTROLLER_H_


class SpeedController {
public:
	static int MAX_SPEED;

public:
	SpeedController();
	virtual ~SpeedController();

	void setup();

	// Valid values of speed: MAX_SPEED ... -MAX_SPEED
	void setSpeedOfLeftMotor(int speed);
	// Valid values of speed: MAX_SPEED ... -MAX_SPEED
	void setSpeedOfRightMotor(int speed);

	void enableMotors(boolean enable);
};

#endif /* SPEEDCONTROLLER_H_ */
