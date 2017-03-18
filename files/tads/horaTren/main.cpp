#include <iostream>
#include "horas.h"
#define MAX 10000
using namespace std;

class Horas
{
  private:
    int horas;
    int minutos;
    int segundos;
 public:
    istream &operator>>(istream &sIn, Horas &h){
        int n, h, m, s;
        sIn.get(n);
        h = 10 * n;
        sIn.get(n);
        h += n;
        sIn.get(n);
        sIn.get(n);
        m = 10 * n;
        sIn.get(n);
        m += n;
        sIn.get(n);
        sIn.get(n);
        s = 10 * n;
        sIn.get(n);
        s += n;
        if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59)
        {
            horas = h;
            minutos = m;
            segundos = s;
        }
        else
            throw "Error";
    }

    ostream &operator<<(ostream &sOut, Horas &h) {
        sOut << horas << ":" << minutos << ":" << segundos << endl;
    }
};

void solve(Horas V[], int nTrenes, Horas consulta){

}

int main(){
	int nTrenes, nConsultas;
	Horas V[MAX];
    Horas consulta;
	cin >> nTrenes;
    cin >> nConsultas;
    while (nTrenes!=0 || nConsultas!=0){
        for(int i=0; i < nTrenes; i++){
            cin >> V[i];
            cout << V[i];
        }

        for (int i =0; i < nConsultas; i++){
            cin >> consulta;
            solve(nTrenes, V, consulta);
        }
    cin >> nTrenes;
    cin >> nConsultas;
    }
    return 0;
}