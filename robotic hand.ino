#include <MovingAverage.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int mvasize =1;
MovingAverage<unsigned>fma0(mvasize , 90);
MovingAverage<unsigned>fma1(mvasize , 90);
MovingAverage<unsigned>fma2(mvasize , 90);
MovingAverage<unsigned>fma3(mvasize , 90);
MovingAverage<unsigned>fma4(mvasize , 90);

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int AP0;
int AP1;
int AP2;
int AP3;
int AP4;

int fr0, fr1, fr2, fr3, fr4; 

#define SERVOMIN  150
#define SERVOMAX  550



void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  //yield();
}

void loop() 
{
  //---------------------------------
  Serial.print("[0]");
  AP0 = analogRead(A0);
  fma0.push(AP0);
  Serial.print(AP0);Serial.print(",");
  Serial.print(fma0.get());Serial.print(",");
  fr0 = map(fma0.get(), 80, 500, SERVOMIN, SERVOMAX);
  fr0 = constrain(fr0 ,SERVOMIN,SERVOMAX);
  Serial.print(fr0);Serial.print("-");
  pwm.setPWM(0, 0, fr0);

  //---------------------------------
    Serial.print("[1]");
  AP1 = analogRead(A1);
  fma1.push(AP1);
  Serial.print(AP1);Serial.print(",");
  Serial.print(fma1.get());Serial.print(",");
  fr1 = map(fma1.get(), 80, 500, SERVOMIN, SERVOMAX);
  fr1 = constrain(fr1 ,SERVOMIN,SERVOMAX);
  Serial.print(fr1);Serial.print("-");
  pwm.setPWM(1, 0, fr1);
  //---------------------------------
  Serial.print("[2]");
  AP2 = analogRead(A2);
  fma2.push(AP2);
  Serial.print(AP2);Serial.print(",");
  Serial.print(fma2.get());Serial.print(",");
  fr2 = map(fma2.get(), 80, 300, SERVOMIN, SERVOMAX);
  fr2 = constrain(fr2 ,SERVOMIN,SERVOMAX);
  Serial.print(fr2);Serial.print("-");
  pwm.setPWM(2, 0, fr2);
  //---------------------------------
  Serial.print("[3]");  
  AP3 = analogRead(A3) ;
  fma3.push(AP3);
  Serial.print(AP3);Serial.print(",");
  Serial.print(fma3.get());Serial.print(",");
  fr3 = map(fma3.get(), 80, 500, SERVOMIN, SERVOMAX);
  fr3 = constrain(fr3 ,SERVOMIN,SERVOMAX);
  Serial.print(fr3);Serial.print("-");
  pwm.setPWM(3, 0, fr3);
  //---------------------------------
  Serial.print("[4]");
  AP4 = analogRead(A4);
  fma4.push(AP4);
  Serial.print(AP4);Serial.print(",");
  Serial.print(fma4.get());Serial.print(",");
  fr4 = map(fma4.get(), 80, 500, SERVOMIN, SERVOMAX);
  fr4 = constrain(fr4 ,SERVOMIN,SERVOMAX);
  Serial.print(fr4);
  pwm.setPWM(4, 0, fr4);
  //---------------------------------

  Serial.println("");  
  delay(50);

}
