// Sensor_system.h

#ifndef _SENSOR_SYSTEM_h
#define _SENSOR_SYSTEM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct capteur_struct {
	double face;
	double arriere;
	double gauche;
	double droite;
};

void trig_sensor();

capteur_struct get_sensor(void);

void interrupt01();
void interrupt02();

void interrupt11();
void interrupt12();

void interrupt21();
void interrupt22();

void interrupt31();
void interrupt32();

void init_sensor();

#endif

