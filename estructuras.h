#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <Arduino.h>
/**
 * @brief Estructura de medicion de tiempos para comparaciones horarias.
 *
 * @param Hora Hora de inicio del periodo.
 * @param Minuto Minuto de inicio del periodo.
 *
 */
struct set_Horario
{
	uint8_t Hora;	// Hora de inicio del periodo.
	uint8_t Minuto; // Minuto de inicio del periodo.
};
/**
 * @brief Datos sensores DHT
 *
 * @param humedadInt Humedad interior.
 * @param temperaturaInt Temperatura interior.
 * @param humedadExt Humedad exterior.
 * @param temperaturaExt Temperatura exterior.
 *
 */
struct datos_sensores
{
	float humedad;	   // Humedad
	float temperatura; // Temperatura
};
/**
 * @brief Estructura que alverga los datos de temperatura y Humedad en funcion de la hora.
 * @param Hora Hora de comienzo.
 * @param Minuto Minuto de comienzo.
 * @param Temp Temperatura a mantener.
 * @param Hr Humedad a mantener.
 *
 */
struct set_Ambiente
{
	set_Horario set; // Valores horarios del set.
	datos_sensores AmbienteHora;
};
/**
 * @brief Estructura para controlar tiempos de ejecucion.
 *
 * @param currentmillis Lectura actual de ejecucion.
 * @param lastmillis Tiempo de la ultima ejecucion.
 * @param period	Lapso de tiempo entre ejecuciones, defecto _DEFECTO_PERIODO
 *
 */
struct millis_set
{
	unsigned long currentmillis; // Lectura actual de ejecucion.
	unsigned long lastmillis;	 // Tiempo de la ultima ejecucion.
	unsigned long period;		 // Lapso de tiempo entre ejecuciones, defecto _DEFECTO_PERIODO
};
struct config_Hardware
{
	/** Pines de estado **/
	int pinEstadoLampara;
	int pinEstadoValvula;		   // Pin de la electrovalvula.
	int pinEstadoBomba;			   // Pin de la bomba.
	int pinEstadoSondaMaximo;	   // Pin sonda de Maximo.
	int pinEstadoSondaMinimo;	   // Pin de la sonda de Minimo.
	int pinEstadoCalefaccion;	   // Pin que activa la calefaccion.
	int pinEstadoHumidificador;	   // Pin que activa el sistema de humidificacion.
	int pinEstadoDeshumidificador; // Pin que activa el sistema de des-humidificacion.
	int pinEstadoExtractor;		   // Pin que controla el sistema de extraccion.
	int pinEstadoImpulsor;		   // Pin que controla el sistema de impulsion.
	/** Pines de configuracion **/
	int pinControlLampara;
	int pinControlValvula;			// Pin de la electrovalvula.
	int pinControlBomba;			// Pin de la bomba.
	int pinControlSondaMaximo;		// Pin sonda de Maximo.
	int pinControlSondaMinimo;		// Pin de la sonda de Minimo.
	int pinControlCalefaccion;		// Pin que activa la calefaccion.
	int pinControlHumidificador;	// Pin que activa el sistema de humidificacion.
	int pinControlDeshumidificador; // Pin que activa el sistema de des-humidificacion.
	int pinControlExtractor;		// Pin que controla el sistema de extraccion.
	int pinControlImpulsor;			// Pin que controla el sistema de impulsion.
	/** Sensores ambiente **/
	uint8_t pinInt;	 // Pin del sensor interior.
	uint8_t typeInt; // Tipo de sensor interior.
	uint8_t pinExt;	 // Pin del sensor exterior.
	uint8_t typeExt; // Tipo de sensor exterior.
};
struct estado_Hardware
{

	bool EstadoLampara;
	bool EstadoSensorMax;			   // Estado sensor de maximo.
	bool EstadoSensorMin;			   // Estado sensor de minimo.
	bool EstadoBomba;				   // Estado de la bomba.
	bool EstadoValvula;				   // Estado de la electrovalvula.
	bool EstadoCalefaccion;			   // Estado calefaccion.
	bool EstadoHumidificador;		   // Estado del humidificador.
	bool EstadoDeshumidificador;	   // Estado del deshumidificador.
	bool EstadoExtractor;			   // Estado del extractor.
	bool EstadoImpulsor;			   // Estado del impulsor.
	bool CalValvula;				   // Calibracion realizada.
	bool CalBomba;					   // Calibracion realizada.
	unsigned long TCalibracionBomba;   // Tiempo de calibracion de la bomba.
	unsigned long TCalibracionValvula; // Tiempo de calibracion de la valvula.
	datos_sensores AmbienteInterno;
	datos_sensores AmbienteExterno;
};
/**
 * @brief Definir estructura de los datos a guardar en la EEPROM configData_t archivo estructuras.h .
 *
 * @struct configData_t archivo estructuras.h .
 */
struct configData_t
{
	uint8_t signature[2];			   // Firma para comprobacion.
	uint8_t version;				   // Version de datos.
	uint8_t OnMinuto;				   // Minuto encendido.
	uint8_t OnHora;					   // Hora encendido.
	float OnTemp;					   // Temperatura encendido.
	float OnHr;						   // Humedad encendido.
	set_Horario SetHOn;				   // Hora encendido.
	set_Horario SetHOff;			   // Hora apagado.
	set_Ambiente SetAOn;			   // Temperatura / humedad arranque.
	set_Ambiente SetAOff;			   // Temperatura y humedad arranque.
	uint8_t OffMinuto;				   // Minuto apagado.
	uint8_t OffHora;				   // Hora apagado.
	float OffTemp;					   // Temperatura apagado.
	float OffHr;					   // Humedad apagado.
	unsigned long TCalibracionBomba;   // Tiempo de calibracion de la bomba.
	bool CalBomba;					   // Calibracion realizada.
	unsigned long TCalibracionValvula; // Tiempo de calibracion de la valvula.
	bool CalValvula;				   // Calibracion realizada.
	uint16_t delaySelect;			   // Auxiliar de tiempos.
	uint16_t lastSlotID;			   // Ultima casilla usada.
};
struct config_Deposito
{
	/** Pines de estado **/
	int pinEstadoValvula;		   // Pin de la electrovalvula.
	int pinEstadoBomba;			   // Pin de la bomba.
	int pinEstadoSondaMaximo;	   // Pin sonda de Maximo.
	int pinEstadoSondaMinimo;	   // Pin de la sonda de Minimo.
	/** Pines de configuracion **/
	int pinControlValvula;			// Pin de la electrovalvula.
	int pinControlBomba;			// Pin de la bomba.
	int pinControlSondaMaximo;		// Pin sonda de Maximo.
	int pinControlSondaMinimo;		// Pin de la sonda de Minimo.

};
struct estado_Deposito
{
	bool EstadoSensorMax;			   // Estado sensor de maximo.
	bool EstadoSensorMin;			   // Estado sensor de minimo.
	bool EstadoBomba;				   // Estado de la bomba.
	bool EstadoValvula;				   // Estado de la electrovalvula.
};
enum _TSensores
{
	_DHT11, _DHT22, _Temperatura, _Humedad, _Binario 
};
struct _Isensores
{
	_TSensores TipoSensor;
};
#endif
