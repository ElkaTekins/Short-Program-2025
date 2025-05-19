#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define sensor pins
const int turbidityPin = A2;
const int tdsSensorPin = A1;    
const int pHSensorPin = A0;     

// Define reference voltage and ADC resolution
const float referenceVoltage = 5.0;
const int adcResolution = 1024;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read Turbidity sensor
  int turbidityValue = analogRead(turbidityPin);
  float turbidityVoltage = turbidityValue * (referenceVoltage / adcResolution);
  float turbidityNTU  = 100.00 - (turbidityVoltage/4.16) * 100.00;
  if (turbidityNTU < 0) turbidityNTU = 0;

  // Read TDS sensor
  int tdsValue = analogRead(tdsSensorPin);
  float tdsVoltage = tdsValue * (referenceVoltage / adcResolution);
  float tdsPPM = (133.42 * pow(tdsVoltage, 3) - 255.86 * pow(tdsVoltage, 2) + 857.39 * tdsVoltage) * 0.5;
  if (tdsPPM < 0) tdsPPM = 0;

  // Read pH sensor
  int pHValue = analogRead(pHSensorPin);
  float pHVoltage = pHValue * (referenceVoltage / adcResolution);
  float pH = 7 + ((2.5 - pHVoltage) / 0.35);

  // Send data to Serial Monitor
  Serial.print("TDS:");
  Serial.print(tdsPPM, 2);
  Serial.print(",Turbidity:");
  Serial.print(turbidityNTU, 2);
  Serial.print(",pH:");
  Serial.println(pH, 1);

  delay(1000);
}
