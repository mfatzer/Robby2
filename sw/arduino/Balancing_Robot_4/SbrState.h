/*
 * SbrState.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef SBRSTATE_H_
#define SBRSTATE_H_

#include "Arduino.h"
#include "SbrEvents.h"

enum State { STANDBY, READY };

class SbrState {
public:
	SbrState() {};
	virtual ~SbrState() {};

	virtual String getName() = 0;
	virtual void onInit() = 0;
	virtual State onAngle(float angle) = 0;

};

#endif /* SBRSTATE_H_ */
