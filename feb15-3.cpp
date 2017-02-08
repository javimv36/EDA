/*
3. (3,5 puntos) Se dispone de una lista de n productos alimenticios entre los que se quiere escoger algunos para seguir una dieta adecuada.

 Para cada producto i (0 ≤ i < n) se conoce
 su precio pi ≥ 0,
 su contenido en proteinas qi ≥ 0 y
 su cantidad de calorías ci ≥ 0.

Se desea seleccionar algunos de estos productos (a lo sumo uno de cada) de forma
que el precio total no supere un presupuesto M, el contenido proteico total sea
al menos de Q y el valor calórico sea lo menor posible.

 Diseñar un algoritmo de vuelta atrás para encontrar la selección óptima,
 es decir, la que minimiza la cantidad de calorías. Se valorarán las podas realizadas
*/
//Author Javi
#include <iostream>
#define MAX 10000
using namespace std;

void copiarSolucion(bool S[], bool Smejor[], int n){
  for(int i=0;i<n;i++){
    Smejor[i]=S[i];
    cout << Smejor[i];
  }
  cout << endl;
}

void vueltaAtrasDieta(int P[], int T[], int C[],int &precio, int &proteinas, int &calorias, int M, int Q, int &minCalorias, int k, int n, bool S[], bool Smejor[]){
    for(int i=1;i>=0;i--){
        S[k]=i;
        if (i==1){
          calorias+=C[k];
          precio+=P[k];
          proteinas+=T[k];
        }else{
          calorias-=C[k];
          precio-=P[k];
          proteinas-=T[k];
        }
        if ((precio<=M) && (proteinas>=Q)){
          if(k==n-1){
            if(calorias < minCalorias){
              minCalorias=calorias;
              copiarSolucion(S, Smejor, k);
            }
            }else
              vueltaAtrasDieta(P,T,C,precio,proteinas,calorias,M,Q,minCalorias,k+1,n,S,Smejor);
        }
    }
}

int main(int argc, char **args){
  int P[MAX]= {1,2,1,3,2,4,4,3,1};
  int T[MAX]= {10,1,10,4,2,1,3,5,1};
  int C[MAX]= {5,9,1,5,3,2,4,4,8};
  int n=9;
  bool S[MAX];
  bool Smejor[MAX];
  int minCalorias=10000;
  int precio, proteinas,calorias;
  precio=calorias=proteinas=0;
  /*
  cin << n;   //DESCOMENTAR PARA PEDIR LOS DATOS DE LOS ALIMENTOS INDIVIDUALMENTE
  for (int i = 0; i<n; i++){
    cout << "Precio alimento " << i << ": ";
    cin >> P[i];
    cout << "Proteinas alimento " << i << ": ";
    cin >> T[i];
    cout << "Calorias alimento " << i << ": ";
    cin >> C[i];
  }
  */
  int M,Q;
  cout << "Precio maximo (M): ";
  cin >> M;
  cout << "Proteinas minimas (Q):";
  cin >> Q;
  vueltaAtrasDieta(P,T,C,precio,proteinas,calorias,M,Q,minCalorias,0,n,S,Smejor);
  return 0;
}
