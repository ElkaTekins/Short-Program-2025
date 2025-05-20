#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define TDS sensor analog input pin
const int tdsSensorPin = A1;

// Define reference voltage and ADC resolution
const float referenceVoltage = 5.0;    
const int adcResolution = 1024;        

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("TDS Sensor Ready");

  delay(2000);
  lcd.clear();
}

void loop() {
  // Read analog value from TDS sensor
  int analogValue = analogRead(tdsSensorPin);

  // Convert analog value to voltage
  float voltage = analogValue * (referenceVoltage / adcResolution);

  // Convert voltage to ppm
  float tdsValue = (133.42 * pow(voltage, 3) - 255.86 * pow(voltage, 2) + 857.39 * voltage) * 0.5;

  // Display TDS value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Volt: ");
  lcd.print(voltage, 2);
  lcd.print(" V");
  
  lcd.setCursor(0, 1);
  lcd.print("TDS: ");
  lcd.print(tdsValue, 0);  
  lcd.print(" ppm   ");
  delay(1000);  
}