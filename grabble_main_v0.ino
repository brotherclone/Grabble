
#include <Servo.h> 
 
Servo Wrist;
Servo Pinch;
Servo Forearm;
Servo Arm;
int iThreshold   = 100;   
const int iMuscleSensorPin  = A0;      // pin connected to the muscle sensor

 
void setup() { 
  Serial.begin(9600);
  Wrist.attach(6);
  Pinch.attach(5);
  Forearm.attach(3);
  Arm.attach(4);
  pinMode(iMuscleSensorPin, INPUT);

} 
 
int testrun = true; 
void loop(){
 if(testrun){
    returntodefault();
    testrun = false;
  }
  int ch = analogRead(iMuscleSensorPin); 
  Serial.println(ch);
  delay(200);
}

 int returntodefault(){ 
      
       Wrist.write(100);
       Pinch.write(100);
       Forearm.write(100);
      Arm.write(100); 
       
  }
