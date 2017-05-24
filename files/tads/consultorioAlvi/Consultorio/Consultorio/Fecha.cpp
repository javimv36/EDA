#include <iostream>
#include "Fecha.h"
#include "Error.h"
using namespace std;

Fecha::Fecha(int d, int h, int m)
{
	if (31 <= d && h <= 23 && 0 <= m && m <= 59)
	{
		dia = d;
		hora = h;
		minutos = m;
	}
}

Fecha::Fecha(int d)
{
	if (31 <= d)
	{
		dia = d;
		hora = 0;
		minutos = 0;
	}
}

Fecha::Fecha()
{
	dia = 00;
	hora = 00;
	minutos = 00;
}

void Fecha::write(ostream &sOut)
{

}

int Fecha::getDia() const
{
	return dia;
}
int Fecha::getHH() const
{
	return hora;
}
int Fecha::getMM() const
{
	return minutos;
}

bool Fecha::operator<(const Fecha &fecha) const
{
	if (getDia() < fecha.getDia())
	{
		return true;
	}
	else if (getDia() == fecha.getDia())
	{
		if (getHH() < fecha.getHH())
		{
			return true;
		}
		else if (getHH() == fecha.getHH())
		{
			if (getMM() < fecha.getMM())
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
