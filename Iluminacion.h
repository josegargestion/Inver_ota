#ifndef ILUMINACION_H
#define ILUMINACION_H
#include "estructuras.h"

/**
 * @brief Controlar el encendido apagado de los equipos de control de iluminacion acorde a los valores objetivo.
 * Clase maestra del sistema de control de iluminacion, tiene las siguientes funciones:
 * - dos estructuras para fijar el horario de encendido y apagado.
 * - una estructura para las variables de configuracion de la clase.
 * - funciones para encender y apagar el sistema, asi como para ver su estado.
 * - una funcion para controlar el sistema automaticamente en base a los datos guardados.
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 * @todo
 * @todo - Comprobacion de funcionamiento.
 * @todo - Eliminar codigo de depuracion.
 *
 */
class Iluminacion
{
public:
	/**
	 * @brief Construct a new Iluminacion object.
	 *
	 */
	Iluminacion();
	/**
	 * @brief Inicializador del hardware.
	 *
	 */
	void begin();
	/**
	 * @brief Gestion automatica de la iluminación, para controlar desde la aplicacion principal.
	 *
	 */
	void Control();

private:
	millis_set lamparaMillis;
	/**
	 * @brief Funcion para controlar la lampara en general.
	 *
	 * @param estado True = encendida, False = apagada.
	 */
	void ControlLampara(bool estado);
	/**
	 * @brief Variables de configuracion de la clase.
	 *
	 * @param pinLampara Pin asignado a activar la lampara fisicamente en el arduino, envia señal HIGH para activar.
	 * @param EstLampara Estado de la lampara true = encendida.
	 */
	struct config_Lampara
	{
		bool EstLampara; // Estado de la lampara true = encendida.
	};
	/**
	 * @brief Estructura que controla la clase.
	 *
	 */
	config_Lampara configLampara;
};
#endif
