/**
 * @brief Funciones de la capa de abstraccion de hardware.
 * Esta libreria contiene las funciones referentes al hardware del sistema, para hacer
 * que el programa funcione sin teenr en cuenta factores como los pines de entrada
 * o la configuracion de sensores.
 * que lo mantiene entre el maximo y el minimo, vaciandolo o rellenandolo cuando sea preciso.
 *
 * @author Josegar1908@gmail.com
 * @version 0.0.0
 *
 * @todo	- Comprobación del sistema.
 * @copyright Copyright (c) 2021
 */
#ifndef HARDWARE_H
#define HARDWARE_H

#include "lib\DHT.h"		// Control sensores DHT.
#include "estructuras.h"	// Estructuras de datos.
#include <Arduino.h>		// STD de arduino.
#include "configurations.h" // Guarda los datos por defecto del equipo.
#include "Debug.h"			// Necesario para las llamadas de depuración.
#include "cAPPconfig.h"		// Guardado de datos a EEPROM.
#include "ilib\ISensor.h"
#include "ilib\Sensor_dht.h"
class Hardware
{
public:
	static estado_Hardware estadoHardware;
	Hardware();
	void begin();
	static bool GetEstado();
	static void Control();
	static bool GetEstadoIluminacion();
	static bool GetEstadoBomba();
	static bool GetEstadoValvula();
	static bool GetSondaMaximo();
	static bool GetSondaMinimo();
	static void UpdateSondas();
	static void ControlErrorDeposito();
	static void EncenderValvula();
	static void EncenderBomba();
	static void EncenderIluminacion();
	static void EncenderCalefaccion();
	static void EncenderHumidificador();
	static void EncenderDeshumidificador();
	static void EncenderExtractor();
	static void EncenderImpulsor();
	static void ApagarCalefaccion();
	static void ApagarHumidificador();
	static void ApagarDeshumidificador();
	static void ApagarExtractor();
	static void ApagarImpulsor();
	static void ApagarIluminacion();
	static void ApagarValvula();
	static void ApagarBomba();
	static unsigned long GetCalibracionBomba();
	static unsigned long GetCalibracionValvula();
	static configData_t SetCalibracion(configData_t configAPP);
	void GetSensores();

private:
	static config_Hardware configHardware;
#if (INV_SENSORES == C_SENSOR_INTERIOR_)
	/**
	 * @brief Sensor Interior.
	 *
	 */
	//DHT sondaInterior;
#elif (INV_SENSORES == C_SENSOR_INTERIOR_Y_EXTERIOR_)
	/**
	 * @brief Sensor Exterior.
	 *
	 */
	DHT sondaExterior;
#endif
	/**
	 * @brief Get the Sensor Exterior object
	 *
	 */
	datos_sensores GetSensor(DHT Sensor);
	static millis_set hardwareMillis;
};
#endif
