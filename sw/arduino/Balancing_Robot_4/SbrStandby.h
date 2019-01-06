/*
 * SbrStandby.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef SBRSTANDBY_H_
#define SBRSTANDBY_H_

#include "SbrState.h"

class Balancer;

class SbrStandby: public SbrState {
public:
	SbrStandby(Balancer& balancer);
	virtual ~SbrStandby();

	virtual String getName();
	virtual void onInit();
	virtual State onAngle(float angle);

private:
	const float MIN_READY_ANGLE = -2.0;
	const float MAX_READY_ANGLE = 2.0;

	Balancer& balancer;
};

#endif /* SBRSTANDBY_H_ */
