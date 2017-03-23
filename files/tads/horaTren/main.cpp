#include <iostream>
#include "Hora.h"
#define MAX 10000
using namespace std;

Hora solve(Hora V[], int nTrenes, Hora consulta){
    int i;
    for(i=0; V[i] < consulta && i<nTrenes ; i++);
    return V[i];
}

int main(){
	int nTrenes, nConsultas;
	Hora V[MAX];
    Hora consulta;
    Hora resultado;
	cin >> nTrenes;
    cin >> nConsultas;
    while (nTrenes!=0 || nConsultas!=0){
        for(int i=0; i < nTrenes; i++){
            cin >> V[i];
        }
    
        for (int i = 0; i < nConsultas; i++){
            cin >> consulta;
            resultado = solve(V, nTrenes, consulta);
            cout << resultado << endl;
        }
    cin >> nTrenes;
    cin >> nConsultas;
    }
    return 0;
}