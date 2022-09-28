#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\hal\\nano.h"
/**
 * @file hal\nano.h
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @brief Archivo configuracion placa Arduino Nano
 * @version 0.5.0
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h> // STD de arduino.
#include "..\configurations.h"
#ifndef NANO_H
#define NANO_H

#if (INV_BOARD == C_NANO_)
#include <pins_arduino.h>
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
const int _SDA = SDA;
const int _SCL = SCL;
#endif

#endif
