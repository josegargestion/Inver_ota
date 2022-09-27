#ifndef ILUMINACION_H
#define ILUMINACION_H
#include "estructuras.h"
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
	 * @brief Estructura que controla la clase.
	 *
	 */
	config_Lampara configLampara;
};
#endif
