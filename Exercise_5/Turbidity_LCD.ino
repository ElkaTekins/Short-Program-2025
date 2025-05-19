#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define turbidity sensor analog input pin
const int turbidityPin = A2;

// Define reference voltage and ADC resolution
const float referenceVoltage = 5.0;
const int adcResolution = 1024; 

void setup() {
  lcd.begin();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Turbidity Sensor");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read analog value from pH sensor
  int analogValue = analogRead(turbidityPin);
  
  // Convert analog value to voltage
  float voltage = analogValue * (referenceVoltage / adcResolution);

  // Convert voltage to NTU value based on datasheet formula
  float NTU  = 100.00 - (voltage/4.16) * 100.00;
  
  // Ensure NTU is not negative
  if (NTU < 0) {
    NTU = 0;
  }

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Volt: ");
  lcd.print(voltage, 2);
  lcd.print(" V");

  lcd.setCursor(0, 1);
  lcd.print("NTU: ");
  lcd.print(NTU, 1);

  delay(1000); 
}
