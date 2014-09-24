geiger_lcdnleds
===============

Code for the cooking-hacks.com's radiation detection board adapted to the Raspberry Pi (LCD and LEDs).

Code from

http://www.cooking-hacks.com/documentation/tutorials/geiger-counter-arduino-radiation-sensor-board#source_code

Adapted by circulosmeos (circulosmeos.wordpress.com):
for RPi compatibility

See

http://circulosmeos.wordpress.com/2014/04/21/radiation-detection-with-raspberry-pi/

COMPILATION
===========
$ g++ -lrt -lpthread geiger_lcdnleds.c LiquidCrystal.cpp Print.cpp arduPi.cpp -o geiger_lcdnleds
