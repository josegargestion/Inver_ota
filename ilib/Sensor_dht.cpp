#include "Sensor_dht.h"  
#include "..\estructuras.h"	// Estructuras de datos.
#include <Arduino.h>		// STD de arduino.
#include "..\configurations.h" // Guarda los datos por defecto del equipo.
#include "Debug.h"			// Necesario para las llamadas de depuración.
Sensor_dht::Sensor_dht(uint8_t _HTINTPIN, uint8_t _HTINTTYPE) : sondaDHT(_HTINTPIN, _HTINTTYPE)
{

}

Sensor_dht::~Sensor_dht()
{

}
datos_sensores Sensor_dht::GetSensor(DHT sondaDHT)
{
    datos_sensores AmbienteTemporal;
    millis_set sensorMillis;
    sensorMillis.lastmillis = 0;
    unsigned long periodoActual;
    periodoActual = DHT_TIEMPO_MEDIDAS;
    sensorMillis.currentmillis = millis();

    if (sensorMillis.currentmillis - sensorMillis.lastmillis >= periodoActual) // Ejecutar solo si han pasado mas de period.
    {
        AmbienteTemporal.temperatura = sondaDHT.readTemperature();
        AmbienteTemporal.humedad = sondaDHT.readHumidity();
    }
    sensorMillis.lastmillis = millis();
    return AmbienteTemporal;
}