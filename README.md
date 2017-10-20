# Loud Lights
![Alt text](https://imgur.com/c97UVmN "Project Picture")\
  + Brandon Tran
  + Danielle Robinson
  + Victoria Sneddon
  + Sponsored by Northrop Grumman

## Abstract
Our goal was to build an LED display that would reflect the intensity of the music played

## How It Works
Using a Graphic Equalizer Display Filter chip, we split input audio into seven bands of frequencies. Our code translates the seven frequencies onto the LED display. We created multiple 'modes' for which the display shows patterns correlating to the input audio.

## Code
We used a brute force approach to program each iteration of a for-loop interfacing the MSGEQ7 chip. Consequently our program consists of 660 lines of code.

## Parts
 + Graphic Equalizer Display Filter: MSGEQ7 and circuit board from Sparkfun
 + Display: 2 5x8 LED Matrices from Adafruit 
 + Arduino Board & Kit: Provided by Northrop Grumman
