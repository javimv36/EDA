#include "iPud.h"

using namespace std;

iPud::iPud() {}

void iPud::addSong(Cancion& s, Artista& a, Duracion d) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	if (it == ipud.end()) {
		InfoCancion infoC;
		infoC.artista = a;
		infoC.duracion = d;
		ipud.insert(s, infoC);
	}
	else throw invalid_argument("ERROR addSong");
}

void iPud::addToPlayList(Cancion& s) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	if (it != ipud.end()) {
		List<Cancion>::Iterator it2 = listaReproduccion.begin();
		if (!listaReproduccion.empty()) {
			while (it2.elem() != s) {
				if (it2 != listaReproduccion.end())  {
					listaReproduccion.push_back(s);
				}
				else {
					throw invalid_argument("ERROR addToPlaylist");
				}
				it2.next();
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
	Cancion s;
	if (!listaReproduccion.empty()) {
		s = listaReproduccion.front();
	}
	else {
		throw invalid_argument("ERROR current");
	}
	return s;
}

void iPud::play() {
	if (!listaReproduccion.empty()) {
		Cancion s = listaReproduccion.front();
		listaReproduccion.pop_front();
		cout << "Sonando " << s << endl;
		recientes.push_front(s);
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

List<Cancion> iPud::listaRecientes(int n) {
	List<Cancion> aux;
	List<Cancion>::Iterator it = recientes.begin();
	if (n > recientes.size()) {
		n = recientes.size();
	}
	for (int i = 0; i < n; i++){
		aux.push_back(it.elem());	
		cout << "    " << it.elem() << '\n';
		it.next();
	}
	return aux;
}

void iPud::deleteSong(Cancion& s) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	List<Cancion>::Iterator it2 = listaReproduccion.begin();
	List<Cancion>::Iterator it3 = recientes.begin();
	if (it != ipud.end()) {
		ipud.erase(s);
		if (it2 != listaReproduccion.end() && !listaReproduccion.empty()){
			if (it2.elem() == s){
				listaReproduccion.erase(it2);
			}
			else it2.next();
		}
		else if (it3 != recientes.end() && !recientes.empty()) {
			if (it3.elem() == s) {
				recientes.erase(it3);
			}
			else
			{
				it3.next();
			}	
		}
	}
	else throw invalid_argument("ERROR deleteSong");
}
