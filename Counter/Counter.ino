int pin_offset = 6;
int num_pins = 8;
int resistor_pin = 0;

void setup() {
  // serial communication
  Serial.begin(9600);
  
  // display
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  // power
  pinMode(0, OUTPUT);
}

void loop() {
  unsigned char i = 0;
  
  // drive power to pin 0
  digitalWrite(0, HIGH);
  
  // constantly print the vaue of i
  while(1) {
    
    // read the sensor
    i = (analogRead(resistor_pin) / 4);
    Serial.print("\nsensor = ");                       
    Serial.print((int)i);
    
    print_scale_to_display(i);
    delay(50);
  }
}

void print_scale_to_display(unsigned char c) {
  int j = 0;
  for(j = num_pins - 1; j >= 0; j--) {
    write_bit_to_pin((c > 0), (j + pin_offset));
    if(c > 32) {
      c -= 32;
    } else {
      c = 0;
    }
  } 
  return;
}

void print_char_to_display(unsigned char c) {
  int j = 0;
  for(j = num_pins - 1; j >= 0; j--) {
    write_bit_to_pin(((c >> j) & 1), (j + pin_offset));
  } 
  return;
}

// write HIGH to pin if bit is 1, LOW if 0
void write_bit_to_pin(int written_bit, int pin) {
  if(written_bit) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
  return;
}
