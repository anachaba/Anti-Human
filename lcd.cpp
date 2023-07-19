#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//SDA==A4
//SCL==A5
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address and dimensions

void setup() {
    // Display "Hello" on the LCD
    LCD_TEST();
  
}
void LCD_TEST(){
  lcd.begin(16, 2);  // Initialize the LCD
  lcd.setBacklight(HIGH);
  lcd.print("Hello");
  }

void loop() {
  // No additional actions in the loop
}