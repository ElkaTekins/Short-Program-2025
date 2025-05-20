#include <Wire.h>                 // Library for I2C communication
#include <LiquidCrystal_I2C.h>    // Library for LCD with I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define button pin
const int buttonPin = 6;

void setup() {
  lcd.begin();               
  lcd.backlight();           

  lcd.setCursor(0, 0);       
  lcd.print("Hello, world!");
  delay(3000);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool isButtonPressed = digitalRead(buttonPin) == LOW;

  if (isButtonPressed) {
    lcd.clear();                      
    lcd.setCursor(0, 0);              
    lcd.print("Button Pressed!");     
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press the button");    
  }

  delay(200); 
}