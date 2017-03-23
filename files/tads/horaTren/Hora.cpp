#include <iostream>
#include "Hora.h"
#include "Error.h"
using namespace std;

Hora::Hora()
{
    _horas = 0;
    _minutos = 0;
    _segundos = 0;
}

void Hora::write(ostream &sOut)
{
    sOut << _horas << ":" << _minutos << ":" << _segundos << std::endl;
}

void Hora::setHora(int h, int m, int s) throw(Error)
{
    if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59)
    {
        _horas = h;
        _minutos = m;
        _segundos = s;
    }
    else
        throw Error("Error");
}

ostream &operator<<(ostream &sOut, Hora &hora)
{
    hora.write(sOut);
    return sOut;
}

istream &operator>>(istream &sIn, Hora &hora)
{
    int h, m, s;
    char c;
    sIn >> h;
    sIn.get(c);
    sIn >> m;
    sIn.get(c);
    sIn >> s;
    hora.setHora(h, m, s);
    return sIn;
}
//tema8 FP