#include <MsTimer2.h>

const int set_min=1;  // min
const double minute=60000; // 1 min = 60 * 1000 ms
double delta = 0;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int work = 0;

void setup() {
  Serial.begin(19200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  delta = set_min * minute / 2;
  MsTimer2::set(delta, flash); // delta(ms) period
}

void flash()
{
  work=2;
  //digitalWrite(timer_led_pin, HIGH);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    if(work == 0) {
      MsTimer2::start();
      Serial.println(delta);
      work = 1;
//      delay(200);
    } else if (work == 1) {
      digitalWrite(ledPin, HIGH);
//      delay(200);
//      digitalWrite(ledPin, LOW);
//      delay(200);
    } else { // work = 2
      Serial.println("alert");
//      delay(200);
    }
  } else {
    // turn LED off:
//    digitalWrite(ledPin, LOW);
    work = 0;
    digitalWrite(ledPin,LOW);
    MsTimer2::stop();
  }
//  delay(400);
}
