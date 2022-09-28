/**
 * @file hal\Relojes.h
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @brief Archivo configuracion placa Arduino Nano
 * @version 0.5.0
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RELOJES_H
#define RELOJES_H
#include "..\configurations.h"
#ifdef DS1307RTC
#include "DS1307RTC.h"      // Control del reloj RTC.
#define _RTC_ADD 0x68
#endif

#if (INV_RELOJ ==  C_RELOJI2C_)
#define _RTC_ADD 0x68
#endif

#endif
