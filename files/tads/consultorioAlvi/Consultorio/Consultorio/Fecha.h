#include "Error.h"
class Fecha
{
private:
	int dia;
	int hora;
	int minutos;

public:
	Fecha();
	Fecha(int d, int h, int m);
	Fecha(int d);
	void write(ostream &sOut);
	int getDia() const;
	int getHH() const;
	int getMM() const;
	
	bool operator<(const Fecha &fecha) const;
	
};