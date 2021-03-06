#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Fecha.h"
#include "List.h"
#include "HashMap.h"
#include "TreeMap.h"

using namespace std;

typedef string Medico;
typedef string Paciente;

class Consultorio{
	public:
		Consultorio();
		void nuevoMedico(Medico& m);
		void pideConsulta(Paciente& p, Medico& m, Fecha f);
		Medico siguientePaciente(Medico& m);
		void atiendeConsulta(Medico& m);
		List< pair <Fecha, Paciente> > listaPacientes(const Medico& m, const Fecha fecha);

	private:
		HashMap<Medico, TreeMap <Fecha, Paciente> > consultorio; 
};
