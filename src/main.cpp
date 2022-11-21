#include <stdio.h>              // STD IO Library

#include <pico/stdlib.h>        // Pico's Standard library
#include <hardware/pio.h>       // Pico's Hardware Library
#include <hardware/clocks.h>    // Pico's Clocks Library
#include "blink.pio.h"          // 'Compiled' PIO assembly file

#define PIN_LED     25          // Pico's built-in LED
#define SLEEP_TIME  10          
#define PIO_FREQ    2000

int main() {
    stdio_init_all();                   // Required to enable serial upload / serial monitor              

    gpio_init(PIN_LED);                 // Sets pinmode as GPIO
    gpio_set_dir(PIN_LED, GPIO_OUT);    // Sets pin direction as OUT

    int i = 0;

    PIO pio = pio0;                                         // Use pio 0
    uint sm = pio_claim_unused_sm(pio, true);               // Use first unused state machine
    uint offset = pio_add_program(pio, &blink_program);     // Get the offset of the assembly program
    float div = (float)clock_get_hz(clk_sys) / PIO_FREQ;    // Calculate the frequency of the LED blink
    blink_program_init(pio, sm, offset, PIN_LED, div);      // Initialize the assembly program
    pio_sm_set_enabled(pio, sm, true);                      // Enable the state machine

    // LOOP
    // This loops proves that the processor spends no instruction time blinking the LED, all done by PIO
    while(1)
    {
        sleep_ms(SLEEP_TIME);

        i++;
        printf("Busy counting away i = %d\n", i);
    }
}

