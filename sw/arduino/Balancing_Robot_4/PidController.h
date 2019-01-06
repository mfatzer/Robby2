/*
 * PidController.h
 *
 *  Created on: 07.11.2017
 *      Author: Martin
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

class PidController {
public:
	PidController();
	virtual ~PidController();

	float control(float dt, float input, float setPoint);
	void setKp(float kp);
	void setKd(float kd);
	void setKi(float ki);

	void reset();

private:
	float Kp;
	float Kd;
	float Ki;

	float errorSum;
	float errorOld;
};

#endif /* PIDCONTROLLER_H_ */
