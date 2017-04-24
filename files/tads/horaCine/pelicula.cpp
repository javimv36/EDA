#include <iostream>
#include "pelicula.h"
using namespace std;

Pelicula::Pelicula()
{
    _horaInicio.setHora(0, 0, 0);
    _horaFin.setHora(0,0,0);
    _duracion.setHora(0, 0, 0);
    _nombre = "";
}

void Pelicula::setDatos(Hora horaInicio, Hora duracion, string nombre)
{
    _horaInicio = horaInicio;
    _duracion = duracion;
    _horaFin = horaInicio + duracion;
    _nombre = nombre;
}

void Pelicula::write(ostream &sOut)
{
    sOut << _horaInicio << " " << _duracion << " " << _nombre << endl;
}

Hora Pelicula::getHora() const
{
    return _horaInicio;
}

Hora Pelicula::getDuracion() const
{
    return _duracion;
}

Hora Pelicula::getFin() const
{
    return _horaFin;
}

string Pelicula::getNombre() const
{
    return _nombre;
}

bool Pelicula::operator<(const Pelicula &p) const
{
    if(this->_horaFin < p.getFin()){
        return true;
    }
    if(this->_horaFin == p.getFin()){
        if(this->_nombre < p.getNombre()){
            return true;
        }
        else return false;
    }else
    return false;
}

istream &operator>>(istream &sIn, Pelicula &p)
{
    Hora inicio, duracion;
    string nombre;
    char c;
    sIn >> inicio;
    sIn >> duracion;
    sIn.get(c);
    getline(sIn, nombre);
    p.setDatos(inicio, duracion, nombre);
    return sIn;
}

ostream &operator<<(ostream &sOut, Pelicula &p)
{
    p.write(sOut);
    return sOut;
}