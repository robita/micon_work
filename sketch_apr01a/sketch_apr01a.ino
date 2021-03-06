#include <MsTimer2.h>

const int set_min=10;  // min
const double minute=60000; // 1 min = 60 * 1000 ms
const int timer_led_pin = LED_BUILTIN;
const int led_pin = 12;
const int switch_pin=2;
int work = 0;
const int default_interval = 1000;
int interval = default_interval;
double delta = 0;

unsigned long time_s = 0;
unsigned long time_e = 0;
unsigned long time_delta = 0;

void setup() {
    Serial.begin(19200);
    pinMode(switch_pin, INPUT);    //スイッチに接続ピンをデジタル入力に設定
    pinMode(led_pin, OUTPUT);
    pinMode(timer_led_pin, OUTPUT);

    delta = set_min * minute / 2;
    MsTimer2::set(delta, flash); // delta(ms) period
}

void flash()
{
  work=2;
  digitalWrite(timer_led_pin, HIGH) ;
  digitalWrite(led_pin, HIGH) ;      //スイッチが押されているならLEDを点灯
}

void loop() {
  interval = default_interval;
  if (digitalRead(2) == HIGH) {     //スイッチの状態を調べる
    if(work == 0) {
      MsTimer2::start();
      Serial.println(delta);
      work = 1;
      
      time_s = millis();
      time_e = 0;
      time_delta = 0;
    } else if (work == 1) {
      digitalWrite(timer_led_pin,HIGH);
      delay(200);
      interval -= 200;
      digitalWrite(timer_led_pin,LOW);
      delay(200);
      interval -= 200;
    } else { // work = 2
      Serial.println("alert");
      time_e = millis();
      time_delta = (time_e - time_s) / 1000;
      Serial.print("elapsed time s =");
      Serial.println(time_delta);
    }
  } else {
    work = 0;
    digitalWrite(timer_led_pin,LOW);
    digitalWrite(led_pin,LOW);       //スイッチが押されていないならLEDを消灯
    MsTimer2::stop();
  }
  Serial.println(work);
  delay(interval);
}
