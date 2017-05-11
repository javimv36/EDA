#include "Polinomio.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

int solve(Polinomio p, int x){
    int solucion=0;
    int pot=1;
    for(int i=0; i<=p.getGrado(); i++){
        solucion += p.getCoef(i)*pot;
        pot*=x;
    }
    return solucion;
}

bool resuelve(){
    if(!cin){
        return false;
    }else{
        Polinomio polinomio = Polinomio();
        cin >> polinomio;
        int casos, caso;
        if(!(polinomio.getGrado()==0 && polinomio.getCoef(0)==0)){
        cin >> casos;
        
        for (int i=0; i<casos; i++){
            cin >> caso;
            
                int sol = solve(polinomio, caso);
                cout << sol << " ";
            }
cout << endl;
        }
        return true;
    }
}

int main()
{
    while (resuelve()){
        
    }
    return 0;
}
