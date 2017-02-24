#include <Key.h>
#include <Keypad.h>

#define r0 2
#define r1 12
#define r2 11
#define r3 9

#define c0 10
#define c1 5
#define c2 4
#define c3 3

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'}
};
byte rowPins[rows] = {r0,r1,r2,r3}; //connect to the row pinouts of the keypad
byte colPins[cols] = {c0,c1,c2,c3}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  Serial.begin(9600);
  Serial.println("Reading keypad...");
}

void loop() {
  char key = keypad.getKey();
  
  if(key != NO_KEY) {
    Serial.println(key);
  }
}
