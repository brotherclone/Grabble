
#include <Servo.h> 
 
Servo Wrist;
Servo Pinch;
Servo Forearm;
Servo Arm;
int sensorThreshold   =  100;   
const int MuscleSensorPinA  = A0;
const int MuscleSensorPinB =A1;
int curArmPos[] = {80,80,80,80};
int servospeed = 12;
int accspeed =10;
int firsttime = 0;
String armstate = "none";

void setup() { 
  Serial.begin(9600);
  Wrist.attach(6);
  Pinch.attach(5);
  Forearm.attach(3);
  Arm.attach(4);
  pinMode(MuscleSensorPinA, INPUT);
  pinMode(MuscleSensorPinB, INPUT);
  if(firsttime==0){
    positionGrable(100,100,100,100);
    firsttime=1;
  }
} 
 
void loop(){
  readMuscles(analogRead(MuscleSensorPinA), analogRead(MuscleSensorPinB));
}

void positionGrable(int W,int P,int F,int A){
  if(curArmPos[0]>W){
    for(int iW = curArmPos[0]; iW<W; iW++){
       Wrist.write(iW);
       delay(servospeed);
       curArmPos[0] = iW;
    } 
  }else{
    for(int iW = curArmPos[0]; iW>W; iW--){
      Wrist.write(iW);
      delay(servospeed);
      curArmPos[0] = iW;
    }
  }
  
  if(curArmPos[1]>P){
    for(int iP = curArmPos[1]; iP<P; iP++){
       Pinch.write(iP);
       delay(servospeed);
       curArmPos[1] = iP;
    } 
  }else{
    for(int iP = curArmPos[1]; iP>P; iP--){
       Pinch.write(iP);
       delay(servospeed);
       curArmPos[1] = iP;
    }
  }
  
   if(curArmPos[2]>F){
    for(int iFd = curArmPos[2]; iFd<F; iFd++){
       Forearm.write(iFd);
       delay(accspeed);
       curArmPos[2] = iFd;
    } 
  }else{
    for(int iFd = curArmPos[2]; iFd>P; iFd--){
       Forearm.write(iFd);
       delay(accspeed);
       curArmPos[2] = iFd;
    }
  }
 
 if(curArmPos[3]>A){
    for(int iA = curArmPos[3]; iA<A; iA++){
        Arm.write(iA);
       delay(accspeed);
       curArmPos[3] = iA;
    } 
  }else{
    for(int iA = curArmPos[3]; iA>A; iA--){
       Arm.write(iA);
       delay(accspeed);
       curArmPos[3] = iA;
    }
  }

   
}
  
void readMuscles(int chA, int chB){
  if((chA>=sensorThreshold)&&(chA>=sensorThreshold)){
    if(armstate==String("none")){
      positionGrable(80,220,225,225);
      armstate = "extended";
    }else if(armstate==String("extendedpinched")){
      positionGrable(80,220,0,0);
      armstate = "pinched";
    }
  }else if((chA>=sensorThreshold)&&(chA<sensorThreshold)){
     if(armstate==String("extended")){
       positionGrable(80,80,0,0);
       armstate = "none";
    }
  }else if((chA<sensorThreshold)&&(chA>=sensorThreshold)){
    
    if(armstate==String("none")){
      positionGrable(80,220,0,0);
      armstate = "pinched";

    }else if(armstate==String("pinched")){
       positionGrable(80,80,0,0);
       armstate = "none";
      
    }
    
  }

}

