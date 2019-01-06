/*
 * SbrReady.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef SBRREADY_H_
#define SBRREADY_H_

#include "SbrState.h"

class Balancer;

class SbrReady: public SbrState {
public:
	SbrReady(Balancer& balancer);
	virtual ~SbrReady();

	virtual String getName();
	virtual void onInit();
	virtual State onAngle(float angle);

private:
	const float MIN_VALID_ANGLE = -45;
	const float MAX_VALID_ANGLE = 45;

	Balancer& balancer;
};

#endif /* SBRREADY_H_ */
