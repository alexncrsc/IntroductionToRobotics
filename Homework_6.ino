#include "LedControl.h"
int timer=0;
int ctime;
long time=0;
LedControl lc = LedControl(12, 11, 10, 1);  // Pins for DIN, CLK, CS, and number of MAX7219s
bool explosion=0;
long long p_time=0;
long long b_time=0;
const int joyXPin = A0;  // Connect joystick X-axis to analog pin A0
const int joyYPin = A1;  // Connect joystick Y-axis to analog pin A1
const int joyButtonPin = 2;
int a,b; //coordonates for animation
long exp_time=0;
int var=0;
int count=8;
bool ammo=1;
static int lastButtonState = HIGH;  // Initialize the last button state
static unsigned long lastDebounceTime = 0;  // Initialize the last debounce time
const int debounceDelay = 50;  

long long move_time=0;

class Player {
public:
  int x, y;
  int blinkInterval;
  bool isBlinkOn;

  Player(int startX, int startY, int blinkRate) : x(startX), y(startY), blinkInterval(blinkRate), isBlinkOn(true) {}

  void draw() {
    if (isBlinkOn) {
      lc.setLed(0, x, y, true);
    }
    else
        lc.setLed(0, x, y, false);
  }

  void erase() {
    lc.setLed(0, x, y, false);
  }

  void move(int deltaX, int deltaY) {
    erase();
    x += deltaX;
    y += deltaY;
    draw();
  }

  void updateBlink() {
    isBlinkOn = !isBlinkOn;
  }
};

class Bomb {
public:
  int x, y;
  int blinkInterval;
  bool isBlinkOn;

  Bomb(int startX, int startY, int blinkRate) : x(startX), y(startY), blinkInterval(blinkRate), isBlinkOn(true) {}

  void draw() {
    if (isBlinkOn) {
      lc.setLed(0, x, y, true);
    }
    else
      lc.setLed(0, x, y, false);
  }

  void erase() {
    lc.setLed(0, x, y, false);
  }

  void updateBlink() {
    isBlinkOn = !isBlinkOn;
  }
};

class Wall {
public:
  int x, y;

  // Default constructor
  Wall() : x(0), y(0) {}

  // Parameterized constructor
  Wall(int startX, int startY) : x(startX), y(startY) {}

  void draw() {
    lc.setLed(0, x, y, true);
  }
  void erase() {
    lc.setLed(0, x, y, false);
  }

};


const int maxWalls = 8;
Wall walls[maxWalls] = {
  Wall(1, 2),
  Wall(4, 5),
  Wall(7, 3),
   Wall(4, 2),
  Wall(6, 5),
  Wall(8, 3),
   Wall(3, 2),
  Wall(2, 5),
  
};

void setup() {
  Serial.begin(9600);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  pinMode(joyXPin, INPUT);
  pinMode(joyYPin, INPUT);
  pinMode(joyButtonPin, INPUT_PULLUP);


}

void drawAllEntities(Player& player, Bomb& bomb) {
  player.draw();
  bomb.draw();
  for (int i = 0; i < maxWalls; ++i) {
    walls[i].draw();
  }
}



Player player(6, 6, 300);  // Initial position for the player with a blink interval of 1000ms
  Bomb bomb(-1, -1, 100);      // Initial position for the bomb with a blink interval of 500ms
  


void isCollision(Player& player, Bomb& bomb) {
  


  for (int i = 0; i < maxWalls; i++) {
    if(((abs(bomb.x - walls[i].x) == 1 && bomb.y == walls[i].y) || (bomb.x == walls[i].x && abs(bomb.y - walls[i].y) == 1))&& explosion==1) {
          walls[i].x=-1, walls[i].y=-1,walls[i].draw(), Serial.print("zid"), count=count-1;
    }
  }
  if(((abs(bomb.x - player.x) == 1 && bomb.y == player.y) || (bomb.x == player.x && abs(bomb.y - player.y) == 1))&& explosion==1) {
    Serial.print("mort"),loose();
}
  

  

}


void handleJoystick(Player& player) {
  const int joyX = analogRead(joyXPin);
  const int joyY = analogRead(joyYPin);

  // Define a dead zone to ignore small fluctuations when the joystick is released
  const int deadZone = 100;

  // Map joystick values to player movement, considering the dead zone
  int deltaX = 0;
  int deltaY = 0;

  if (abs(joyX - 512) > deadZone) {
    deltaX = (joyX < 512) ? -1 : 1;
  }

  if (abs(joyY - 512) > deadZone) {
    deltaY = (joyY < 512) ? 1 : -1;
  }

  // Ensure the player moves only one position at a time
  const int movementSpeed = 200;  
  long  currentTime = millis();

  if (currentTime - move_time > movementSpeed) {
    if (!isWallInDirection(player, deltaX, deltaY)) {
    
    player.move(deltaX, deltaY);
  }
    move_time = currentTime;
  }
}

void loop() {
  
Serial.print(count);
  while (true) {
    if(count==1)
      win();
    drawAllEntities(player, bomb);
   handleJoystick(player);
   isCollision(player, bomb);
    while(var==-1){
      
        lc.setLed(0, 2, 3, true);
  lc.setLed(0, 5, 3, true);

  // Mouth
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 4, 5, true);
  lc.setLed(0, 5, 6, true);

        if(millis() -ctime>2500){
          var=0;
          lc.setLed(0, 2, 3,false);
  lc.setLed(0, 5, 3,false);

  // Mouth
  lc.setLed(0, 2, 6, false);
  lc.setLed(0, 3, 5, false);
  lc.setLed(0, 4, 5, false);
  lc.setLed(0, 5, 6, false);
   reset();
}
        }
      
  while(var==1){
            lc.setLed(0, 2, 3, true);
  lc.setLed(0, 5, 3, true);

  // Mouth
  lc.setLed(0, 2, 5, true);
  lc.setLed(0, 3, 6, true);
  lc.setLed(0, 4, 6, true);
  lc.setLed(0, 5, 5, true);
        if(millis() -ctime>2500){
          var=0;
           lc.setLed(0, 2, 3, false);
  lc.setLed(0, 5, 3, false);

  // Mouth
  lc.setLed(0, 2, 5, false);
  lc.setLed(0, 3, 6, false);
  lc.setLed(0, 4, 6, false);
  lc.setLed(0, 5, 5, false);
            reset();
        }
      
  }
    

   
  long long player_time = millis();

  if (player_time - p_time > player.blinkInterval) {
    player.updateBlink();
    p_time = player_time;
     drawAllEntities(player, bomb);
  }

  long long bomb_time = millis();
  if (bomb_time - b_time > bomb.blinkInterval) {
    bomb.updateBlink();
    b_time = bomb_time;
     drawAllEntities(player, bomb);
  }

  int buttonState = digitalRead(joyButtonPin);



  if (buttonState != lastButtonState ) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay ) {
    // If the button state has changed and is stable for the debounce delay
    if (buttonState == LOW) {
      // Spawn a bomb at the player's position
      if(ammo==1){
      bomb.x = player.x;
      bomb.y = player.y;
      }
      timer=1;
      time =millis();
      ammo=0;
    }

    if(timer==0)
      exp_time=0;
    else
      exp_time=millis();
    Serial.println(count);
    if(exp_time -time>3000&&exp_time -time<3350){
      lc.setLed(0, bomb.x, bomb.y+1, true);
      lc.setLed(0, bomb.x-1, bomb.y, true);
      lc.setLed(0, bomb.x+1, bomb.y, true);
      lc.setLed(0, bomb.x, bomb.y-1, true);
      lc.setLed(0, bomb.x, bomb.y, true);
      explosion = true;
    }
    if(exp_time -time>3350&&exp_time -time<3500){
      lc.setLed(0, bomb.x, bomb.y+1, false);
      lc.setLed(0, bomb.x-1, bomb.y, false);
      lc.setLed(0, bomb.x+1, bomb.y, false);
      lc.setLed(0, bomb.x, bomb.y-1, false);
      if(bomb.x!=-1){
        a=bomb.x; //animation
        b=bomb.y; //animation
      }
      bomb.x = -1;
      bomb.y = -1;
    }
    if(exp_time -time>3700){
      lc.setLed(0, a, b, false);
      explosion = false;
      timer=0;
      ammo=1; //you can have just one bomb at a time
    
    }
}

  lastButtonState = buttonState;
    

  
  }
  
}


void loose(){
    eraseAllEntities(player, bomb);
    var=-1;
   ctime=millis();
    lc.setLed(0, bomb.x, bomb.y+1, false);
      lc.setLed(0, bomb.x-1, bomb.y, false);
      lc.setLed(0, bomb.x+1, bomb.y, false);
      lc.setLed(0, bomb.x, bomb.y-1, false);
     lc.setLed(0, bomb.x, bomb.y, false);
     bomb.x=-1,bomb.y=-1; 
}
void win(){
 eraseAllEntities(player, bomb);
 ctime=millis();
 lc.setLed(0, bomb.x, bomb.y+1, false);
      lc.setLed(0, bomb.x-1, bomb.y, false);
      lc.setLed(0, bomb.x+1, bomb.y, false);
      lc.setLed(0, bomb.x, bomb.y-1, false);
     lc.setLed(0, bomb.x, bomb.y, false);
     bomb.x=-1,bomb.y=-1; 
  var=1;
}

void reset(){
  eraseAllEntities(player, bomb);
  walls[1].x=1;
  walls[1].y=2;
  walls[2].x=4;
  walls[2].y=5;
  walls[3].x=7;
  walls[3].y=3;
  walls[4].x=4;
  walls[4].y=2;
  walls[5].x=6;
  walls[5].y=5;
  walls[6].x=8;
  walls[6].y=3;
  walls[7].x=3;
  walls[7].y=2;
  walls[8].x=2;
  walls[8].y=5;


  player.x=6;
  player.y=6;
  explosion=0;
  count=8;

}


bool isWallInDirection(Player& player, int deltaX, int deltaY) {
  // Calculate the new position after the move
  int newX = player.x + deltaX;
  int newY = player.y + deltaY;

  // Check if the new position is within the bounds of the LED matrix
  if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
    return true;  // The move is out of bounds, treat it as a wall
  }

  // Check if there is a wall at the new position
  for (const auto& wall : walls) {
    if (wall.x == newX && wall.y == newY) {
      return true;  // There is a wall in the direction of the move
    }
  }

  return false;  // No wall in the direction of the move
}


void eraseAllEntities(Player& player, Bomb& bomb) {
  player.erase();
  bomb.erase();
  for (int i = 0; i < maxWalls; ++i) {
    walls[i].erase();
  }
}
