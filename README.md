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
 ![RGB LED](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/90367b7b-cd40-43f6-a1c4-18c209dbb871)
          
          ### Here is a link showcasing how it works, but it doesn't have subtitles:
          [Watch the video](https://youtu.be/oHhTwCTH0bw)


## Homework 2
          ## Elevator Simulator Project

**Homework #3 - Elevator Simulator**
**Submission Deadline:** Your respective lab in the week of October 30th-November 5th, 2023.

### Description

This assignment involves simulating a 3-floor elevator control system using LEDs, buttons, and a buzzer with Arduino. By the end of this task, you will gain experience in using button state change, implementing debouncing techniques, and coordinating multiple components to represent real-world scenarios.

### Objectives

- Gain a better understanding of debouncing functionality.
- Learn the functionality of a buzzer.
- Improve the utilization of the principle of pull-up resistors.
- Enhance logical thinking.

### Project Components

- Three floors with associated buttons, each connected to GND and a PIN on the Arduino (from 2 to 5).
- LEDs on each floor to indicate the elevator's current position, connected to GND and Arduino PINs (from 10 to 12).
- An additional LED to indicate the elevator's availability, connected to PIN 13.
- A buzzer connected to PIN 8.

### Project Logic

The project involves moving the elevator up and down between the specified floors by pressing the corresponding buttons. The buttons are configured with debouncing to ensure accurate button presses. The elevator has the capability to move both up and down, causing updates to the LED states on each floor. A buzzer is used to signal when the elevator is ready for use.

### Final Product

![Elevator Simulator](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/7a625d4d-d8ce-44c5-938a-b882d3dc0735)

### Video Showcase

View a short video showcasing the project on [YouTube](https://youtu.be/kRsa0LXNc7k).


## Homework 3

omework #4 - 7 segment display drawingDeadline (hard): Your respective lab in the week of October 6th -November 12th, 2023. You must have the Git ready and the assign-ment turned in before the start of lab.•General description:You will use the joystick to control the position ofthe segment and ”draw” on the display.  The movement between segmentsshould be natural, meaning they should jump from the current positiononly to neighbors, but without passing through ”walls”.•Example video:https://www.youtube.com/watch?v=03NsXO1_Q_4•Components:  1  7-segment  display,  1  joystick,  resistors  and  wires  (perlogic)•Requirement:The  initial  position  should  be  on  the  DP.  The  currentposition always blinks (irrespective of the fact that the segment is on oroff).  Use the joystick to move from one position to neighbors (see table forcorresponding movement).  Short pressing the button toggles the segmentstate  from  ON  to  OFF  or  from  OFF  to  ON.  Long  pressing  the  buttonresets the entire display by turning all the segments OFF and moving thecurrent position to the decimal point.Interrupts are required for CTIand bonus for Computer Science.Be careful:1.  Joystick movements should be done with toggle, as in the lab (joy-Moved, etc)2.  For CTI, it is part of requirement to use interrupts.  For ComputerScience, it is a bonus.3.  The  code  in  the  lab  for  joystick  movement  is  not  perfect  and  canbe  improved.   The  code  should  be  wrapped  in  a  function  and  theconstraint between 0 and 9 can be simplified.1
Unibuc Robotics2022 - 2023Current segment  UP  DOWN  LEFT  RIGHTaN/AgfbbagfN/AcgdedpdgN/AecegdN/AcfagN/AbgadN/AN/AdpN/AN/AcN/A•Publishing task:You must add the code to the Github repo and continueupdating the readme with at least the following details (but feel free tobe more creative).  I recommend using dropdowns in the readme, for eachproject, if you feel the readme is too cluttered:https://gist.github.com/citrusui/07978f14b11adada364ff901e27c7f611.  Task Requirements2.  Picture of the setup3.  Link to video showcasing functionality (I recommend youtube,  butanything I can access is fine)4.  Remember to publish the video in the correct orientation.  Don’t dothis:https://youtu.be/Y8H0PlUtcto5.Hand in the homework on MS teams when done - aka whenGit is up to date•Coding task:Coding style is of utmost importance.  You must have aperfectly clean code in order to receive the maximum grade.  An importantcoding challenge present in this task is usingmillis() or micros()andinterruptsinstead ofdelay().  Do not use repetitive structures such aswhile().  You can usefor()in certain cases where it removes repeatedcode (such as addressing all the segments, changing the pinMode() etc.).However, remember that the bulk of the grade is if the projectsworks.Do not tend to small details unless you have the entire functionality done.•Possible bonus points:–Add other components, such as sounds, other LEDs etc.  Be creative.–Computer  Science  students,  you can  use  interrupts  for  bonus.  ForCTI it is part of the basic requirement. Make sure you use it correctly.It’s  best  to  have  a  functional  homework  without  interrupts  ratherthan one with interrupts that does not work.


To be fair, I don't where to start from, this was the hardest one yet, 7 hours straight, working on it. 

#Description:
The homework focused on using a 7-segment display. I learned how to implement interrupts and gained a better understanding of the Arduino's flow. While I believe I've improved my ability to work with the flow and create useful functions, I acknowledge that the approach I took for this homework was quite complex. During the project, I used various delay variables and the millis function for different purposes, including debouncing both joystick movement and button presses.

I worked with three arrays simultaneously: one for controlling the LED pins, one for storing the segment names to track the current segment, and another for keeping track of which LEDs were selected. The most challenging aspect of the assignment was ensuring that the Arduino didn't repeatedly toggle the segment due to continuous button presses.

#Photo: ![Untitled](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/18de8167-37eb-4781-9a72-8224dae3901d)


#Link to a video where it's showcased:  https://www.youtube.com/watch?v=0s4tPm-hV2c&feature=youtu.be


