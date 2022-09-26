#ifndef CAPPCONFIG_H
#define CAPPCONFIG_H
#include <EEPROM.h>
#include "estructuras.h"
#include <Arduino.h>		// STD de arduino.
/**
 * @brief Guarda los parametros de configuracion y/o datos que queramos conservar al arranque.
 * Tiene las siguientes funciones:
 * - una estructuraque almacena los datos a salvar en la EEPROM.
 * - funciones para guardar y cargar la EEPROM.
 * - funcion para inicializar la EEPROM al arranque y cargar valores por defecto sino los hay.
 *
 * @attention Para inicializar:
 * @attention cAppConfig configApp;
 * @attention
 * @attention Se deben de definir los parametros a salvar y cargarlos.
 *
 *
 * @author Josegar1908@gmail.com
 * @version 0.0.3
 *
 *
 */
class cAppConfig
{
public:
    configData_t _D;
    uint16_t getSelectDelay();
    void setSelectDelay(uint16_t n);
    uint16_t getLastSlot();
    void setLastSlot(uint16_t n);
    /**
     * @brief Inicializador del sistema.
     * Comprueba si existe una configuracion guardada y la carga.
     * Si no existe una configuracion valida carga los datos por defecto.
     *
     */
    void begin();
    /**
     * @brief Configura los datos por defecto.
     *
     */
    void configDefault();
    /**
     * @brief Carga la configuracion desde la EEPROM
     *
     * @return true Operacion correcta.
     * @return false La version no coincide, si hay datos para actualizar, actualiza (si actualiza cambiar return a true).
     */
    bool configLoad();
    /**
     * @brief Gurada la confiiguracion en la EEPROM
     *
     * @return true Operacion correcta.
     * @return false Error de algun tipo.
     */
    bool configSave();
};
#endif
