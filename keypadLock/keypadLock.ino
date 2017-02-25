// Splash 2017, Designing with Arduino
// Starter Code for reading 4x4 matrix keypad
// jhwu@hmc.edu
#include <Keypad.h>
#include <Servo.h>

// Keypad pins, Left (*) to Right (D)
// R1 R2 C0 R3  C1 C2 C3 R0
#define R0 2
#define R1 12
#define R2 11
#define R3 9
#define C0 10
#define C1 5
#define C2 4
#define C3 3

#define SERVOPIN 6 // Servo

Servo servo;

// Initialize keypad
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'}
};
byte rowPins[rows] = {R0,R1,R2,R3}; //connect to the row pinouts of the keypad
byte colPins[cols] = {C0,C1, C2,C3}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

char code[] = {'2','4','6','8'};
int index = 0;
int isLocked = 1;

void setup() {
  Serial.begin(9600);
  pinMode(SERVOPIN, OUTPUT);
  servo.attach(SERVOPIN);
  Serial.println("Reading keypad...");
}

void loop() {
  //printKeys();
  checkPassCode();
  if(isLocked == 0) {
    servo.write(90);
    delay(500);
    servo.write(-90);
    delay(500);
    servo.write(0);
    isLocked = 1;
  }
}
