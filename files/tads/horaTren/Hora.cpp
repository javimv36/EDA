#include <iostream>
#include "Hora.h"
#include "Error.h"
using namespace std;

Hora::Hora()
{
    _horas = 00;
    _minutos = 00;
    _segundos = 00;
}

void Hora::write(ostream &sOut)
{
    sOut << ((_horas < 10) ? ("0") : ("")) << _horas << ":" << ((_minutos < 10) ? ("0") : ("")) << _minutos << ":" << ((_segundos < 10) ? ("0") : ("")) << _segundos << endl;
}

void Hora::setHora(int h, int m, int s)
{
    if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59)
    {
        _horas = h;
        _minutos = m;
        _segundos = s;
    }
}

int Hora::getHH() const
{
    return _horas;
}
int Hora::getMM() const
{
    return _minutos;
}
int Hora::getSS() const
{
    return _segundos;
}

bool Hora::operator<(const Hora &hora) const
{
    if (getHH() < hora.getHH())
    {
        return true;
    }
    else if (getHH() == hora.getHH())
    {
        if (getMM() < hora.getMM())
        {
            return true;
        }
        else if (getMM() == hora.getMM())
        {
            if (getSS() < hora.getSS())
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

ostream &operator<<(ostream &sOut, Hora &hora)
{
        hora.write(sOut);
    return sOut;
}

istream &operator>>(istream &sIn, Hora &hora) throw (Error)
{
    int h, m, s;
    char c;
    sIn >> h;
    sIn.get(c);
    sIn >> m;
    sIn.get(c);
    sIn >> s;
if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59)
    {
         hora.setHora(h, m, s);
    }
    else
        throw Error("Error");
   
    return sIn;
}
//tema8 FP