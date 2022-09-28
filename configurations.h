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
#include "definiciones.h"
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

/**
 * @brief Configuracion de placa, opciones :
 * 
 * C_NANO_ , C_ESP8266_, C_ESP32WROOM_
 * 
 */
#define INV_BOARD  C_ESP8266_
/**
 * @brief Cargar expansores I/O, opciones :
 * C_MC23008_ , C_S74HCXX_
 * 
 */
#define INV_EXPANSORES  ANULAR
/**
 * @brief Cargar modulo de deposito, opciones :
 * C_NODEPOSITO_ , C_DEPOSITO_2_SONDAS_ , C_DEPOSITO_3_SONDAS_ , C_DEPOSITO_ESTATICO_  
 * 
 */
#define INV_DEPOSITO  C_NODEPOSITO_// Desactiva el deposito.
/**
 * @brief Configurar sensores, opciones :
 * C_SENSOR_INTERIOR_ , C_SENSOR_INTERIOR_Y_EXTERIOR
 */ 
#define INV_SENSORES  C_SENSOR_INTERIOR_
/**
 * @brief Configurar RTC , opciones :
 * C_RTC_ , C_RELOJI2C_ , C_DS1307RTC_
 * 
 */
#define INV_RELOJ  ANULAR
/**
 * @brief Configurar pantalla
 */
#define INV_PANTALLA  ANULAR
#include "hal\hal.h"
#endif
