/**
 * @file hal\MC23008.h
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @brief Archivo configuracion placa Arduino Nano
 * @version 0.5.0
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>		// STD de arduino.
#include "..\configurations.h"
#ifndef MC23008_H
#define MC23008_H

#if (INV_EXPANSORES == C_MC23008_)

#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP23XXX.h>

// Configuracion de pines
const int _pinControlSondaMaximo = 12; // 22
const int _pinControlSondaMinimo = 11; // 21
const int _pinControlBomba = 10;
const uint8_t _HTINTPIN = 10;
const uint8_t _HTEXTPIN = 8;
const int _pinControlValvula = 7;
const int _DHTPIN = 8;
const int _pinControlDeshumidificador = 1;
const int _pinControlHumidificador = 2;
const int _pinControlExtractor = 3;
const int _pinControlCalefaccion = 4;
const int _pinControlImpulsor = 6;
const int _pinControlLampara = 7;
const int _SDA = 23;
const int _SCL = 24;

#endif

#endif
