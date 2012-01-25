#include "notes.h"
#include "pins.h"

// pins
#define TONE_PIN PWM_0

// notes in milliseconds
#define NW 800      // whole note
#define NH (NW / 2) // half-note
#define NQ (NW / 4) // quarter-note

volatile static boolean silent = true;

void setup() {
    pinMode(TONE_PIN, OUTPUT);
}

void music_on() {
    silent = false;
    return;
}

void music_off() {
    silent = true;
    return;
}

void loop() {
    attachInterrupt(INTR_0, music_on, RISING);
    attachInterrupt(INTR_1, music_off, FALLING);
    
    // good king wenceslas
    int const tune_size = 53;
    int const durations[tune_size] = {
        NQ,  NQ,  NQ,        NQ,        /**/ NQ,        NQ,  NH,  /**/ NQ,  NQ,  NQ,        NQ,        /**/ NH,  NH,
        NQ,  NQ,  NQ,        NQ,        /**/ NQ,        NQ,  NH,  /**/ NQ,  NQ,  NQ,        NQ,        /**/ NH,  NH,
        NQ,  NQ,  NQ,        NQ,        /**/ NQ,        NQ,  NH,  /**/ NQ,  NQ,  NQ,        NQ,        /**/ NH,  NH,
        NQ,  NQ,  NQ,        NQ,        /**/ NQ,        NQ,  NH,  /**/ NQ,  NQ,  NQ,        NQ,        /**/ NH,  NH,  /**/ NW
    }; 
    int const notes[tune_size] = {
        D_4, D_4, D_4,       E_4,       /**/ D_4,       D_4, A_3, /**/ B_3, A_3, B_3,       C_4_SHARP, /**/ D_4, D_4, 
        D_4, D_4, D_4,       E_4,       /**/ D_4,       D_4, A_3, /**/ B_3, A_3, B_3,       C_4_SHARP, /**/ D_4, D_4, 
        A_4, G_4, F_4_SHARP, E_4,       /**/ F_4_SHARP, E_4, D_4, /**/ B_3, A_3, B_3,       C_4_SHARP, /**/ D_4, D_4, 
        A_3, A_3, B_3,       C_4_SHARP, /**/ D_4,       D_4, E_4, /**/ A_4, G_4, F_4_SHARP, E_4,       /**/ D_4, G_4, /**/ D_4
    };
    
    // loop the notes
    int i = 0;
    while(true) {
        for(i = 0; i < tune_size; i++) {
            
            if (!silent) {
                tone(TONE_PIN, notes[i], durations[i]);
            }
            
            delay(durations[i]);
            noTone(TONE_PIN);
        }
    }
}
