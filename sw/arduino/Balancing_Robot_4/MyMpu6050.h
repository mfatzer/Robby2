/*
 * Mpu6050.h
 *
 *  Created on: 01.01.2019
 *      Author: Martin
 */

#ifndef MYMPU6050_H_
#define MYMPU6050_H_

#include "Arduino.h"

namespace MyMpu6050 {


class MyMpu6050 {
public:
	MyMpu6050(int interruptPin);
	virtual ~MyMpu6050();

	void setup();
	void tick();

	double getYaw();
	double getPitch();
	double getRoll();

private:
	int interruptPin;
	bool dmpReady;  // set true if DMP init was successful
	uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
	uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
	uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
	uint16_t fifoCount;     // count of all bytes currently in FIFO
	uint8_t fifoBuffer[64]; // FIFO storage buffer

	float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
};

} /* namespace Mpu6050 */

#endif /* MYMPU6050_H_ */
