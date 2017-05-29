#include <iostream>
#include "Consultorio.h"
#include "Error.h"
using namespace std;

Consultorio::Consultorio() {}

void Consultorio::nuevoMedico(Medico& m) {
	if (!consultorio.contains(m)) {
		consultorio.insert(m, TreeMap<Fecha, Paciente>());
	}
}

void Consultorio::pideConsulta(Paciente& p, Medico& m, Fecha f) {
	HashMap<Medico, TreeMap<Fecha, Paciente> >::Iterator it = consultorio.find(m);
	if (it == consultorio.end()){
		throw invalid_argument("Medico no existente");
	}
	else if (it.value().contains(f)){
		throw invalid_argument("Fecha ocupada");
	}
	else {
		it.value().insert(f, p);
	}
}

Paciente Consultorio::siguientePaciente(Medico& m) {
	HashMap<Medico, TreeMap<Fecha, Paciente> >::Iterator it = consultorio.find(m);
	Paciente siguiente;
	if (it == consultorio.end())	throw invalid_argument("Medico no existente");
	else {
		TreeMap<Fecha, Paciente>::Iterator it2 = it.value().begin();
		if (it2 == it.value().end())	throw invalid_argument("No hay pacientes");
		else {
			siguiente = it2.value();
		}
	}
	return siguiente;
}
void Consultorio::atiendeConsulta(Medico& m) {
	HashMap<Medico, TreeMap<Fecha, Paciente> >::Iterator it = consultorio.find(m);
	Paciente siguiente;
	if (it == consultorio.end())	throw invalid_argument("Medico no existente");
	else {
		TreeMap<Fecha, Paciente>::Iterator it2 = it.value().begin();
		if (it2 == it.value().end())	throw invalid_argument("No hay pacientes");
		else {
			it.value().erase(it2.key());
		}
	}
	
}
List< pair <Fecha, Paciente> > Consultorio::listaPacientes(const Medico& m, const Fecha fecha) {
	List< pair <Fecha, Paciente> > pacientes;
	HashMap<Medico, TreeMap<Fecha, Paciente> >::Iterator it = consultorio.find(m);
	Fecha fechaCita;
	if (it == consultorio.end())	throw invalid_argument("Medico no existe");
	else {
		TreeMap<Fecha, Paciente>::Iterator it2 = it.value().begin();
		while (it2 != it.value().end()) {
			fechaCita = it2.key();
			if (fechaCita.getDia() == fecha.getDia()) {
				pair<Fecha, Paciente> par;
				par.first = fechaCita;
				par.second = it2.value();
				pacientes.push_back(par);
			}
			it2.next();
		}
	}
	return pacientes;
}