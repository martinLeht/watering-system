#ifndef _DHT11_H
#define _DHT11_H

#include <dht.h>

extern dht DHT;

#define DHT11_PIN 7

float getTemp();
float getHum();
float* getTempAndHum();

#endif _DHT11_H
