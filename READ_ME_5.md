## Objective
Develop a "Smart Environment Monitor and Logger" using Arduino. The system will utilize various sensors to collect environmental data, store this data in EEPROM, and provide visual feedback through an RGB LED. Additionally, user interaction will be facilitated through a Serial Menu. The project emphasizes the integration of sensor readings, memory management, Serial Communication, and the overall goal of constructing a user-friendly menu.

For a visual reference, you can view a partial example video (specifically on menu parsing) [here](https://www.youtube.com/watch?v=mh0KYdul1Sk).

## Components Required
- Arduino Uno Board
- Ultrasonic Sensor (HC-SR04)
- LDR (Light-Dependent Resistor) also known as Photocell, Photoresistor, or Light Sensor
- RGB LED
- Resistors as needed
- Breadboard and connecting wires
- (Optional) Additional sensors/components for extended functionality

## Menu Structure

### 1. Sensor Settings
   1.1 **Sensors Sampling Interval:** Prompt for a value between 1 and 10 seconds. Use this value as a sampling rate for the sensors. It can be the same for both or different.
   
   1.2 **Ultrasonic Alert Threshold:** Prompt for a threshold value for the ultrasonic sensor. This can be considered as either the minimum or maximum value. When the sensor value exceeds the threshold, provide an alert, which can be in the form of a message. If the LED is set to Automatic Mode (see section 4.2), it should also turn red if any sensor is outside the threshold.
   
   1.3 **LDR Alert Threshold:** Prompt for a threshold value for the LDR sensor. Similar to the ultrasonic sensor, this can be considered as either the minimum or maximum value. When the sensor value exceeds the threshold, provide an alert, which can be in the form of a message. If the LED is set to Automatic Mode (see section 4.2), it should also turn red if any sensor is outside the threshold.
   
   1.4 **Back:** Return to the main menu.

### 2. Reset Logger Data
   - Print a message prompting confirmation to delete all data, e.g., "Are you sure?". Followed by submenus with YES or NO. You can reset both sensor data at the same time, or individually.
   - 2.1 **Yes.**
   - 2.2 **No.**

### 3. System Status
   3.1 **Current Sensor Readings:** Continuously print sensor readings at the set sampling rate from all sensors. Provide a method to exit (e.g., by pressing a specific key) and inform the user of this method through a message.
   
   3.2 **Current Sensor Settings:** Display the sampling rate and threshold values for all sensors.
   
   3.3 **Display Logged Data:** Display the last 10 sensor readings for all sensors. Alternatively, use a creative approach.
   
   3.4 **Back:** Return to the main menu.

### 4. RGB LED Control
   4.1 **Manual Color Control:** Set the RGB colors manually. Decide how to input them, either by making an option for each channel or by using a string. If you expect a specific format, inform the user accordingly.
   
   4.2 **LED: Toggle Automatic ON/OFF:** If automatic mode is ON, the LED color should be GREEN when all sensor values do not exceed threshold values (no alert) and RED when there is an alert (any sensor value exceeds the threshold). When automatic mode is OFF, the LED should use the last saved RGB values.
   
   4.3 **Back:** Return to the main menu.

## Description
  Very detailed menu with a lot of submenus, it took 7 hours, but it was the most interesting one.
## Video https://www.youtube.com/watch?v=cCMWMu-CBPY
## ![Untitled](https://github.com/alexncrsc/IntroductionToRobotics/assets/61351673/c8dad22f-74a9-4a56-88db-99897a7d422d)

