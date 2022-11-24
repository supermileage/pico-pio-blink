#include <stdio.h>              // STD IO Library

#include <pico/stdlib.h>        // Pico's Standard library
#include <hardware/pio.h>       // Pico's Hardware Library
#include <hardware/clocks.h>    // Pico's Clocks Library

#include "encoder.pio.h"          // 'Compiled' PIO assembly file

// Base pin to connect the A phase of the encoder.
// The B phase must be connected to the next pin
#define PIN_AB              10
#define PIO_STATE_MACHINE   0

int main() {
    int new_value, delta, old_value = 0;

    stdio_init_all();                   // Required to enable serial upload / serial monitor              

    int i = 0;

    PIO pio = pio0;                                         // Use pio 0
    uint offset = pio_add_program(pio, &encoder_program);     // Get the offset of the assembly program
    encoder_program_init(pio, PIO_STATE_MACHINE, offset, PIN_AB, 0);      // Initialize the assembly program

    // LOOP
    while(1)
    {
        // note: thanks to two's complement arithmetic delta will always
        // be correct even when new_value wraps around MAXINT / MININT
        new_value = encoder_get_count(pio, PIO_STATE_MACHINE);
        delta = (new_value - old_value) / 4;
        old_value = new_value;

        printf("Speed: %dHz\n", delta);
        sleep_ms(1000);
    }
}

