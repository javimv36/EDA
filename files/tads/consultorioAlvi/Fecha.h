
#ifndef __FECHA_H
#define __FECHA_H

#include "Error.h"
class Fecha
{
private:
	int dia;
	int hora;
	int minutos;

public:
	Fecha();
	Fecha(int d, int h, int m);
	
	int getDia() const;
	int getHH() const;
	int getMM() const;
	
	bool operator<(const Fecha &fecha) const;
	bool operator==(const Fecha &fecha) const;
	
};

#endif // __FECHA_H