#include <iostream>
#include "Polinomio.h"
#include "Error.h"

using namespace std;

//x2 0 0 1

// Constructor sin argumentos
Polinomio::polinomio()
{
    _grado = 0;
    int _coeficientes[_grado + 1];
}

// Constructor con argumentos
Polinomio::polinomio(int gr, int[] v)
{
    _grado = gr;
    int _coeficientes[_grado + 1];
    for (int i = 0; i <= _grado; i++)
	_coeficientes[i] = v[i];
}

// Constructor con grado
Polinomio::polinomio(int gr)
{
    _grado = gr;
    int _coeficientes[_grado + 1];
}

// Modificar el polinomio
void setPolinomio(int gr, int[] v)
{
    _grado = gr;
    for (int i = 0; i < _grado; i++)
	_coeficientes[i] = v[i];
}

// Modificar monomio i por num
void setMonomio(int i, int num)
{
    _coeficientes[i] = num;
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
    for (int i = 0; i < _grado; i++)
	sOut << ("coef ") << i << " " << _coeficientes[i];
}

// Obtener el grado del polinomio
int getGr() const
{
    return _grado;
}

// Obtener los coeficientes
void getCoef(int &v[]) const
{
}

// Operador comparacion (igualdad) de un polinomio
bool operator==(const Polinomio &polinomio) const
{
    //Comprobar que tienen el mismo gr sino son /=
    if (_grado == polinomio.getGr())
    {
	//mismo vector
	for (int i = 0; i < _grado; i++)
	{
	    //if(getCoef() == polinomio.getCoef())????
	    if (_coeficientes[i] != polinomio._coeficientes[i])
		return false;
	}
	return true;
    }
    return false;
}

// Operador comparacion (menor que) de un polinomio
bool operator<(const Polinomio &polinomio) const
{
    if (getGr() < polinomio.getGr())
	return true;
    else
	return false;
}

// Modificar monomio i por num
void setMonomio(int i, int num)
{
    _coeficientes[i] = num;
}

// Añadir monomio al final del polinomio
void addMonomio(int num)
{
    _grado++;
    _coeficientes[_grado] = num;
}

// Operador suma de un polinomio
//p.suma(p1);
Polinomio &Polinomio::operator+(const Polinomio &polinomio) const
{
    int grad = max(getGr(), polinomio.getGr());
    int i = 0;

    //El grado del polinomio a sumar es mayor
    if (getGr() < polinomio.getGr())
    {
	// 1 2 3   1 2 3 4 5 6
	// 2 4 6 4 5 6
	for (i = 0; i < getGr; i++)
	    _coeficientes[i] += polinomio._coeficientes[i];
	i = _grado;
	while (i < grad)
	    addMonomio(i, polinomio._coeficientes[i]);
    }
    //El grado del polinomio a sumar es igual
    else if (getGr() == polinomio.getGr())
    {
	// 1 2 3   1 2 3
	// 2 4 6
	for (i = 0; i < getGr(); i++)
	    _coeficientes[i] += polinomio._coeficientes[i];
    }
    //El grado del polinomio a sumar es menor
    else if (getGr() > polinomio.getGr())
    {
	// 1 2 3 4 5 6    1 2 3
	// 2 4 6    4 5 6
	for (i = 0; i < polinomio.getGr(); i++)
	    _coeficientes[i] += polinomio._coeficientes[i];
    }
    return *this;
}

// Operador para insertar un polinomio
friend istream &operator>>(istream &sIn, Polinomio &polinomio) throw(Error)
{
    int gr;
    int coef[];
    sIn >> gr;
    for (int i = 0; i < gr; i++)
	sIn >> coef[i];
    if (0 <= gr)
	polinomio.setPolinomio(gr, coef);
    else
	throw Error("Error");
    return sIn;
}

// Operador para mostrar un polinomio
friend ostream &operator<<(ostream &sOut, Polinomio &polinomio)
{
    polinomio.write(sOut);
    return sOut;
}