#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\ambiente.h"
#ifndef AMBIENTE_H
#define AMBIENTE_H
#include "estructuras.h"
/**
 * @brief Controlar el sistema ambiental.
 * Clase maestra del sistema de control ambiente :
 * - Gestiona la humedad y temperatura en funcion de un set
 * - Proporciona dos Set de opciones parra encendido y apagado.
 * - Funciones para encender y apagar el sistema, asi como para ver su estado.
 * - Una funcion para controlar el sistema automaticamente en base a los datos guardados.
 *
 * @attention Para configurar requiere definir definir :
 * @attention - const int _PinDeshumidificador	Pin de activacion del deshumidificador.
 * @attention - const int _PinHumidificador		Pin de activacion del humidificador.
 * @attention - const int _PinExtractor			Pin de activacion del extractor.
 * @attention - const int _PinCalefaccion		Pin de activacion de la calefaccion.
 * @attention - const int _PinImpulsor			Pin de activacion del impulsor.
 * @attention - const uint8_t _HTINTPIN				Pin del sensor de temp - humedad interior.
 * @attention - const uint8_t _HTEXTPIN				Pin del sensor de temp - humedad exterior.
 * @attention - const uint8_t _HTINTTYPE DHT22		Tipo de sensor interior (DHT22 por defecto).
 * @attention - const uint8_t _HTEXTTYPE DHT22		Tipo de sensor exterior (DHT22 por defecto).
 *
 * @attention Para inicializar:
 * @attention - Ambiente Ambiente1;
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 * @todo - Comprobacion de funcionamiento.
 * @todo - Controles individuales de cada subsistema.
 * @todo - Modificar el sistema para limitarse a llevar el ambiente a un set sin horario.
 *
 */
class Ambiente
{
public:
	/**
	 * @brief Variable de horario.
	 *
	 */
	set_Ambiente setOn, setOff;
	datos_sensores dataAmbiente;
	/**
	 * @brief Constructor de clase.
	 *
	 */
	Ambiente();
	/**
	 * @brief Control de Ambiente.
	 *
	 */
	void Control();
	/**
	 * @brief Inicializador de hardware.
	 *
	 */
	void begin();
private:
	millis_set ambienteMillis, sensorExteriorMillis, sensorInteriorMillis;
	/**
	 * @brief LLama a los elementos de control configurando al estado enviado.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void CallControls(bool estado);
	/**
	 * @brief Controla el sistema de calefaccion para llegar a los parametros enviados.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void ControlCalefaccion(set_Ambiente set);
	/**
	 * @brief Controla el sistema de humidificacion para llegar a los parametros enviados.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void ControlHumidificador(set_Ambiente set);
	/**
	 * @brief Controla el sistema de des-humidificacion.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void ControlDeshumidificador(set_Ambiente set);
	/**
	 * @brief Controla el sistema de extraccion.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void ControlExtractor(set_Ambiente set);
	/**
	 * @brief Controla el sistema de impulsion.
	 *
	 * @param set Envia los parametros a configurar.
	 */
	void ControlImpulsor(set_Ambiente set);
};
#endif