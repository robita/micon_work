#include <Servo.h>

Servo myservo;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
int state =  0;

void setup() {
  myservo.attach(9);
}

void loop() {
//  val = analogRead(potpin);
//  val = map(100, 0, 1023, 0, 179);

if (state == 1){
  val = 180;
  state = 0;
}else{
  val=0;
  state = 1;
}
  myservo.write(val);
  delay(1000);
}
