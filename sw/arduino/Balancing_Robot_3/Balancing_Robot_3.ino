#include "Arduino.h"
#include "BoardSetup.h"
#include "MyMpu6050.h"
#include "Balancer.h"


const float ZERO_ANGLE_OFFSET = -2;

MyMpu6050::MyMpu6050 mpu(MPU_INTERRUPT_PIN);
Balancer balancer(.7, 1.2, .3, ZERO_ANGLE_OFFSET);



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
	Serial.begin(115200);
	Serial.println("setup() -> Start");

	mpu.setup();

	balancer.setup();
	balancer.enableMotors(true);

	Serial.println("setup() -> End");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	mpu.tick();
	const double currentAngle = mpu.getPitch();

//	Serial.print("Pitch: ");
//	Serial.println(currentAngle + ZERO_ANGLE_OFFSET);
	balancer.tick(currentAngle);

	int p = analogRead(2);
	int i = analogRead(1);
	int d = analogRead(0);

	Serial.print("P: ");
	Serial.println(p);
	Serial.print("I: ");
	Serial.println(i);
	Serial.print("D: ");
	Serial.println(d);
}
