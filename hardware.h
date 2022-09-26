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

#include "lib\DHT.h"			// Control sensores DHT.
#include "estructuras.h"	// Estructuras de datos.
#include <Arduino.h>		// STD de arduino.
#include "configurations.h" // Guarda los datos por defecto del equipo.
#include "Debug.h"			// Necesario para las llamadas de depuración.
#include "cAPPconfig.h"		// Guardado de datos a EEPROM.
class Hardware
{
public:
	static estado_Hardware estadoHardware;
	/**
	 * @brief Construct a new Hardware object.
	 *
	 */
	Hardware();
	/**
	 * @brief Inicializador del hardware.
	 *
	 */
	void begin();
	/**
	 * @brief Estado de la Hardware.
	 *
	 * @return true Encendia
	 * @return false Apagada
	 */
	static bool GetEstado();
	/**
	 * @brief Gestion automatica de la iluminación, para controlar desde la aplicacion principal.
	 *
	 */
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
	/**
	 * @brief Sensor Interior.
	 *
	 */
	DHT sondaInterior;
	/**
	 * @brief Sensor Exterior.
	 *
	 */
	DHT sondaExterior;
	/**
	 * @brief Get the Sensor Exterior object
	 *
	 */
	datos_sensores GetSensor(DHT Sensor);
	static millis_set hardwareMillis;
};
#endif
