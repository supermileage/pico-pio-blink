#include <Arduino.h>              // Arduino Library

#include "hardware/clocks.h"

#include "blink.pio.h"

#define PIN_LED     25          // Pico's built-in LED    
#define PIO_FREQ    2000

int i = 0;

void setup() {

    Serial.begin(115200);

    pinMode(PIN_LED, OUTPUT);                   // Required to enable serial upload / serial monitor              

    PIO pio = pio0;                                         // Use pio 0
    uint sm = pio_claim_unused_sm(pio, true);               // Use first unused state machine
    uint offset = pio_add_program(pio, &blink_program);     // Get the offset of the assembly program
    float div = (float)clock_get_hz(clk_sys) / PIO_FREQ;    // Calculate the frequency of the LED blink
    blink_program_init(pio, sm, offset, PIN_LED, div);      // Initialize the assembly program
    pio_sm_set_enabled(pio, sm, true);                      // Enable the state machine

}


// This loops proves that the processor spends no instruction time blinking the LED, all done by PIO
void loop() {
        i++;
        Serial.println("Busy counting away i = " + String(i));
        delay(10);
}
