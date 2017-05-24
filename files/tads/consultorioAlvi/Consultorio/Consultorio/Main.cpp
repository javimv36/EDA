#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Fecha.h"
#include "Consultorio.h"
#include "Exceptions.h"

bool resuelve() {

	int N;
	cin >> N;
	if (!cin) return false;

	string inst; Medico med; Paciente pac; int d, h, m;
	Consultorio con;
	
	for (int i = 0; i < N; ++i) {
		try {
			cin >> inst;
			if (inst == "nuevoMedico") {
				cin >> med;
				con.nuevoMedico(med);
			}
			else if (inst == "pideConsulta") {
				cin >> pac >> med >> d >> h >> m;
				con.pideConsulta(pac, med, Fecha(d, h, m));
			}
			else if (inst == "siguientePaciente") {
				cin >> med;
				pac = con.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << pac << '\n';
				cout << "---\n";
			}
			else if (inst == "atiendeConsulta") {
				cin >> med;
				con.atiendeConsulta(med);
			}
			//else if (inst == "listaPacientes") {
			//	/*cin >> med >> d;
			//	auto vec = con.listaPacientes(med, Fecha(d));

			//	cout << "Doctor " << med << " dia " << d << '\n';
			//	for (auto p : vec) {
			//		cout << p.second << ' ';
			//		cout << setfill('0') << setw(2) << p.first.hora() << ':';
			//		cout << setfill('0') << setw(2) << p.first.minuto() << '\n';
			//	}
			//	cout << "---\n";*/
			}
			catch (invalid_argument e) { cout << e.what() << '\n' << "---\n"; }
		}
		cout << "------\n";

		return true;
	}

	int main() {
		while (resuelve())
			return 0;
	}