#include "Arduino.h"
#include "SoilMoistureSensor.h"

int getMoistureLevel() {
  int sensorRead = analogRead(SOIL_PIN);
  // Map the moisture to a 0-10 range
  int moistureLevel = map(sensorRead, 0, 1023, 0, 13);
  Serial.print("Moisture level:");
  Serial.println(moistureLevel);
  Serial.print(sensorRead);
  Serial.println("(analog read)");
  return moistureLevel;
}
