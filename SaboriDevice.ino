// For Arduino Micro
#include "Keyboard.h"

int brightness = 0;

void setup() {
  Keyboard.begin();
  pinMode(LED_BUILTIN, OUTPUT);       // Heartbeat
}

void loop() {
  analogWrite(LED_BUILTIN, brightness);   // Update Heartbeat LED
  delay(60000/255);                       // wait

  if(brightness == 0) {
    // Run every minute
    brightness = 255;

    // Push key twice every minute
    // (Push twice to keep Scroll Lock state)
    Keyboard.press(KEY_SCROLL_LOCK);
    delay(250);
    Keyboard.releaseAll();
    delay(250);
    Keyboard.press(KEY_SCROLL_LOCK);
    delay(250);
    Keyboard.releaseAll();
  } else {
    brightness--;   // get darker and darker...
  }
}
