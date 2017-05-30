#include "iPud.h"

using namespace std;

iPud::iPud() {}

void iPud::addSong(Cancion& s, Artista& a, Duracion d) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	if (it == ipud.end()) {
		InfoCancion infoC;
		infoC.artista = a;
		infoC.duracion = d;
		infoC.reproducida = false;

		ipud.insert(s, infoC);
	}

	else throw invalid_argument("ERROR addSong");
}

void iPud::addToPlayList(Cancion& s) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	if (it != ipud.end()) {
		List<Cancion>::Iterator it = listaReproduccion.begin();
		if (!listaReproduccion.empty()) {
			while (it.elem() != s) {
				if (it != listaReproduccion.end())  {
					listaReproduccion.push_back(s);
				}
				else {
					throw invalid_argument("ERROR addToPlaylist");
				}
				it.next();
			}
		}
		else listaReproduccion.push_back(s);
	}
	else
	{
		throw invalid_argument("ERROR addToPlaylist");
	}
}

Cancion iPud::current() {
	if (!listaReproduccion.empty()) {
		Cancion s = listaReproduccion.front();
		cout << s << endl;
	}
	else {
		throw invalid_argument("ERROR current");
	}
}

void iPud::play() {
	if (!listaReproduccion.empty()) {
		Cancion s = listaReproduccion.front();
		listaReproduccion.pop_front();
		cout << "Sonando " << s << endl;
		HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
		it.value().reproducida = true;
	}
	else {
		throw invalid_argument("No hay canciones en la lista");
	}
}

int iPud::totalTime() {
	int total = 0;
	if (!listaReproduccion.empty()) {
		List<Cancion>::Iterator it = listaReproduccion.begin();
		while (it != listaReproduccion.end()) {
			HashMap<Cancion, InfoCancion>::Iterator itHashMap = ipud.find(it.elem());
			if (itHashMap != ipud.end()) {
				total += itHashMap.value().duracion;
			}
			it.next();
		}
	}
	return total;
}

//�C�mo sabemos si se ha reproducido mas o menos recientemente?
List<Cancion> iPud::listaCanciones(int n) {
	for (int i = 0; i < n; i++){
		
	
	}

}

void iPud::deleteSong(Cancion& s) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	List<Cancion>::Iterator it2 = listaReproduccion.begin();
	if (it != ipud.end()) {
		ipud.erase(s);
		if (!listaReproduccion.empty()){
			if (it2.elem() == s){
				listaReproduccion.erase(it2);
			}
			else it2.next();
		}
	}
	else throw invalid_argument("ERROR deleteSong");
}