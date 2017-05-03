#include <iostream>
#include "Polinomio.h"
#include "Error.h"
using namespace std;
//x2 0 0 1

// Constructor sin argumentos
Polinomio::Polinomio()
{
	for (int i=0; i<MAXNUMCOEF;i++)_coeficientes[i]=0;
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
void Polinomio::setMonomio(int exp, int coef)
{
	_coeficientes[exp] += coef;

}

// Operador para insertar un polinomio
istream &operator >> (istream &sIn, Polinomio &polinomio) throw (Error)
{
		int coef=0, exp=0;
		sIn >> coef;
		sIn >> exp;
		while(!(coef==0 && exp==0)){
			polinomio.setMonomio(exp, coef);
			if(exp>polinomio.getGrado())
				polinomio.setGrado(exp);
			sIn >> coef;
			sIn >> exp;
		}
	return sIn;
}
