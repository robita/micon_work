
#include <Servo.h>

Servo myservo;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
int state =  0;

const int buttonPin = 2;
const int ledPin = 13;
const int serboPin = 9;
int buttonState = LOW;

void setup() {
  Serial.begin(9600);
  myservo.attach(serboPin);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  Serial.println(buttonState);
  
  if (buttonState == HIGH) {
//    Serial.println("step1");
    digitalWrite(ledPin, HIGH);
    val = 90;
    delay(500);
  }
  else {
//    Serial.println("step2");
    val = 0;
  }
  myservo.write(val);
//  delay(100);
}
