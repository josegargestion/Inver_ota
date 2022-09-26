#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\ambiente.cpp"
/**
 * @file ambiente.cpp
 * @brief Codigo de la biblioteca ambiente.h
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 *
 */
#include "configurations.h" // Guarda los datos por defecto del equipo.
#include "lib\DHT.h"        // Control sensores DHT.
#include "Debug.h"          // Necesario para las llamadas de depuración.
#include <TimeLib.h>
//#include <time.h>
#include "hardware.h"    // Clase de control del hardware.
#include "ambiente.h"    // Control del ambiente.
#include "Iluminacion.h" // Control iluminación.
#include "debug.h"       // Necesario para las llamadas de depuración.
#include "CTiempos.h"    // Clase de control de horarios.
#include <Arduino.h>     // STD de arduino.
extern Control_Tiempos Horario1;
extern Hardware Sistema1;
Ambiente::Ambiente()
{
    ambienteMillis.lastmillis = 0;
}
void Ambiente::begin()
{
    DTIME;
    DPRINTLN(F(" Inicializando Ambiente."));
}
void Ambiente::Control()
{
    DTIME;
    DPRINTLN(F(" Ejecutando Control de Ambiente."));
    ambienteMillis.currentmillis = millis();
    if (ambienteMillis.currentmillis - ambienteMillis.lastmillis >= ambienteMillis.period) // Ejecutar solo si han pasado mas de period.
    {
        CallControls(Horario1.ControlOnOff(Horario1.setAOn, Horario1.setAOff));
        ambienteMillis.lastmillis = millis();
    }
}
void Ambiente::CallControls(bool estado) // LLamada a los elementos de control asignando parametros.
{
    Sistema1.GetSensores();
    if (estado)
    {
        ControlCalefaccion(setOn);
        ControlHumidificador(setOn);
        ControlDeshumidificador(setOn);
        ControlExtractor(setOn);
        ControlImpulsor(setOn);
    }
    else if (!estado)
    {
        ControlCalefaccion(setOff);
        ControlHumidificador(setOff);
        ControlDeshumidificador(setOff);
        ControlExtractor(setOff);
        ControlImpulsor(setOff);
    }
}
void Ambiente::ControlCalefaccion(set_Ambiente set) // Control de la calefaccion.
{
}
void Ambiente::ControlHumidificador(set_Ambiente set) // Control del sistema de humidificacion.
{
}
void Ambiente::ControlDeshumidificador(set_Ambiente set) // Control del sistema de des-humidificacion.
{
}
void Ambiente::ControlExtractor(set_Ambiente set) // Control del sistema de extraccion.
{
}
void Ambiente::ControlImpulsor(set_Ambiente set) // Control del sistema de impulsion.
{
}
