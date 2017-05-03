#include "Error.h"
#include <iostream>

// Un polinomio en una variable es una expresion matematica de la
// forma P(x) = anxn + an−1x n−1 + ... + a1x 1 + a0x 0. 
// Las constantes (a0,...,an) se llaman los coeficientes del polinomio 
// y los valores  (0..n)                los exponentes (numero naturales). 
// Se puede deducir que el exponente es la posicion en el vector de conocimientos.

// Cada una de las sumas aixi se denomina un monomio. 

// La operacion mas basica que podemos realizar con un polinomio es
// calcular su valor para cierto valor de la variable. 

// En este problema se pide: 
// calcular el valor de un polinomio para diversos valores de la variable.

class Polinomio
{
private:
	static const int MAXNUMCOEF = 10;
	// El grado del polinomio es el del monomio de mayor grado.
	int _grado;
	int _coeficientes[MAXNUMCOEF];

public:
	// Constructor del polinomio
	Polinomio();

	// Constructor con argumentos
	Polinomio(int gr);
	//polinomio(int gr, int[] &v);

	// Modificar el polinomio
	//void setPolinomio(int gr, int[] v);
	void setMonomio(int exp, int coef);
	void setGrado(int gr);
	// Escribir un polinomio
	void write(ostream &sOut);
	// Obtener el grado del polinomio
	int getGrado() const;
	
	// Obtener los coeficientes
	int getCoef(int gr) const;
	
	// Operador comparacion (igualdad) de un polinomio
	bool operator==(const Polinomio &polinomio) const;
	// Operador comparacion (menor que) de un polinomio
	bool operator<(const Polinomio &polinomio) const;
	// Operador suma de un polinomio
	bool operator+(const Polinomio &polinomio) const;
	// Operador para insertar un polinomio
	friend istream &operator >> (istream &sIn, Polinomio &polinomio) throw (Error);
	// Operador para mostrar un polinomio
	friend ostream &operator<<(ostream &sOut, Polinomio &polinomio);
};
