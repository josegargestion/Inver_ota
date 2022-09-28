/**
 * @file invernadero.cpp
 * @brief Codigo de la biblioteca invernadero.h
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 */
#include "configurations.h" // Guarda los datos de configuracion del equipo.
#include "cAPPconfig.h"     // Guardado de datos a EEPROM.
#include "Debug.h"          // Necesario para las llamadas de depuración.
#include <TimeLib.h>        // Funciones de control de tiempos.
#include "estructuras.h"    // Estructuras de datos.
#include "deposito.h"       // Control sistema de deposito de liquidos
#include "ambiente.h"       // Control del ambiente.
#include "invernadero.h"    // Clase maestra de control del sistema.
#include "hardware.h"       // Clase de control del hardware.
#include "CTiempos.h"       // Clase de control de horarios.
#include <Arduino.h>        // STD de arduino.
cAppConfig configApp1;
Control_Tiempos Horario1;
Hardware* Sistema = new Hardware;
#if (INV_DEPOSITO != ANULAR)
Deposito Deposito1;
#endif
Ambiente Ambiente1;
millis_set inverMillis;
Inver::Inver()
{
}
void Inver::begin()
{
  configApp1.begin();
  Horario1.SetTimeOn(configApp1._D.OnHora, configApp1._D.OnMinuto);
  Horario1.SetTimeOff(configApp1._D.OffHora, configApp1._D.OffMinuto);
  Sistema->begin();
  Ambiente1.begin();
#if (INV_DEPOSITO != ANULAR)
#ifdef DEBUG
  configApp1._D.CalBomba = true;
  configApp1._D.CalValvula = true;
#endif
  Deposito1.begin();
  if (configApp1._D.CalBomba && configApp1._D.CalValvula)
  {
    DTIME;
    DPRINTLN(F(" Cargando calibracion desde EEPROM."));
    Sistema.estadoHardware.CalBomba = configApp1._D.CalBomba;
    Sistema.estadoHardware.CalValvula = configApp1._D.CalValvula;
    Sistema.estadoHardware.TCalibracionBomba = configApp1._D.TCalibracionBomba;
    Sistema.estadoHardware.TCalibracionValvula = configApp1._D.TCalibracionValvula;
  }
  else
  {
    DTIME;
    DPRINTLN(F(" Generando nueva calibracion."));
    configData_t tempconfig;
    tempconfig = Sistema.SetCalibracion(configApp1._D);
    configApp1._D = tempconfig;
    DTIME;
    DPRINTLN(F(" Guardando calibracion en EEPROM."));
    configApp1.configSave();
  }
#endif
}
void Inver::Control()
{
  Sistema->Control();
  Ambiente1.Control();
#if (INV_DEPOSITO != ANULAR)
  Deposito1.Control();
#endif
}
