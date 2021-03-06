#include "Arduino.h"
#include "lcd_i2c.h"

void displayWaterLevel(const char *txt) {
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");
  lcd.setCursor(0, 1);
  lcd.print(txt);
}

void displayMoistureLevel(int moisture) {
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Moisture Level:");

  lcd.setCursor(0, 1);
  lcd.print("|");
  for (int i=14; i > 0; --i) {
    if (moisture <= i) {
      lcd.print("=");
    } else {
      lcd.print(" ");
    }
  }
  lcd.print("|");
}

void displayTemperatureAndHumidity(float temp, float humidity) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity, 1);
  lcd.print("%");
}

void printTopRow(const char *txt) {
  lcd.setCursor(0, 0);
  lcd.print(txt);
}

void printBottomRow(const char *txt) {
  lcd.setCursor(0, 1);
  lcd.print(txt);
}
