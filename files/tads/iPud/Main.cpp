#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "iPud.h"
#include "Exceptions.h"

bool resuelve() {
	while (true) {	
		string inst;
		cin >> inst;
		if (!cin) return false;
		Cancion s; Artista a; Duracion d;
		iPud iPud;
			while (inst != "FIN"){
				try {
					if (inst == "addSong") {
						cin >> s >> a >> d;
						iPud.addSong(s, a, d);
					}
					else if (inst == "addToPlaylist") {
						cin >> s;
						iPud.addToPlayList(s);
					}
					else if (inst == "totalTime") {
						cout << "Tiempo total " << iPud.totalTime() << '\n';
					}
					else if (inst == "current") {
						iPud.current();
					}
					else if (inst == "play") {
						iPud.play();
					}
					else if (inst == "deleteSong") {
						cin >> s;
						iPud.deleteSong(s);
					}
					else if (inst == "recent") {
						int n=0;
						cin >> n;
						iPud.listaRecientes(n);
					}
					
				}
				catch (invalid_argument e) {
					cout << e.what() << '\n';
				}
				cin >> inst;
			}
			cout << "----\n";
		
		
	}
}
	int main() {
		resuelve();
		return 0;
	}