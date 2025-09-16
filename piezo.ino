#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
 
// Pin definitions const int piezoPin = A0;      // Analog pin for piezo const int dcMotorPin = A1;    // Analog pin for DC motor const int ledPin = 13;        // LED pin (optional) 
const int threshold = 512;    // LED activation threshold 
 
int piezoValue = 0; int dcMotorValue = 0; 
 
// Initialize LCD: address 0x27, 16 characters, 2 lines 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
 
void setup() { 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
 
  // LCD setup   lcd.init();   lcd.backlight();   lcd.setCursor(0, 0);   lcd.print("Dual Voltage");   delay(1000);   lcd.clear(); 
} 
 
void loop() { 
  // Read sensor values   piezoValue = analogRead(piezoPin);   dcMotorValue = analogRead(dcMotorPin); 
 
  // Convert to voltage   float piezoVoltage = piezoValue * (5.0 / 1023.0);   float motorVoltage = dcMotorValue * (5.0 / 1023.0); 
 
  // Debug output 
  Serial.print("Piezo: "); 
  Serial.print(piezoVoltage, 2); 
  Serial.print(" V\tMotor: "); 
    Serial.print(motorVoltage, 2); 
  Serial.println(" V"); 
 
  // Display on LCD   lcd.setCursor(0, 0);   lcd.print("Piezo: ");   lcd.print(piezoVoltage, 2);   lcd.print("V  "); 
 
  lcd.setCursor(0, 1);   lcd.print("Motor: ");   lcd.print(motorVoltage, 2);   lcd.print("V  "); 
 
  // Optional LED indicator   if (piezoValue > threshold || dcMotorValue > threshold) {     digitalWrite(ledPin, HIGH); 
  } else {     digitalWrite(ledPin, LOW); 
  } 
 
  delay(500); 
} 
