# Homework #5 - Stopwatch Timer

## General Description

Using the 4 digit 7-segment display and 3 buttons, we should implement a stopwatch timer that counts in 10ths of a second and has a save lap functionality (similar to most basic stopwatch functions on most phones).

This was challenging, and I have some mistakes regarding the debounce process. Sometimes the input is taken multiple times. In the rest, everything is working fine 😉

## Requirements

- The starting value of the 4 digit 7-segment display should be ”000.0”.
- Buttons functionalities:
  - **Button 1:** Start / pause.
  - **Button 2:** Reset (if in pause mode). Reset saved laps (if in lap viewing mode).
  - **Button 3:** Save lap (if in counting mode), cycle through last saved laps (up to 4 laps).

## Workflow

1. Display shows ”000.0”. When pressing the Start button, the timer should start.
2. During timer counter, each time you press the lap button, you should save that timer’s value in memory (not persistent, it is OK to be deleted upon reset), up to 4 laps (or more if you want); pressing the 5th time should override the 1st saved one. If you press the reset button while the timer works, nothing happens. If you press the pause button, the timer stops.
3. In Pause Mode, the lap flag button doesn’t work anymore. Pressing the reset button resets you to 000.0.
4. After reset, you can now press the flag buttons to cycle through the lap times. Each time you press the flag button, it takes you to the next saved lap. Pressing it continuously should cycle you through it continuously. Pressing the reset button while in this state resets all your flags and takes the timer back to ”000.0”.

## Project Showcase

You can find below an image with the project and a video showcasing it!
![Untitled](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/7033b629-b69f-443d-8a42-d91d26d870ec)

[[Watch the video](https://www.youtube.com/watch?v=0s4tPm-hV2c)](https://youtu.be/oPeYIkepgOw)https://youtu.be/oPeYIkepgOw
