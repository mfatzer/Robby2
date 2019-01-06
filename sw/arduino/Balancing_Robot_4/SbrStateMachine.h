/*
 * SbrStateMachine.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef SBRSTATEMACHINE_H_
#define SBRSTATEMACHINE_H_

#include "SbrState.h"
#include "SbrStandby.h"
#include "SbrReady.h"
#include "SbrEvents.h"

class Balancer;

class SbrStateMachine : public SbrEvents {
public:
	SbrStateMachine(Balancer& balancer);
	virtual ~SbrStateMachine();

	virtual void onAngle(float angle);

	virtual boolean isReady();

private:
	virtual void setState(State newState);
	virtual void setState(SbrState* newState);

private:
	SbrStandby standbyState;
	SbrReady readyState;
	SbrState* currentState;
};

#endif /* SBRSTATEMACHINE_H_ */
