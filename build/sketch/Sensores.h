#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Inver_ota\\Sensores.h"
#pragma once
#ifndef SENSORES_H
#define SENSORES_H
#include "estructuras.h"
class ISensores
{
public:
	virtual _Isensores GetSensores() = 0;
	virtual void UpdateSensores() = 0;
	virtual ~ISensores();
};
#endif

