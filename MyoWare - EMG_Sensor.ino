//Default library for servo motor.
#include <Servo.h>

//Threshold for servo motor control with muscle sensor.
#define THRESHOLD 250 

//Analog pin 0 is assign to EMG sensor.
#define EMG_PIN 0

//PWM pins are assign to servo motor.
#define SERVO_IT 3
#define SERVO_M 6
#define SERVO_RP 9

//Defined servo motor.
Servo SERVO_1;
Servo SERVO_2;
Servo SERVO_3;

void setup() {
    //Baud Rate set to 115200.
    Serial.begin(115200);

    SERVO_1.attach(SERVO_IT); //Set servo motor to digital pin 3
    SERVO_2.attach(SERVO_M); //Set servo motor to digital pin 6
    SERVO_3.attach(SERVO_RP); //Set servo motor to digital pin 9
    
}


void loop(){
  //The "value" variable reads the value taken from the analog pin to which sensor is connected.
  int value = analogRead(EMG_PIN);

  //If the sensor value is greater than the THRESHOLD, the servo will rotate to X number of degree.
  if(value > THRESHOLD){

    SERVO_1.write(170); //Index and Thumb Finger
    SERVO_2.write(170); //Middle Finger
    SERVO_3.write(170);//Ring and Pinky Finger
    
   }
   
   //If the sensor value is less than the THRESHOLD, the servo will rotate to X number of degree.
   else{

      SERVO_1.write(10); //Index and Thumb Finger
      SERVO_2.write(10);//Middle Finger
      SERVO_3.write(10);//Ring and Pinky Finger
      
    }
    //can use serial monitor to set THRESHOLD value.
    Serial.println(value);
}
