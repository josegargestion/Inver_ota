#pragma once
#ifndef ARDUINO_SENSOR_DHT_H
#define ARDUINO_SENSOR_DHT_H
#include <Arduino.h>
#include <DHT.h>
#include "ISensor.h"

class Sensor_dht : public ISensor
{
private:
	DHT sondaDHT;
	datos_sensores GetSensor(DHT Sensor);

public:
	_Isensor GetSensor();
	void UpdateSensor();
	Sensor_dht(uint8_t _HTINTPIN, uint8_t _HTINTTYPE);
	~Sensor_dht();
};
#endif
