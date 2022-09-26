#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\deposito.h"
/**
 * @brief Control de deposito con vaciado automatico.
 * Esta libreria emplea dos entradas digitales y una salida digital para controlar un deposito de liquidos y una bomba
 * que lo mantiene entre el maximo y el minimo, vaciandolo o rellenandolo cuando sea preciso.
 *
 * @attention Para configurar requiere definir :
 * @attention - const int _SONDAMAXIMO	Pin de la sonda de maximo.
 * @attention - const int _SONDAMINIMO	Pin de la sonda de minimo.
 * @attention - const int _BOMBA		Pin del Rele de activacion de la bomba.
 * @attention - const int _VALVULA		Pin del rele de activacion de la valvula.
 * @attention En el Main inicializar con :
 * @attention - Deposito Deposito_name;
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 * @todo	- Comprobación del sistema para controlar errores del sensor.
 * */
#ifndef DEPOSITO_H
#define DEPOSITO_H
#include "estructuras.h"
class Deposito
{
private:
	/**
	 * @brief Variable que contendra los datos de configuracion.
	 *
	 */
	estado_Deposito estadoDeposito;
	/**
	 * @brief Enciende o apaga el sistema de vaciado del deposito.
	 *
	 * @param estado ON = encendio , OFF = apagado.
	 */
	void Vaciado(bool estado);
	/**
	 * @brief Enciende o apaga el sistema de llenado del deposito.
	 *
	 * @param estado ON = encendido , OFF = apagado.
	 */
	void LLenado(bool estado);
	/**
	 * @brief Variables para controlar el tiempo de ejecucion del hilo principal.
	 *
	 */
	millis_set depositoMillis;
	/**
	 * @brief Actualiza estadoDeposito.SensorMax y estadoDeposito.SensorMin.
	 *
	 */
	void UpdateSondas();
public:
	/**
	 * @brief Estructura que almacena los datos publicos.
	 *
	 * @param pinValvula Pin de marcha / paro de la valvula
	 * @param pinBomba Pin de marcha / paro de la bomba.
	 * @param pinSondaMaximo Pin desde el que leer la sonda de maximo.
	 * @param pinSondaMinimo Pin desde el que leer la sonda de manimo.
	 */
	struct cal_Deposito
	{
		bool CalBomba;					   // Calibracion realizada.
		unsigned long TCalibracionBomba;   // Tiempo de calibracion de la bomba.
		unsigned long TCalibracionValvula; // Tiempo de calibracion de la valvula.
		bool CalValvula;				   // Calibracion realizada.
	};
	cal_Deposito configDeposito;
	/**
	 * @brief Construct a new Deposito:: Deposito object
	 *
	 */
	Deposito();
	/**
	 * @brief Inicializador del hardware.
	 *
	 */
	void begin();
	/**
	 * @brief Control automatico del deposito.
	 *
	 */
	void Control();
};
#endif