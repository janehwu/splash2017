void printKeys() {
  char key = keypad.getKey();
  
  if(key != NO_KEY) {
    Serial.println(key);
  }
}

void checkPassCode() {
  // Get the current key being pressed
  char key = keypad.getKey();
  
  // If already unlocked or nothing pressed, no need to check for code
  if(!(isLocked) || key == NO_KEY) { return; }
  
  // If we pressed the correct key
  if(key == code[index]) {
    Serial.println(key);
    index += 1;
    if(index == sizeof(code)) {
      Serial.println("UNLOCKED");
      isLocked = 0;
      index = 0;
    }
  }
  else {
    Serial.println(key);
    index = 0;
  }
}
