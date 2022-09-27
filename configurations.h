/**
 * @file configurations.h
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @brief Archivo de definiciones para la configuracion inicial del sistema.
 * @version 0.5.0
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h> // STD de arduino.
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

/* Opciones de selección de MCU. */
//#define C_NANO_ // Activa compilación para nano usando pines sin expansores.
#define C_ESP8266_ // Activa compatibilidad con esp8266
//#define C_ESP32WROOM_ // Activa compatibilidad con ESP32

/* Opciones de selección de expansores I/O. */
//#define C_S74HCXX_ // Activa la compilacion usando expansores 74hc595 y 74hc165.
//#define C_MC23008_ // Activa la compilacion usando expansores MC23008.

/* Opciones de selección de deposito */
#define NODEPOSITO // Desactiva el deposito.
//#define DEPOSITO_2_SONDAS // Deposito de 2 sondas ( Max y Min).
//#define DEPOSITO_3_SONDAS // Deposito de 3 sondas (Max Med y Min).
//#define DEPOSITO_SOLO_VACIADO // Deposito con bomba o valvula de vaciado.
//#define DEPOSITO_SOLO_LLENADO // Deposito con bomba o valvula de llenado.
//#define DEPOSITO_ESTATICO // Deposito que se mantiene en nivel Medio (3 sondas).

/* Sensores de temperatura - humedad */
//#define SENSOR_INTERIOR_Y_EXTERIOR
#define SENSOR_INTERIOR

/* Opciones de selección de Reloj. */
//#define C_RTC_ // Activa opciones de reloj de tiempo real.
//#define C_RELOJI2C_ // Activa el reloj I2C
//#define C_DS1307RTC_ // Configuracion para Reloj DS1307RTC por I2C

/* Opciones de selección de pantalla. */
//#define C_LCD_ // Activa opciones de pantalla LCD
#include "hal\hal.h"
#endif
