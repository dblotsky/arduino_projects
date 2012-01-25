#include "speaker.h"

#define ONE_SECOND 100

static int delay_time = 1;
static int elapsed_milliseconds = 0;

void setup() {
  
  // serial communication
  Serial.begin(9600);
  
  // display
  pinMode(11, OUTPUT);
}

void loop() {
  
  if(delay_time >= 50) {
    delay_time = 1;
  }
  
  while(elapsed_milliseconds < ONE_SECOND) {
    digitalWrite(11, HIGH);
    delay(delay_time);
    
    digitalWrite(11, LOW);
    delay(delay_time);
    elapsed_milliseconds += 2*delay_time;
  }
  
  elapsed_milliseconds = 0;
  delay_time += 5;
}
