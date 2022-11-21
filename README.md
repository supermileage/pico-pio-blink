# pico-pio-blink
A sample program for the Raspberry Pi Pico that blinks an LED using programmable I/O. 

## Getting Started
If you don't already have PlatformIO, get it by downloading [Visual Studio Code](https://code.visualstudio.com/) and the [PlatformIO extension](https://platformio.org/). Then, [install the Wiz-IO Pico platform](https://platformio.org/) on PlatformIO. 

Open up the platformio.ini file in the root directory, and modify the *board* and *monitor_port* to match the board you're using, and the port that it is connected to on your computer. 

Press the PlatformIO Upload button, and you should see the on-board LED start blinking rapidly. 

## What's happening behind the scenes?
The [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/) is a very powerful microcontroller that features a dual-core processor, and a ["PIO" (programmable Input/Output) logic block](https://hackspace.raspberrypi.com/articles/what-is-programmable-i-o-on-raspberry-pi-pico) that can run very simple instructions independently of the processor. In this demo, the PIO is set up to blink the LED independently, freeing up the processor to run other tasks. While blinking an LED is a simple low-speed IO task, PIO can be used to run simple high-speed IO tasks such as adressable LEDs, logic analysis, or creating an additional i2c, SPI or UART interface. 
