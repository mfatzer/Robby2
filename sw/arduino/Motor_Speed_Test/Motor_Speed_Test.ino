#include "Arduino.h"

#include "BoardSetup.h"
#include "Motor.h"


Motor motor1(MOTOR_LEFT_DIR, MOTOR_LEFT_STEP, false);
Motor motor2(MOTOR_RIGHT_DIR, MOTOR_RIGHT_STEP, true);

void setupRobbyPinModes() {
	pinMode(MOTOR_ENABLE_PIN, OUTPUT);
	pinMode(MOTOR_LEFT_STEP, OUTPUT);
	pinMode(MOTOR_LEFT_DIR, OUTPUT);
	pinMode(MOTOR_RIGHT_STEP, OUTPUT);
	pinMode(MOTOR_RIGHT_DIR, OUTPUT);
    pinMode(MPU_INTERRUPT_PIN, INPUT);
}

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	setupRobbyPinModes();
	motor1.setup();
	motor1.setDirection(FORWARD);
	motor2.setup();
	motor2.setDirection(FORWARD);
	digitalWrite(MOTOR_ENABLE_PIN, LOW);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	motor1.step();
	motor2.step();
	// Minimum delay mit 16* Microstepping
	delayMicroseconds(60);
}
