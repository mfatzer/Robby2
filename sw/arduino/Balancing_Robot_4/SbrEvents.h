/*
 * SbrEvents.h
 *
 *  Created on: 05.11.2017
 *      Author: Martin
 */

#ifndef SBREVENTS_H_
#define SBREVENTS_H_

class SbrEvents {
public:
	SbrEvents() {};
	virtual ~SbrEvents() {};

	virtual void onAngle(float angle) = 0;
};

#endif /* SBREVENTS_H_ */
