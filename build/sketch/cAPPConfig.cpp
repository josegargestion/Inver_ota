#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\cAPPConfig.cpp"
#include "EEPROM.h"
#include "configurations.h" // Guarda los datos por defecto del equipo.
#include "Debug.h"          // Necesario para las llamadas de depuración.
#include "lib\DHT.h"        // Control sensores DHT.
#include <TimeLib.h>
#include "hal\hal.h" // Abstraccion de hardware.
#include "estructuras.h"
#include "cAPPconfig.h"
#include <Arduino.h> // STD de arduino.

void cAppConfig::begin()
{
    DTIME;
    DPRINTLN(F(" Inicializando configApp1."));
    if (!configLoad())
    {
        DTIME;
        DPRINTLN(F(" Configuración no encontrada, se carga configuracion por defecto."));
        configDefault();
        configSave();
    }
}
void cAppConfig::configDefault()
{
    _D.signature[0] = EEPROM_SIG[0];
    _D.signature[1] = EEPROM_SIG[1];
    _D.version = CONFIG_VERSION;
    _D.delaySelect = SELECT_DELAY_DEFAULT;
    _D.lastSlotID = LAST_SLOT_DEFAULT;
    _D.OnMinuto = _DEFECTO_MINUTO_ON;
    _D.OnHora = _DEFECTO_HORA_ON;
    _D.OffMinuto = _DEFECTO_MINUTO_OFF;
    _D.OffHora = _DEFECTO_HORA_OFF;
    _D.OnTemp = _DEFECTO_TEMP_ON;
    _D.OffTemp = _DEFECTO_TEMP_OFF;
    _D.OnHr = _DEFECTO_HR_ON;
    _D.OffHr = _DEFECTO_HR_OFF;
    _D.SetHOn.Hora = _DEFECTO_HORA_ON;                       // Hora encendido.
    _D.SetHOn.Minuto = _DEFECTO_MINUTO_ON;                   // Hora encendido.
    _D.SetHOff.Hora = _DEFECTO_HORA_OFF;                     // Hora apagado.
    _D.SetHOff.Minuto = _DEFECTO_MINUTO_OFF;                 // Hora apagado.
    _D.SetAOn.set.Hora = _DEFECTO_HORA_ON;                   // Temperatura / humedad arranque.
    _D.SetAOn.set.Minuto = _DEFECTO_MINUTO_ON;               // Temperatura / humedad arranque.
    _D.SetAOn.AmbienteHora.humedad = _DEFECTO_HR_ON;         // Temperatura / humedad arranque.
    _D.SetAOn.AmbienteHora.temperatura = _DEFECTO_TEMP_ON;   // Temperatura / humedad arranque.
    _D.SetAOff.set.Hora = _DEFECTO_HR_OFF;                   // Temperatura / humedad arranque.
    _D.SetAOff.set.Minuto = _DEFECTO_MINUTO_OFF;             // Temperatura / humedad arranque.
    _D.SetAOff.AmbienteHora.humedad = _DEFECTO_HR_OFF;       // Temperatura / humedad arranque.
    _D.SetAOff.AmbienteHora.temperatura = _DEFECTO_TEMP_OFF; // Temperatura / humedad arranque.
#if (INV_DEPOSITO != ANULAR)
    _D.TCalibracionBomba = _CalibracionBomba;
    _D.CalBomba = _CalBomba;
    _D.CalValvula = _CalValvula;
    _D.TCalibracionValvula = _CalibracionValvula;
#endif
}
/**
 * @brief Carga la configuracion desde la EEPROM
 *
 * @return true Operacion correcta.
 * @return false La version no coincide, si hay datos para actualizar, actualiza (si actualiza cambiar return a true).
 */
bool cAppConfig::configLoad()
{
    EEPROM.get(EEPROM_ADDR, _D);
    if (_D.signature[0] != EEPROM_SIG[0] &&
        _D.signature[1] != EEPROM_SIG[1])
        return (false);
    // handle any version adjustments here
    if (_D.version != CONFIG_VERSION)
    {
        // do something here
    }

    // update version number to current
    _D.version = CONFIG_VERSION;

    return (true);
}
/**
 * @brief Gurada la confiiguracion en la EEPROM
 *
 * @return true Operacion correcta.
 * @return false Error de algun tipo.
 */
bool cAppConfig::configSave()
{
    EEPROM.put(EEPROM_ADDR, _D);
    return (true);
}
uint16_t cAppConfig::getSelectDelay()
{
    return (_D.delaySelect);
};
void cAppConfig::setSelectDelay(uint16_t n)
{
    _D.delaySelect = n;
};
uint16_t cAppConfig::getLastSlot()
{
    return (_D.lastSlotID);
};
void cAppConfig::setLastSlot(uint16_t n)
{
    _D.lastSlotID = n;
};
