#include <Bounce2.h>
#include <MsTimer2.h>

#define BUTTON_PIN 2
#define LED_PIN 4
#define ALERT_PIN 12

const int set_min=15;  // min
const double minute=60000; // 1 min = 60 * 1000 ms
double delta = 0;

unsigned long time_s = 0;
unsigned long time_e = 0;
unsigned long time_delta = 0;

int work = 0;

// Instantiate a Bounce object
Bounce debouncer = Bounce(); 

void setup() {
  Serial.begin(19200);

  // pins
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ALERT_PIN, OUTPUT);

  // After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5); // interval in ms

  delta = set_min * minute / 2;
  MsTimer2::set(delta, flash); // delta(ms) period
}

void flash()
{
  work=2;
  digitalWrite(LED_PIN, LOW);
  digitalWrite(ALERT_PIN, HIGH);
}

void loop() {
  // Update the Bounce instance :
  debouncer.update();

  digitalWrite(LED_BUILTIN, HIGH);

  // Get the updated value :
  int value = debouncer.read();

  // Turn on or off the LED as determined by the state :
  if ( value == LOW ) {
    if(work == 0) {
      work = 1;

      MsTimer2::start();
      Serial.println(delta);
      
      time_s = millis();
      time_e = 0;
      time_delta = 0;
    } else if (work == 1) {
      digitalWrite(LED_PIN, HIGH);
    } else if (work == 2) { // work = 2
      Serial.println("alert");
      
      time_e = millis();
      time_delta = (time_e - time_s) / 1000;
      Serial.print("elapsed time s =");
      Serial.println(time_delta);
    }
  } 
  else {
    work = 0;
    digitalWrite(LED_PIN, LOW);
    digitalWrite(ALERT_PIN, LOW);       //スイッチが押されていないならLEDを消灯
    MsTimer2::stop();
  }
  Serial.println(work);
}
