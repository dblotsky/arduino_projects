#define GREEN 11
#define RED 10
#define ORANGE 9
#define YELLOW 6
#define DELAY_FAST 3
#define DELAY_SLOW 15
#define BRIGHTNESS 200
#define STEP 2

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  pinMode(3, INPUT);
}

void loop() {
  attachInterrupt(0, isr_flashLED, RISING);
  int i = 0;
  int j = 0;
  int colors[4] = {GREEN, RED, ORANGE, YELLOW};
  
  for(j = 0; j < 4; j++) {
    for(i = 0; i < BRIGHTNESS; i += STEP) {
      analogWrite(colors[j], i);
      delay(DELAY_FAST);
    }
    for(i = BRIGHTNESS; i > 0; i -= STEP) {
      analogWrite(colors[j], i);
      delay(DELAY_SLOW);
    }
    digitalWrite(colors[j], LOW);
  }
}

void isr_flashLED(){
    int i = 0;
    
    for (i = 0; i < 4; i++){
      int j = 0;
      int colors[4] = {GREEN, RED, ORANGE, YELLOW};
     for(j = 0; j < 4; j++) {
        analogWrite(colors[j], BRIGHTNESS);
      }
      delay(DELAY_FAST);
      for(j = 0; j < 4; j++) {
        analogWrite(colors[j], 0);
      }
      delay(DELAY_FAST);
    }
}
