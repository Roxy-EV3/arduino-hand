#include <MovingAverage.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

MovingAverage<unsigned>fma0(10, 90);

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int AP0;

int fr0, fr1, fr2, fr3, fr4; 

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  550 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();550
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  yield();
}

void loop() 
{
  AP0 = analogRead(A0);
  fma0.push(AP0);
  Serial.print(AP0);
  Serial.print(",");
  Serial.print(fma0.get());
  fr0 = map(fma0.get(), 80, 500, SERVOMIN, SERVOMAX);
  if (fr0 < SERVOMIN ) {fr0 = SERVOMIN ;}
  if (fr1 > SERVOMAX ) {fr0 = SERVOMAX ;}
  Serial.print(",");
  Serial.println(fr0);
  pwm.setPWM(0, 0, fr0);
   
  delay(50);
}
