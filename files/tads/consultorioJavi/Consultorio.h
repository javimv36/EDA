#include "Exceptions.h"
#include "HashMap.h"
#include "TreeMap.h"
#include "Fecha.h"
#include <iostream>

typedef string Persona;
typedef string Medico;

class Consultorio{
    private:
        HashMap<Medico, TreeMap<Fecha, Paciente>> consultorio;

    public:
        Consultorio();
        void nuevoMedico(Medico m);
        void pideConsulta(Paciente p, Medico m, Fecha f) throw (Exception);
        void siguientePaciente(Medico m) throw (Exception);
        void atiendeConsulta(Medico m);
        void listaPacientes(Medico m, int d);
        friend istream &operator>>(istream &sIn, Consultorio &c) throw (Error);
};