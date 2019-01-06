#include "Arduino.h"
#include "BoardSetup.h"
#include "MyMpu6050.h"
#include "Balancer.h"
#include "SbrStateMachine.h"

// Nagativ: Forward
// Positiv: Back
const float ZERO_ANGLE_OFFSET = -1;

const float MIN_P_VAL = 2.0;
const float MIN_I_VAL = 0;
const float MIN_D_VAL = 0;
const float MAX_P_VAL = 5.0;
const float MAX_I_VAL = 5.0;
const float MAX_D_VAL = .6;

const float MIN_K_CHANGE = .05;


MyMpu6050::MyMpu6050 mpu(MPU_INTERRUPT_PIN);
Balancer balancer(ZERO_ANGLE_OFFSET);
SbrStateMachine sbrStateMachine(balancer);


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

float calculateFactor(int value, float minValue, float maxValue) {
	return minValue + value * (maxValue - minValue) / 1023.0;
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
	oldP = calculateFactor(analogRead(INPUT_P), MIN_P_VAL, MAX_P_VAL);
	oldI = calculateFactor(analogRead(INPUT_I), MIN_I_VAL, MAX_I_VAL);
	oldD = calculateFactor(analogRead(INPUT_D), MIN_D_VAL, MAX_D_VAL);
	balancer.setKP(oldP);
	balancer.setKI(oldI);
	balancer.setKD(oldD);

	delay(4000);

	Serial.println("setup() -> End");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	mpu.tick();
	const float currentAngle = mpu.getPitch();

//	Serial.print("Pitch: ");
//	Serial.println(currentAngle);
	sbrStateMachine.onAngle(currentAngle);

	float p = calculateFactor(analogRead(INPUT_P), MIN_P_VAL, MAX_P_VAL);
	float i = calculateFactor(analogRead(INPUT_I), MIN_I_VAL, MAX_I_VAL);
	float d = calculateFactor(analogRead(INPUT_D), MIN_D_VAL, MAX_D_VAL);


	if (abs(oldP - p) >= MIN_K_CHANGE) {
		balancer.setKP(p);
		oldP = p;
	}
	if (abs(oldI - i) >= MIN_K_CHANGE) {
		balancer.setKI(i);
		oldI = i;
	}
	if (abs(oldD - d) >= MIN_K_CHANGE) {
		balancer.setKD(d);
		oldD = d;
	}

	Serial.print("P: ");
	Serial.println(oldP);
	Serial.print("I: ");
	Serial.println(oldI);
	Serial.print("D: ");
	Serial.println(oldD);
//	delay(10);
}
