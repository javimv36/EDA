#include "List.h"
#include <string>
#include <iostream>
#include "Error.h"
#include <stdexcept>
#include "Exceptions.h"
#include "HashMap.h"
using namespace std;

typedef string Cancion;
typedef string Artista;
typedef int Duracion;

class iPud {	
	public:
		iPud();
		void addSong(Cancion& s, Artista& a, Duracion d);
		void addToPlayList(Cancion& s);
		Cancion current();
		void play();
		int totalTime();
		List<Cancion> listaRecientes(unsigned int n);
		void deleteSong(Cancion& s);

	private:
		typedef struct {
			Artista artista;
			Duracion duracion;
			bool reproducida;
		} InfoCancion;

		HashMap<Cancion, InfoCancion> ipud;
		List<Cancion> listaReproduccion;
		List<Cancion> recientes;
};
