#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pH sensor analog input pin
const int pHSensorPin = A0;

// Define reference voltage and ADC resolution
const float referenceVoltage = 5.0;
const int adcResolution = 1024; 

void setup() {
  lcd.begin();         
  lcd.backlight();     

  lcd.setCursor(0, 0);
  lcd.print("pH Sensor Ready");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read analog value from pH sensor
  int analogValue = analogRead(pHSensorPin);

  // Convert analog value to voltage
  float voltage = analogValue * (referenceVoltage / adcResolution);

  // Convert voltage to pH value
  float pHValue = 7 + ((2.5 - voltage) / 0.35); 

  // Display pH value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Volt: ");
  lcd.print(voltage, 2);
  lcd.print(" V");
  
  lcd.setCursor(0, 1);
  lcd.print("pH Value: ");
  lcd.print(pHValue, 2); 

  delay(1000); 
}
