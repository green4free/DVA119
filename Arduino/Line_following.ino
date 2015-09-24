#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

int sen[3] = {0,0,0};
mySensors Sensors; // create Sensors object
myMotors Motors;  // create Motors object
volatile int state = LOW;

void setup() 
{  
  Motors.beginMotors();   // start motors
  Sensors.beginSensors(); // start sensors
}

void loop() 
{
  
  sen[0] = Sensors.readReflect0(); sen[1] = Sensors.readReflect1(); sen[2] = Sensors.readReflect2(); // Read digital value of reflect sensor 0

  if (sen[0] == 0 && sen[1] == 1 && sen[2] == 0)
  {
      Motors.runMotor(1, FORWARD, 80); // Run motor 1 & 2 forward at 0 velocity(Stop)
      Motors.runMotor(2, FORWARD, 80);
  }else if(sen[0] == 1 && sen[1] == 0 && sen[2] == 0)
  {
      Motors.runMotor(1, FORWARD, 100); // Run motor 1 & 2 forward at 0 velocity(Stop)
      Motors.runMotor(2, BACKWARD, 60);
  }else if(sen[0] == 0 && sen[1] == 0 && sen[2] == 1)
  {
      Motors.runMotor(2, FORWARD, 100); // Run motor 1 & 2 forward at 0 velocity(Stop)
      Motors.runMotor(1, BACKWARD, 60);
  }else if(sen[0] == 0 && sen[1] == 1 && sen[2] == 1)
  {
      Motors.runMotor(2, FORWARD, 80); // Run motor 1 & 2 forward at 0 velocity(Stop)
      Motors.runMotor(1, FORWARD, 65);
  }else if(sen[0] == 1 && sen[1] == 1 && sen[2] == 0)
  {
      Motors.runMotor(1, FORWARD, 80); // Run motor 1 & 2 forward at 0 velocity(Stop)
      Motors.runMotor(2, FORWARD, 65);
  }
  else
  {
      delay(100);
      if(sen[0] == 1 || sen[1] == 1 || sen[2] == 1){
          Motors.runMotor(1, FORWARD, 0); // Run motor 1 & 2 forward at 100 velocity
          Motors.runMotor(2, FORWARD, 0);
      }else{
          Motors.runMotor(1, BACKWARD, 50); // Run motor 1 & 2 forward at 100 velocity
          Motors.runMotor(2, BACKWARD, 50);
      }
    }
}

