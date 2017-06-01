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
		while (it2 != listaReproduccion.end() && it2.elem() != s) {
			it2.next();
		}
		if (it2 == listaReproduccion.end()){
			listaReproduccion.push_back(s);
		}
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
		List<Cancion>::Iterator it = recientes.begin();
		Cancion s = listaReproduccion.front();
		listaReproduccion.pop_front();
		cout << "Sonando " << s << endl;
		while (it != recientes.end() && it.elem() != s){
			it.next();
		}
		if (it != recientes.end()){
			recientes.erase(it);
		}
		recientes.push_front(s);
	}
	else {
		throw invalid_argument("No hay canciones en la lista");
	}
}

int iPud::totalTime() {
	int total = 0;
	List<Cancion>::Iterator it = listaReproduccion.begin();
	while (it != listaReproduccion.end()) {
		HashMap<Cancion, InfoCancion>::Iterator itHashMap = ipud.find(it.elem());
		if (itHashMap != ipud.end()) {
			total += itHashMap.value().duracion;
		}
		it.next();
	}
	return total;
}

List<Cancion> iPud::listaRecientes(unsigned int n) {
	List<Cancion> aux;
	if (!recientes.empty()){
		List<Cancion>::Iterator it = recientes.begin();
		cout << "Las " << n << " mas recientes" << '\n';
		if (n > recientes.size()) {
			n = recientes.size();
		}
		unsigned int i;
		for (i = 0; i < n; i++){
			aux.push_back(it.elem());
			cout << "    " << it.elem() << '\n';
			it.next();
		}
	}
	else throw invalid_argument("No hay canciones recientes");
	return aux;
}

void iPud::deleteSong(Cancion& s) {
	HashMap<Cancion, InfoCancion>::Iterator it = ipud.find(s);
	bool encontrado = false;
	if (it != ipud.end()) {
		List<Cancion>::Iterator it2 = listaReproduccion.begin();
		List<Cancion>::Iterator it3 = recientes.begin();
		ipud.erase(s);
		while(it2 != listaReproduccion.end() && !encontrado){
			if (it2.elem() == s){
				listaReproduccion.erase(it2);
				encontrado = true;
			}
			it2.next();
		}
		encontrado = false;
		while(it3 != recientes.end() && !encontrado) {
			if (it3.elem() == s) {
				recientes.erase(it3);
				encontrado = true;
			}
			it3.next();	
		}
	}
	else throw invalid_argument("ERROR deleteSong");
}
