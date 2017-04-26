#include <iostream>
#include "Polinomio.h"
#include "Error.h"
using namespace std;
//x2 0 0 1

// Constructor sin argumentos
Polinomio::Polinomio()
{
	_grado = 0;
}

// Constructor con argumentos
Polinomio::Polinomio(int gr)
{
	_grado = gr;

}


void Polinomio::setGrado(int gr)
{
	_grado = gr;
}

// Obtener el grado del polinomio
int Polinomio::getGrado() const
{
	return _grado;
}

// Obtener los coeficientes
int Polinomio::getCoef(int gr) const
{
	return _coeficientes[gr];
}

// Modificar monomio i por num
void Polinomio::setMonomio(int i, int num)
{
	_coeficientes[i] = num;
}

// Operador para insertar un polinomio
istream &operator >> (istream &sIn, Polinomio &polinomio) throw (Error)
{
	int gr;
	sIn >> gr;
	polinomio.setGrado(gr);
	if (gr > 0) {
		int coef;
		for (int i = 0; i < gr;i++) {
			sIn >> coef;
			polinomio.setMonomio(i, coef);
		}
	}
	else
		throw Error("Error");
	return sIn;
}


// Operador para mostrar un polinomio
/*
ostream &operator<<(ostream &sOut, Polinomio &polinomio)
{
	polinomio.write(sOut);
	return sOut;
}
// Añadir monomio al final del polinomio
void addMonomio(int num)
{
_grado++;
_coeficientes[_grado] = num;
}
// Operador suma de un polinomio
//p.suma(p1);
Polinomio& Polinomio::operator+(const Polinomio &polinomio) const
{
int grad = max(getGr(), polinomio.getGr());
int i = 0;

//El grado del polinomio a sumar es mayor
if (getGr() < polinomio.getGr())
{
// 1 2 3   1 2 3 4 5 6
// 2 4 6 4 5 6
for (i = 0; i<getGr;i++)
_coeficientes[i] += polinomio._coeficientes[i];
i = _grado;
while (i<grad)
addMonomio(i, polinomio._coeficientes[i]);
}
//El grado del polinomio a sumar es igual
else if (getGr() == polinomio.getGr())
{
// 1 2 3   1 2 3
// 2 4 6
for (i = 0; i<getGr();i++)
_coeficientes[i] += polinomio._coeficientes[i];
}
//El grado del polinomio a sumar es menor
else if (getGr() > polinomio.getGr())
{
// 1 2 3 4 5 6    1 2 3
// 2 4 6    4 5 6
for (i = 0; i<polinomio.getGr();i++)
_coeficientes[i] += polinomio._coeficientes[i];
}
return *this;
}

//Calcula el valor para un polinomio
/*
int sol(int num)
{
int solucion = 0;
for (i = getGr(); i == 0; i--)
solucion += _coeficientes[i];
}
// Operador comparacion (igualdad) de un polinomio
bool operator==(const Polinomio &polinomio) const
{
//Comprobar que tienen el mismo gr sino son /=
if (_grado == polinomio.getGr())
{
//mismo vector
for (int i = 0; i<_grado; i++)
{
//if(getCoef() == polinomio.getCoef())????
if (_coeficientes[i] != polinomio._coeficientes[i]) return false;
}
return true;
}
return false;
}
// Operador comparacion (menor que) de un polinomio
bool operator<(const Polinomio &polinomio) const
{
if (getGr() < polinomio.getGr()) return true;
else return false;
}
// Añadir monomio al final del polinomio
void addMonomio(int num)
{
_grado++;
_coeficientes[_grado] = num;
}
// Escribir un polinomio
void write(ostream &sOut)
{
sOut << ("grado") << _grado;
for (int i = 0; i<_grado;i++)
sOut << ("coef ") << i << " " << _coeficientes[i];
}

// Constructor con argumentos
Polinomio::polinomio(int gr, int[] v)
{
_grado = gr;
for(int i = 0; i<_grado; i++)
_coeficientes[i] = v[i];
}

// Modificar el polinomio
void Polinomio::setPolinomio(int gr, int[] v)
{
_grado = gr;
for (int i = 0; i<_grado; i++)
_coeficientes[i] = v[i];
}
*/
