#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "lcd_i2c.h"
#include "dht11.h"
#include "soil_moisture_sensor.h"
#include "water_level_sensor.h"
#include "utils.h"

#define MODE_BTN_PIN 2

int modeState = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;

void setup() {
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.clear();

  // Initialize button to change mode with Interrupt Service Routine (ISR)
  pinMode(MODE_BTN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MODE_BTN_PIN), changeModeISR, FALLING);
}

void loop() {
  if (modeState == 0) {
    float *dhtData = getTempAndHum();
    displayTemperatureAndHumidity(dhtData[0], dhtData[1]);
    free(dhtData);
    delay(1500);
  } else if (modeState == 1) {  
    int moistureLevel = getMoistureLevel();
    displayMoistureLevel(moistureLevel);
  } else if (modeState == 2) {
    const char * waterLevel;
    waterLevel = (char *) malloc(7);
    getWaterLevel(waterLevel);
    displayWaterLevel(waterLevel);
    free(waterLevel);
  }
  Serial.print("Mode: ");
  Serial.println(modeState);
  delay(1000);
}

void changeModeISR() {
  modeState++;
  if (modeState > 2) {
    modeState = 0;
  }
}
