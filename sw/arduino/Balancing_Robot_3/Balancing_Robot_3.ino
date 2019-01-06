#include "Arduino.h"
#include "BoardSetup.h"
#include "MyMpu6050.h"
#include "Balancer.h"


const float ZERO_ANGLE_OFFSET = -2;

MyMpu6050::MyMpu6050 mpu(MPU_INTERRUPT_PIN);
Balancer balancer(ZERO_ANGLE_OFFSET);

float oldP = 0.0;
float oldI = 0.0;
float oldD = 0.0;


void setupRobbyPinModes() {
	pinMode(MOTOR_ENABLE_PIN, OUTPUT);
	pinMode(MOTOR_LEFT_STEP, OUTPUT);
	pinMode(MOTOR_LEFT_DIR, OUTPUT);
	pinMode(MOTOR_RIGHT_STEP, OUTPUT);
	pinMode(MOTOR_RIGHT_DIR, OUTPUT);
    pinMode(MPU_INTERRUPT_PIN, INPUT);
}

float calculateFactor(int value) {
	return value * 10 / 1023.0;
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
	oldP = calculateFactor(analogRead(INPUT_P));
	oldI = calculateFactor(analogRead(INPUT_I));
	oldD = calculateFactor(analogRead(INPUT_D));
	balancer.setKP(oldP);
	balancer.setKI(oldI);
	balancer.setKD(oldD);
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
//	Serial.println(currentAngle);
	balancer.tick(currentAngle);

	float p = calculateFactor(analogRead(INPUT_P));
	float i = calculateFactor(analogRead(INPUT_I));
	float d = calculateFactor(analogRead(INPUT_D));


	if (abs(oldP - p) >= .1) {
		balancer.setKP(p);
		oldP = p;
	}
	if (abs(oldI - i) >= .1) {
		balancer.setKI(i);
		oldI = i;
	}
	if (abs(oldD - d) >= .1) {
		balancer.setKD(d);
		oldD = d;
	}

	Serial.print("P: ");
	Serial.println(oldP);
//	Serial.print("I: ");
//	Serial.println(i);
//	Serial.print("D: ");
//	Serial.println(d);
//	delay(10);
}
