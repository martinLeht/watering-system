#include "Arduino.h"
#include "dht11.h"

float getTemp() {
  int readData = DHT.read11(DHT11_PIN);
  float temperature = DHT.temperature;

  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  return temperature;
}

float getHum() {
  int readData = DHT.read11(DHT11_PIN);
  float humidity = DHT.humidity;

  Serial.print("Humidity: ");
  Serial.println(humidity);
  return humidity;
}

float* getTempAndHum() {
  int readData = DHT.read11(DHT11_PIN);
  float *data = malloc(sizeof(float)* 2 + 1);
  data[0] = DHT.temperature;
  data[1] = DHT.humidity;
  
  Serial.print("Temperature: ");
  Serial.println(data[0]);
  Serial.print("Humidity: ");
  Serial.println(data[1]);
  return data;
}
