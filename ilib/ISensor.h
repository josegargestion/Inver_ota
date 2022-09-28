#pragma once
#ifndef ISENSOR_H
#define ISENSOR_H
#include "..\estructuras.h"
class ISensor
{
public:
	virtual _Isensor GetSensor() = 0;
	virtual void UpdateSensor() = 0;
	virtual ~ISensor();
};
#endif
