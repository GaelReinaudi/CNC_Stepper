/*
Adafruit Arduino - Lesson 16. Stepper
*/

#include <Stepper.h>

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

Stepper motor(200, in1Pin, in2Pin, in3Pin, in4Pin);  
int speedMotor = 1;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  
  Serial.begin(9600);
}

void loop()
{
  motor.setSpeed(speedMotor);
  speedMotor += 1;
  if (Serial.available())
  {
    int steps = Serial.parseInt();
    motor.step(steps);
  }
  else
  {
    motor.step(10 * speedMotor);
    //sleep(1000);
  }
}
