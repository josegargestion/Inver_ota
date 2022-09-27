#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\CTiempos.h"
/**
 * 
 * @brief Controles para gestion de tiempos.
 * @file CTiempos.h Biblioteca de control de tiempos.
 * Clase maestra del sistema de control de tiempos, tiene las siguientes funciones:
 * - Estructura que define las horas y minutos de los periodos.
 * - Funcion para fijar tiempo de encendido.
 * - Funcion para fijar tiempo de apagado.
 * - una funcion para controlar el sistema automaticamente en base a los datos guardados.
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 * @todo - Comprobacion de funcionamiento.
 * @todo - Eliminar codigo de depuracion.
 *
 */
#ifndef CTIEMPOS_H
#define CTIEMPOS_H
#include <Arduino.h>		// STD de arduino.
#include "estructuras.h"
class Control_Tiempos
{
public:
	/**
	 *
	 * @brief Variables de horario.
	 *
	 */
	set_Horario setOn, setOff;
	set_Ambiente setAOn, setAOff;
	/**
	 * @brief Configura el tiempo de encendido
	 *
	 * @param Hora Hora de inicio del encendido.
	 * @param Minuto Minuto de inicio del encendido.
	 */
	void SetTimeOn(uint8_t Hora, uint8_t Minuto);
	/**
	 * @brief Configura el tiempo de encendido
	 *
	 * @param Hora Hora de inicio del encendido.
	 * @param Minuto Minuto de inicio del encendido.
	 * @param setOn Set a modificar.
	 */
	void SetTimeOn(uint8_t Hora, uint8_t Minuto, set_Horario& set);
	/**
	 * @brief Configura el tiempo de encendido
	 *
	 * @param Hora Hora de inicio del encendido.
	 * @param Minuto Minuto de inicio del encendido.
	 * @param Temp Temperatura durante este periodo.
	 * @param Hr Humedad durante este periodo.
	 */
	void SetTimeOn(uint8_t Hora, uint8_t Minuto, set_Ambiente& set);
	/**
	 * @brief Configura el tiempo de apagado.
	 *
	 * @param Hora Hora de inicio del apagado.
	 * @param Minuto Minutor de inicio del apagado.
	 */
	void SetTimeOff(uint8_t Hora, uint8_t Minuto);
	/**
	 * @brief Configura el tiempo de apagado.
	 *
	 * @param Hora Hora de inicio del apagado.
	 * @param Minuto Minutor de inicio del apagado.
	 * @param setOff Set a modificar.
	 */
	void SetTimeOff(uint8_t Hora, uint8_t Minuto, set_Horario& set);
	/**
	 * @brief Configura el tiempo de apagado.
	 *
	 * @param Hora Hora de inicio del apagado.
	 * @param Minuto Minutor de inicio del apagado.
	 * @param Temp Temperatura durante este perido.
	 * @param Hr Temperatura durante el periodo.
	 */
	void SetTimeOff(uint8_t Hora, uint8_t Minuto, set_Ambiente& set);
	/**
	 * @brief En funcion de setOn y setOff devuelve estado esperado en funcion del teimpo actual.
	 *
	 * @param setOn Hora y minuto de encendido.
	 * @param setOff Hora y minuto de apagado.
	 * @return true Encendido.
	 * @return false Apagado.
	 */
	bool ControlOnOff(set_Ambiente setAOn, set_Ambiente setAOff);
	bool ControlOnOff(set_Horario setAOn, set_Horario setAOff);
	void hora_detalle();
};
#endif