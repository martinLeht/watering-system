#include "Arduino.h"
#include "water_level_sensor.h"

void getWaterLevel(const char *waterLevelBuffer) {
  int waterLevelValue = analogRead(WATER_SENSOR_PIN);
  if (waterLevelValue <= 200) {
    strcpy(waterLevelBuffer, "Empty");
  } else if (waterLevelValue > 200 && waterLevelValue <= 530) {
    strcpy(waterLevelBuffer, "Low");
  } else if (waterLevelValue > 530 && waterLevelValue <= 600) {
    strcpy(waterLevelBuffer, "Medium");
  } else if (waterLevelValue > 600) {
    strcpy(waterLevelBuffer, "High");
  }
  Serial.print("Water level: ");
  Serial.print(waterLevelBuffer);
  Serial.print("(value = ");
  Serial.print(waterLevelValue);
  Serial.println(")");
  delay(1000);
}
