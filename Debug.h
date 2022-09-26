#pragma once
/**
 * @brief Macros para poner mensajes de depuracion por serial.
 * 
 * @author Josegar1908@gmail.com
 * @version 0.0.3
 * 
 * @todo - Construccion de funciones de depuracion.
 * 
 */
#include <TimeLib.h>
#include "CTiempos.h"
#include "configurations.h"    // Necesario para las llamadas de depuración.
#include <Arduino.h>		// STD de arduino.
#ifndef DEBUG_H
#define DEBUG_H
#define DPRINTER Serial
#ifndef DEBUG
#define DEBUG
#endif
extern Control_Tiempos Horario1;
/**
 * @brief Definimos las macros si esta DEBUG activo.
 * 
 */
#ifdef DEBUG
  #define DTIME { Horario1.hora_detalle(); }
  #define DPRINT(...) { DPRINTER.print(__VA_ARGS__); }
  #define DPRINTLN(...) { DPRINTER.println(__VA_ARGS__); }
#else
  #define DTIME {}
  #define DPRINT(...) {}
  #define DPRINTLN(...) {}
#endif

#endif 