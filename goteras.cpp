/*
Goteras
	Con la llegada de las lluvias, has descubierto una molesta gotera en el salón. 
	Con precisión suiza, las gotas caen una vez por segundo desde el techo hasta un 
	improvisado cubo que te ves obligado a vaciar periódicamente hasta que encuentres una solución.
	Convivir con una gotera es complicado porque tienes que sincronizar tu vida alrededor 
	de los vaciados del cubo…
Entrada:
	La entrada estará compuesta de un primer número indicando cuántos casos de prueba vendrán a continuación.
	Cada caso de prueba será un número mayor que cero con el número de gotas que entran en el cubo.
Salida:
	Para cada caso de prueba, el programa escribirá en una línea el tiempo máximo que puedes estar sin cambiar el cubo en el formato HH:MM:SS, donde HH indica el número de horas, MM el número de minutos y SS el número de segundos.
	Ningún cubo es tan grande como para poder estar más de un día completo sin cambiarse.
Entrada de ejemplo:
	3
	70
	3600
	3661
Salida de ejemplo:
	00:01:10
	01:00:00
	01:01:01
Pseudo-codigo:

*/

#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

void solve(int n, int (&tiempo)[MAX]){
	for (int i=2;i>=0;i--){
		tiempo[i]=n%60;
		n/=60;
	}
}

void resultados(int tiempo[]){
	cout.fill('0');
	cout.width(2);
	cout 	<< tiempo[0] << ":";
	cout.fill('0');
	cout.width(2);
	cout	<< tiempo[1] << ":";
	cout.fill('0');
	cout.width(2);
	cout	<< tiempo[2] << endl;
}


int main(int argc, char **argv){
	int N;
	int n;
	int tiempo[MAX];
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> n;
		solve(n, tiempo);
		resultados(tiempo);
	}
	return 0;
}