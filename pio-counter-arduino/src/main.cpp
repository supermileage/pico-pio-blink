#include <Arduino.h>

#include "encoder.pio.h"          // 'Compiled' PIO assembly file

// Base pin to connect the A phase of the encoder.
// The B phase must be connected to the next pin
#define PIN_AB              10
#define PIO_STATE_MACHINE   0

int delta = 0;
int old_value = 0;
PIO pio = pio0; 

void setup() {
    Serial.begin(115200);

    pinMode(PIN_AB, INPUT);
    pinMode(PIN_AB + 1, INPUT);    

    Serial.begin(115200);                  

                                            // Use pio 0
    uint offset = pio_add_program(pio, &encoder_program);     // Get the offset of the assembly program
    encoder_program_init(pio, PIO_STATE_MACHINE, offset, PIN_AB, 0);      // Initialize the assembly program

}

void loop() {
    // note: thanks to two's complement arithmetic delta will always
    // be correct even when new_value wraps around MAXINT / MININT
    int new_value = encoder_get_count(pio, PIO_STATE_MACHINE);
    delta = (new_value - old_value) / 4;
    old_value = new_value;

    Serial.println("Speed: " + String(delta) + "Hz");
    delay(1000);
}

