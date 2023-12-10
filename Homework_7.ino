#include <LiquidCrystal.h>
#include <EEPROM.h>
const byte rs = 9;
const byte en = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 2; // Replace with your actual button pin
int buttonState = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

byte settingsWheel[8] = {
  B00100,
  B01010,
  B01010,
  B00100,
  B00000,
  B00100,
  B00000,
  B00000
};

byte sign[8] = {
  B00000,
  B01110,
  B01010,
  B00010,
  B00110,
  B00100,
  B00000,
  B00100
};

int lcdBrightness;
int matrixBrightness; 

void setup() {
  lcd.createChar(5, settingsWheel);
  lcd.createChar(6, sign);
  lcd.begin(16, 2);
  pinMode(3, OUTPUT);
  lcdBrightness = EEPROM.read(0);
  matrixBrightness = EEPROM.read(1);
  analogWrite(3, lcdBrightness);
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis <= interval) {
  showIntroMessage();
  currentMillis = millis();
  }
 

  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // Initialize Serial communication

  // Load brightness values from EEPROM on system start
}

void loop() {
   // Display the intro message for 3 seconds
  showMainMenu();
  
}

void showIntroMessage() {
  lcd.clear();
  unsigned long currentMillis = millis();

      lcd.setCursor(0, 0);
      lcd.print("Welcome to the");
      lcd.setCursor(0, 1);
      lcd.print("Game!");
 
}

int readChoice() {
  while (!Serial.available()) {
    // Wait for user input in Serial Monitor
  }
  return Serial.parseInt(); // Read the user's choice as an integer
}

void showMainMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1.Start 2.Sett.");
  lcd.setCursor(15, 0);
  lcd.write((byte)5); // Display the settings wheel

  lcd.setCursor(0, 1);
  lcd.print("3.About");
  lcd.setCursor(8, 1);
  lcd.write((byte)6); 
  lcd.write((byte)6); 
  // Read user choice from Serial Monitor
  int choice = readChoice();

  // Handle user selection
  switch (choice) {
    case 1:
      startGame();
      break;
    case 2:
      showSettingsMenu();
      break;
    case 3:
      showAbout();
      break;  
    case 4:
      endGame();
      break;   
  }
 
}

void startGame() {
  lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("3 lives");
   lcd.setCursor(0, 1);
   lcd.print("Score: 0");
   while (Serial.parseInt() != 1) {
    // Wait for the button to be pressed
  }
  showMainMenu();
}

void showSettingsMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. LCD Brightness");
  lcd.setCursor(0, 1);
  lcd.print("2. Matrix Brightness");
  
  // Read user choice from Serial Monitor
  int choice;

  while(choice!=3){
     choice = readChoice();
  switch (choice) {
    case 1:
      lcdBrightness = adjustBrightness("LCD"),analogWrite(3, lcdBrightness),showSettingsMenu(),EEPROM.write(0, lcdBrightness),EEPROM.write(1, matrixBrightness);

      break;
    case 2:
      matrixBrightness = adjustBrightness("Matrix"),showSettingsMenu(),EEPROM.write(0, lcdBrightness),EEPROM.write(1, matrixBrightness);
      break;
    case 3:
    break;
      
    
  }
  }
  showMainMenu();
  
}

int adjustBrightness(const char* device) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Adjusting ");
  lcd.print(device);
  lcd.print(" Brightness");

  lcd.setCursor(0, 1);
  lcd.print("Use arrow keys");

  int brightness = 0;
  int arrowKey = 0;

  while (arrowKey != '1') { // '\r' is the Enter key
    if (Serial.available()) {
      arrowKey = Serial.read();
      
      switch (arrowKey) {
        case 'A': // Up arrow key
          brightness = min(brightness + 10, 255); // Increase brightness (up to 255)
          break;
        case 'B': // Down arrow key
          brightness = max(brightness - 10, 0);   // Decrease brightness (down to 0)
          break;
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Adjusting ");
      lcd.print(device);
      lcd.print(" Brightness");

      lcd.setCursor(0, 1);
      lcd.print("Brightness: ");
      lcd.print(brightness);
    }
  }

  return brightness;
}

void showAbout() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bomber game");
  lcd.setCursor(0, 1);
  lcd.print("Have fun!");
  // Display information about the game and its creators
  while (Serial.parseInt() != 1) {
    // Wait for the button to be pressed
  }
  
  showMainMenu();
  
  
}

void endGame() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over");

  // Wait for user prompt (e.g., button press) before returning to main menu
  while (Serial.parseInt() != 1) {
    // Wait for the button to be pressed
  }

  // Return to the main menu
  showMainMenu();
}



