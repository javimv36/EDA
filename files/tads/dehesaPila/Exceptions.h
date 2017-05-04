/*
Definici?n de algunas excepciones de las distintas
implementaciones de los TADs.

Estructura de Datos y Algoritmos
Facultad de Inform?tica
Universidad Complutense de Madrid

(c) Marco Antonio G?mez Mart?n, 2012
*/
#ifndef __EXCEPCIONES_H
#define __EXCEPCIONES_H

#include <string>
#include <iosfwd>
/**
Clase de la que heredan todas las excepciones, y
que proporciona el atributo que almacena el
mensaje de error.
*/
class ExcepcionTAD {
public:
	ExcepcionTAD() {}
	ExcepcionTAD(const std::string &msg) : _msg(msg) {}

	const std::string msg() const { return _msg; }

	friend std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e);

protected:
	std::string _msg;
};

inline std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e) {
	out << e._msg;
	return out;
}


// Macro para declarar las clases de tipo excepci?n
// que heredan de ExcepcionConMensaje, para ahorrar
// escribir muchas veces lo mismo...
#define DECLARA_EXCEPCION(Excepcion) \
class Excepcion : public ExcepcionTAD { \
public: \
Excepcion() {}; \
Excepcion(const std::string &msg) : ExcepcionTAD(msg) {} \
};

/**
Excepci?n generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(EmptyStackException);

/**
Excepci?n generada por algunas operaciones de las pilas.
*/
DECLARA_EXCEPCION(FullStackException);

/**
Excepci?n generada por algunas de las operaciones de las colas.
*/
DECLARA_EXCEPCION(EmptyQueueException);

/**
Excepci?n generada por algunas operaciones de las colas dobles.
*/
DECLARA_EXCEPCION(EmptyDequeException);

/**
Excepci?n generada por algunas operaciones de las listas.
*/
DECLARA_EXCEPCION(EmptyListException);

/**
Excepci?n generada por accesos incorrectos a las listas
(tanto a un n?mero de elemento incorrecto como por
mal manejo de los iteradores).
*/
DECLARA_EXCEPCION(InvalidAccessException);

/**
Excepci?n generada por algunas operaciones de los
?rboles binarios.
*/
DECLARA_EXCEPCION(EArbolVacio);

/**
Excepci?n generada por algunas operaciones de los
diccionarios y ?rboles de b?squeda.
*/
DECLARA_EXCEPCION(EClaveErronea);

#endif // __EXCEPCIONES_H

