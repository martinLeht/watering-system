#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "lcd_i2c.h"
#include "dht11.h"
#include "soilmoisturesensor.h"
#include "utils.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;

void setup() {
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  float *dhtData = getTempAndHum();
  displayTemperatureAndHumidity(dhtData[0], dhtData[1]);
  delay(2000);
  free(dhtData);
  
  int moistureLevel = getMoistureLevel();
  displayMoistureLevel(moistureLevel);
  delay(2000);
}
