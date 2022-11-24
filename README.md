# pico-samples
Sample programs for the Raspberry Pi Pico and its Programmable IO block (PIO).

## Background
The [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/) is a very powerful microcontroller that features a dual-core processor, and a ["PIO" (programmable Input/Output) logic block](https://hackspace.raspberrypi.com/articles/what-is-programmable-i-o-on-raspberry-pi-pico) that can run very simple instructions independently of the processor. PIO can be used to run simple high-speed IO tasks such as adressable LEDs, logic analysis, or creating an additional i2c, SPI or UART interfaces. 

## Getting Started
If you don't already have PlatformIO, get it by downloading [Visual Studio Code](https://code.visualstudio.com/) and the [PlatformIO extension](https://platformio.org/). You will need to install the [Wiz-IO Pico platform](https://platformio.org/) on PlatformIO if you'd like to run any of the Pico SDK sketches.

To compile and upload any of the sample projects, open its respective directory in Visual Studio Code (the directory where the platformio.ini file is located). If PlatformIO does not see the platformio.ini file in the root of the directory you have opened, it will not allow you to compile and upload the code. 
 
Press the PlatformIO *Upload* button to upload the sketch to the Pico.

## Pico SDK vs Arduino
There are two ways to write code for the Pico: Using the Pico Software Developer Kit (SDK), or using the Arduino library. If you choose either, you will write your code in C++, but the code that you write will look different. The Pico SDK has its own libraries and methods for accessing hardware on the Pico, the documentation for which can be found here [here](https://raspberrypi.github.io/pico-sdk-doxygen/modules.html). This repo contains samples for both. 

### Why use the Pico SDK?
The Pico SDK is supported on PlatformIO using the Wiz-IO Pico platform. It allows you to "compile" PIO assembly files by including them in the *board_build.pio* field in the *platformio.ini* file. It also allows you to access a ton of complex functionality in the SDK that may not otherwise be available. While this platform does allow you to compile using the Arduino framework, serial upload and the serial monitor is currently broken so this is not an ideal solution.

### Why use the Arduino library?
Arduino is simple and transferrable between different platforms. It helps you spin up a project quickly and also allows you to port a project from another platform really easily. The built-in Pico "platform" on PlatformIO uses Arduino by default, and is relatively bug-free. The one downside is that compiling PIO assembly files is not yet supported. There are two workarounds for this: Compile them in another project using the Pico SDK, or use a [web compiler](https://wokwi.com/tools/pioasm). Once the PIO assembly is compiled into a *.h* file, you can include it in your project easily.  

## Sample Projects

### Blink
Available in both Pico SDK and Arduino flavours. 

Uses PIO to blink an LED rapidly while outputting a simple counter to the serial monitor.

### Counter
Available in both Pico SDK and Arduino flavours. 

Reads the output of a quadrature encoder using PIO. Connect A to pin 10 and B to pin 11. Outputs frequency to serial monitor, but position can also be calculated. 