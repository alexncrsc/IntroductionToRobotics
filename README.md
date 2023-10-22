# 👾 Introduction to Robotics (2023 - 2024) 👾

## Description
This repository is dedicated to the homework assignments for the Introduction to Robotics course. I'm thrilled to embark on this journey of creating intriguing robots. Each project will be thoroughly explained, allowing you to join me on this exciting adventure. Let's build together!

## Homework 1

### Homework #1 Deadline (hard): 
Your respective lab session in the week of October 23rd-29th, 2023. This assignment focuses on controlling each channel (Red, Green, and Blue) of an RGB LED using individual potentiometers. By the end of this task, you will gain experience in interfacing potentiometers with Arduino and controlling RGB LEDs based on analog readings. You must complete the work before your laboratory session and present it there. This includes everything: hardware, coding, and GitHub documentation. 

Example: [Watch the video](https://www.youtube.com/watch?v=tbynfti3OEo)

### Technical Task:
Use a separate potentiometer for controlling each color of the RGB LED: Red, Green, and Blue. This control leverages digital electronics. Specifically, you need to read the potentiometer's value with Arduino and then write a mapped value to the LED pins.

### Description:
This homework serves as a crucial starting point; if we can't complete this task, we won't be able to tackle the rest of the assignments. 💀💀💀💀
We're using three potentiometers to adjust the color of an RGB LED. The goal of this homework is to learn how to write Arduino code to take input from the potentiometers and provide output to the RGB LED. It also serves as practice for understanding code structure and working with circuits.
I used the pins A0, A1, and A2 to input the data set by the potentiometers, converted it to the appropriate value within the RGB data range, and outputted it to pins 9, 10, and 11. I used resistors to ensure that nothing gets damaged. The `map` function was used for efficient conversion.
PS: I didn't check beforehand if I had the correct-colored wires; for future projects, I will be more prepared. In this project, I used black for GND, red and orange for A0, A1, and A2 and their connections, blue for the potentiometer input, and yellow for the output to the RGB LED.

### The final product should look like this:
![Untitled](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/90367b7b-cd40-43f6-a1c4-18c209dbb871)

### Here is a link showcasing how it works, but it doesn't have subtitles:
[Watch the video](https://youtu.be/oHhTwCTH0bw)
