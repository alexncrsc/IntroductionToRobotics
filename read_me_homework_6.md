# Bomber Game with 8x8 LED Matrix

## Objective
Develop a small Bomberman-style game on an 8x8 LED matrix. The game includes a player, bombs/bullets, and walls. The goal is to destroy all the walls with the bomb without getting caught in the explosion.

## Components Required
- Arduino Uno Board
- Joystick
- 8x8 LED Matrix
- MAX7219
- Resistors and capacitors as needed
- Breadboard and connecting wires
- (Optional) Additional sensors/components for extended functionality

## Description
I created a Bomber-style game for a robotics project. The player moves with a joystick, and if you can't move into a wall, pressing the joystick spawns a bomb. The bomb blinks fast, and you need to run away to avoid the explosion. The blast range is a + sign centered on the bomb, destroying walls in its path. Win by destroying all walls; lose by getting caught in an explosion. Only one bomb can be placed at a time.

## Code Structure
The code follows OOP principles for better structure. Player and wall positions are predetermined. The game resets if you win or lose. Using a single bomb variable simplifies logic.

## Media
![Bomber Game](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/c9e9c48f-a840-47c1-a683-28271129ab10)
[Watch the Video](https://www.youtube.com/watch?v=jMmMzy77aes)

## Getting Started
1. [Install Arduino IDE](https://www.arduino.cc/en/software)
2. Connect components as per the circuit diagram.
3. Upload the code to your Arduino Uno.
4. Enjoy playing the Bomber game!

## Acknowledgments
Thanks to the Introduction to Robotics course for this exciting project!

