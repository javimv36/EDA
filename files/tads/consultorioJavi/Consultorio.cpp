#include "Consultorio.h"
#include <iostream>
using namespace std;

Consultorio::Consultorio(){

}

void Consultorio::nuevoMedico(Medico m){
    consultorio[m];
}

void Consultorio::pideConsulta(Paciente p, Medico m, Fecha f) throw (Exception){
    if(consultorio.contains(m)){
        if (!consultorio[m].contains(f)){
            //El medico existente y la fecha esta libre, imprimir que se inserta;
            //consultorio[m].insert(f,p);
        }else 
            throw Exception("Fecha ocupada");
    }else
        throw Exception("Medico no existente");
}

void Consultorio::siguientePaciente(Medico m){
    if(consultorio.contains(m)){
        if (!consultorio[m].empty()){
            //el medico existente y tiene pacientes, imprimir el primeroinorden
        }else 
            throw Exception("No hay pacientes");
    }else
        throw Exception("Medico no existente");
}

void Consultorio::atiendeConsulta(Medico m){
    if(consultorio.contains(m)){
        if (!consultorio[m].empty()){
            //el medico existente y tiene pacientes, eliminar pimeroinorden
        }else 
            throw Exception("No hay pacientes");
    }else
        throw Exception("Medico no existente");
}

//Cambiar a tipo List<nombre, fecha>???
void Consultorio::listaPacientes(Medico m, int d){
    if(consultorio.contains(m)){
        return consultorio[m];
    }else
        throw Exception("Medico no existente");
}

istream &operator>>(istream &sIn, Consultorio &c) throw (Error)
{
    string op;
    Medico m;
    Paciente p;
    int d,h,m;
    char c;
    sIn >> op;
    sIn.get(c);
    if (op == "nuevoMedico"){
        sIn >> m;
        c.nuevoMedico(m);
    }
    else if (op == "pideConsulta"){
        sIn >> p;
        sIn.get(c);
        sIn >> m;
        sIn >> d;
        sIn >> h;
        sIn >> m;
        Fecha(d,h,m) f;
        c.pideConsulta(p,m,f);

    }else if(op == "listaPacientes"){
        sIn >> m;
        sIn >> d;
        c.listaPacientes(m,d);
    }else if (op == "siguientePaciente"){
        sIn >> m;
        c.siguientePaciente(m);
    }else if (op == "atiendeConsulta"){
        sIn >> m;
        c.atiendeConsulta(m);
    }
    else
        throw Error("Error");
   
    return sIn;
}