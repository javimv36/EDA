#include <iostream>
#include "Hora.h"
#define MAX 10000
using namespace std;

void solve(Hora V[], int nTrenes, Hora consulta){

}

int main(){
	int nTrenes, nConsultas;
	Hora V[MAX];
    Hora consulta;
	cin >> nTrenes;
    cin >> nConsultas;
    while (nTrenes!=0 || nConsultas!=0){
        for(int i=0; i < nTrenes; i++){
            cin >> V[i];
            cout << V[i];
        }
    /*
        for (int i =0; i < nConsultas; i++){
            cin >> consulta;
            solve(nTrenes, V, consulta);
        }
    cin >> nTrenes;
    cin >> nConsultas;
    */
    }
    return 0;
}