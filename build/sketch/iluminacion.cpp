#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\iluminacion.cpp"
/**
 * @file iluminacion.cpp
 * @brief Codigo de la biblioteca iluminacion.h
 *
 * @author Jose Luis Garcia Lopez (josegar1980@gmail.com)
 * @version 0.5.0
 * @date 2022-06-23
 * @copyright Copyright (c) 2021
 *
 */
#include "iluminacion.h"
#include "configurations.h" // Guarda los datos por defecto del equipo.
#include "hardware.h"       // Funciones independientes del hardware.
#include "Debug.h"          // Necesario para las llamadas de depuración.
#include <TimeLib.h>
#include "CTiempos.h" // Personal de control de tiempos del procesador y horarios.
extern Control_Tiempos Horario1;
extern Hardware Sistema1;
Iluminacion::Iluminacion()
{
    lamparaMillis.currentmillis = 0;                              // Lectura actual de ejecucion.
    lamparaMillis.lastmillis = 0;                                 // Tiempo de la ultima ejecucion.
    lamparaMillis.period = _DEFECTO_PERIODO;                      // Lapso de tiempo entre ejecuciones, defecto _DEFECTO_PERIODO
}
void Iluminacion::begin()
{
    DTIME;
    DPRINTLN(F(" Incializando Iluminacion."));
    configLampara.EstLampara = Sistema1.GetEstadoIluminacion();
}
void Iluminacion::Control()
{
    DTIME;
    DPRINTLN(F(" Ejecutando Control de Iluminacion."));
    lamparaMillis.currentmillis = millis();
    if (lamparaMillis.currentmillis - lamparaMillis.lastmillis >= lamparaMillis.period)
    {
        ControlLampara(Horario1.ControlOnOff(Horario1.setOn, Horario1.setOff));
        lamparaMillis.lastmillis = millis();
    }
}
void Iluminacion::ControlLampara(bool estado)
{
    configLampara.EstLampara = Sistema1.GetEstadoIluminacion();
    if ((estado == true) && (configLampara.EstLampara == false)) // Si esta apagada la enciende.
    {
        Sistema1.EncenderIluminacion();
    }
    else if ((estado == false) && (configLampara.EstLampara == true)) // Si esta encendida la apaga.
    {
        Sistema1.ApagarIluminacion();
    }
    configLampara.EstLampara = Sistema1.GetEstadoIluminacion();
}

