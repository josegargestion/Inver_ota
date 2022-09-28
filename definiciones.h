
#ifndef ARDUINO_DEFINICIONES_H
#define ARDUINO_DEFINICIONES_H

#define ANULAR 0
/* Opciones de selección de MCU. */
#define C_NANO_ 255		// Activa compilación para nano usando pines sin expansores.
#define C_ESP8266_ 254	// Activa compatibilidad con esp8266
#define C_ESP32WROOM_ 253 // Activa compatibilidad con ESP32

/* Opciones de selección de expansores I/O. */
#define C_S74HCXX_ 252 // Activa la compilacion usando expansores 74hc595 y 74hc165.
#define C_MC23008_ 251 // Activa la compilacion usando expansores MC23008.

/* Opciones de selección de deposito */
#define C_NODEPOSITO_ ANULAR		   // Desactiva el deposito.
#define C_DEPOSITO_2_SONDAS_ 249 // Deposito de 2 sondas ( Max y Min).
#define C_DEPOSITO_3_SONDAS_ 248 // Deposito de 3 sondas (Max Med y Min).
#define C_DEPOSITO_ESTATICO_ 247 // Deposito que se mantiene en nivel Medio (3 sondas).

/* Sensores de temperatura - humedad */
#define C_SENSOR_INTERIOR_Y_EXTERIOR_ 246
#define C_SENSOR_INTERIOR_ 245

/* Opciones de selección de Reloj. */
#define C_NORTC_ ANULAR
#define C_RTC_ 244	   // Activa opciones de reloj de tiempo real.
#define C_RELOJI2C_ 243  // Activa el reloj I2C
#define C_DS1307RTC_ 242 // Configuracion para Reloj DS1307RTC por I2C

/* Opciones de selección de pantalla. */
#define C_LCD_ 241 // Activa opciones de pantalla LCD

#endif
