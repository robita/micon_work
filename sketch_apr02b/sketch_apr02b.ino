//ボタンを押すとLEDがON/OFFするスケッチ３
#include <Bounce2.h>

const int buttonON = LOW;
const int buttonOFF = HIGH;

const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int previusState = buttonOFF;
unsigned long cntMillis = 0;

int ledState = 0;
int previusLedState = 0;

Bounce pushbutton = Bounce(buttonPin, 10); // 10 ms debounce

void setup() {
  Serial.begin(19200);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      if (ledState == 0) { //LEDのステータスが消灯なら点灯、点灯なら消灯する
        ledState = 1;
      } else {
        ledState = 0;
      }
      cntMillis = millis(); // ボタンonの時間を記憶
    }
  } else {
    if (ledState != previusLedState) {
      unsigned long nowMillis = millis();
      if (nowMillis - cntMillis > 100) { // ボタンonからしばらくまった後に実行
        if (ledState == 0) {
          digitalWrite(ledPin, LOW);
        } else {
          digitalWrite(ledPin, HIGH);
        }
      previusLedState = ledState;
      }
    }
  }
  Serial.println(ledState);
}
