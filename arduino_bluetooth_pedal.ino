#include "Keyboard.h"
// #include <SoftwareSerial.h>
// SoftwareSerial mySerial(9, 8);// bluetooth TX,RX

int button_down = 2;
int button_up = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(button_down, INPUT);
  pinMode(button_up, INPUT);
  digitalWrite(button_down, HIGH); //activate arduino internal pull up
  digitalWrite(button_up, HIGH);
  Serial.begin(9600);

  // mySerial.begin(9600);
  Keyboard.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  // mySerial.write("Hola mundo bluetooth");
  if (digitalRead(button_down)==LOW){
    // Keyboard.print("You pressed the button ");
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.releaseAll();
  }
  if (digitalRead(button_up) == LOW) {
    Keyboard.press(KEY_UP_ARROW);
    delay(100);
    Keyboard.releaseAll();
  }
  delay(100);
  
}
