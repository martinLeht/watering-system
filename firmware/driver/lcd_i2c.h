#ifndef _LCD_I2C_H
#define _LCD_I2C_H

#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
void displayMoistureLevel(int moisture);
void displayTemperatureAndHumidity(float temp, float humidity);
void printTopRow(const char *txt);
void printBottomRow(const char *txt);

#endif _LCD_I2C_H  
