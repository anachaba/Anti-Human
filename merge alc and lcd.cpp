#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address and dimensions
const int alcoholPin = A0;  // Analog pin connected to the alcohol sensor

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);  // Set the cursor to the first column, first row
  lcd.print("Alcohol Sensor");  // Display a welcome message
  lcd.setCursor(0, 1);  // Set the cursor to the first column, second row
  lcd.print("Not Detected");  // Display initial status
  delay(2000);  // Display the welcome message for 2 seconds
  lcd.clear();  // Clear the LCD display
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int alcoholValue = analogRead(alcoholPin);  // Read alcohol sensor value
  
  float voltage = alcoholValue * (5.0 / 1023.0);  // Convert analog value to voltage
  float alcoholConcentration = map(voltage, 0.0, 5.0, 0, 100);  // Map voltage to alcohol concentration range
  
  if (alcoholConcentration > 0.0) {
    lcd.setCursor(0, 0);
    lcd.print("Alcohol Detected ");
    lcd.setCursor(0, 1);
    lcd.print("(Rejected)       ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Alcohol Not      ");
    lcd.setCursor(0, 1);
    lcd.print("Detected (Accepted)");
  }
  
  Serial.print("Alcohol Value: ");
  Serial.print(alcoholValue);
  Serial.print(", Alcohol Concentration: ");
  Serial.print(alcoholConcentration);
  Serial.println("%");
  
  delay(1000);  // Delay between readings
}
