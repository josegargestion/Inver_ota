#pragma once
#ifndef ARDUINO_SENSOR_DHT_H
#define ARDUINO_SENSOR_DHT_H
#include <Arduino.h>
#include "..\lib\DHT.h"
#include "ISensor.h"

class Sensor_dht_ : public ISensor
{
private:
	DHT Sensor_Raw;
	DHT *TMPSens;
	datos_sensores GetSensorDHT(DHT *TMPSens);
	millis_set sensorMillis;

public:
	_ISensor GetSensor() override;
	void UpdateSensor() override;
	Sensor_dht_(uint8_t _HTINTPIN, uint8_t _HTINTTYPE);
	~Sensor_dht_();
};
#endif
