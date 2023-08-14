# ESP32-LED-cube

#### This is an open source 4x4x4 LED cube project

(code &amp; PCB provided)

![project gif](LED_cube.gif)

### Hardware

I used ESP32 devkit v1 as the main MCU to control three 74HC595 8-bit shift register. Two of the registers control the layer pattern (4x4), the remaining one swipe through the vertical 4 layers.

The animation affect is done by 'Persistence of vision', a frame you see is actually LEDs turning on/off rapidly layer by layer.

For series resistors I use 160 Ohms to get the brightness and yet not burning the LED.

### Software

The code is in /code/LEDcube_esp32.ino
It's not pretty but gets the job done.

Here is the [website](https://www.instructables.com/Led-Cube-8x8x8/) that I reffered to.
