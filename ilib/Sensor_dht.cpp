#include "Sensor_dht.h"  
#include "..\estructuras.h"	// Estructuras de datos.
#include <Arduino.h>		// STD de arduino.
#include "..\configurations.h" // Guarda los datos por defecto del equipo.
#include "Debug.h"			// Necesario para las llamadas de depuración.

Sensor_dht_::Sensor_dht_(uint8_t _HTINTPIN, uint8_t _HTINTTYPE) : Sensor_Raw(_HTINTPIN, _HTINTTYPE)
{
    DHT *TMPSens = &Sensor_Raw;
    sensorMillis.lastmillis = 0;
}

Sensor_dht_::~Sensor_dht_()
{

}
_ISensor Sensor_dht_::GetSensor()
{
    UpdateSensor();
    datos_sensores AmbienteTemporal;
    AmbienteTemporal = GetSensorDHT(TMPSens);
    _ISensor Tmp;
    Tmp.TipoSensor = _DHT22;
    Tmp.ValorSensor = AmbienteTemporal;
    return Tmp;
}
datos_sensores Sensor_dht_::GetSensorDHT(DHT *Sensor)
{
    datos_sensores AmbienteTemporal;
    unsigned long periodoActual;
    periodoActual = DHT_TIEMPO_MEDIDAS;
    sensorMillis.currentmillis = millis();

    if (sensorMillis.currentmillis - sensorMillis.lastmillis >= periodoActual) // Ejecutar solo si han pasado mas de period.
    {
        AmbienteTemporal.temperatura = Sensor->readTemperature();
        AmbienteTemporal.humedad = Sensor->readHumidity();
    }
    sensorMillis.lastmillis = millis();
    return AmbienteTemporal;
}
void Sensor_dht_::UpdateSensor()
{
    GetSensorDHT(TMPSens);
}