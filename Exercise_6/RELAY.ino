#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pin numbers
const int buzzerPin = 7; 
const int buttonPin = 6;     
const int relayPin = 5;      

void setup() {
  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Turn relay off initially
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);

  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Relay Controller");
  delay(2000);
  lcd.clear();
}

void loop() {
  bool buttonPressed = digitalRead(buttonPin) == LOW;
                                     
  if (buttonPressed) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Status: ON       "); 
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Status: OFF      ");
  }

  delay(300); 
}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pin numbers
const int buzzerPin = 7; 
const int buttonPin = 6;     
const int relayPin = 5;      

void setup() {
  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Turn relay off initially
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);

  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Relay Controller");
  delay(2000);
  lcd.clear();
}

void loop() {
  bool buttonPressed = digitalRead(buttonPin) == LOW;
                                     
  if (buttonPressed) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Status: ON       "); 
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Status: OFF      ");
  }

  delay(300); 
}