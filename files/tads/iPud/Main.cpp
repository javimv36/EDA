#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "iPud.h"
#include "Exceptions.h"

bool resuelve() {
	while (true) {
		int N;
		cin >> N;
		if (!cin) return false;

		string inst; Cancion s; Artista a; Duracion d;
		
		iPud iPud;

		for (int i = 0; i < N; ++i) {
			try {
				cin >> inst;
				if (inst == "addSong") {
					cin >> s >> a >> d;
					iPud.addSong(s, a, d);
				}
				else if (inst == "addToPlaylist") {
					cin >> s;
					iPud.addToPlayList(s);
				}
				else if (inst == "current") {
					cout << "Sonando " << iPud.current() << '\n';
				}
				else if (inst == "play") {
					iPud.play();
				}
				else if (inst == "deleteSong") {
					cin >> s;
					iPud.deleteSong(s);
				}
				else if (inst == "recent") {
					
					cout << "---\n";
				}
			}
			catch (invalid_argument e) {
				cout << e.what() << '\n' << "---\n";
			}
		}
		cout << "------\n";
	}
}

	int main() {
		resuelve();
		return 0;
	}