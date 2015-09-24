#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

int R0Val = 0;
Servo Servo1;
mySensors Sensors; // create Sensors object
myMotors Motors;  // create Motors object

  void setup() 
  { 
    Servo1.attach(10);
    Motors.beginMotors();   // start motors
    Sensors.beginSensors(); // start sensors
  }

  void loop() 
  {
    Servo1.write(120);
    Motors.runMotor(1, FORWARD, 50);
    Motors.runMotor(2, FORWARD, 50);
    delay(1000);
    Motors.runMotor(1, FORWARD, 0);
    Motors.runMotor(2, FORWARD, 0);
    Plocka_Boll();
    Motors.runMotor(1, BACKWARD, 50);
    Motors.runMotor(2, BACKWARD, 50);
    delay(1000);
    Motors.runMotor(1, BACKWARD, 0);
    Motors.runMotor(2, BACKWARD, 0);
  }
  void Plocka_Boll ()
  {
    delay(1000);
    Servo1.write(0);
    delay(1000);
  }

