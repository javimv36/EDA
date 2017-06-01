#include "Fecha.h"
using namespace std;

Fecha::Fecha(){
    d=0;
    h=0;
    m=0;
}
Fecha::Fecha(int d, int h, int m){
    dia=d;
    hora=h;
    minuto=m;
}

int Fecha::getDia() const{
    return dia;
}

int Fecha::getHora() const{
    return hora;
}

int Fecha::getMinutos() const{
    return minutos;
}

bool Fecha::operator<(const Fecha &f) const{
    if(dia<=f.getDia()&&hora<=f.getHora()&&minutos<f.getMinutos())
        return true;
    else return false;
}
