/*
Ejercicio 3
funcion que genere verctores crecientes por los pelos y d-divertidos

recibe n, d y priemer elemnto del Vector
*/
void tratarSolucion(int S[], int n){
  for (int i = 0; i<n; i++) cout << S[i];
  cout << endl;
}
//inicializando marcas con todo ceros (ningun numero se ha cogido)
void solve(int n, int d, int e, int S[], int k, int marcas[]){
    for (int i=e;i<e+n; i++){
      if(marcas[i]<d){
        S[k]=i;
        if((S[k]==S[k-1]||S[k]==S[k-1]+1)&&){ //si el elemento es igual o solo 1 mayor
          if(k==n-1){
            tratarSolucion(S,n);
          }
          else {
            marcas[i]+=1;
            solve(n,d,e,S,k+1,marcas);
            marcas[i]-=1;
          }
        }
      }
    }
}

int main(){
  int S[MAX];
  int n;
  int d;
  int e;
  int marcas[MAX];//inicializado todo a cero (no hemos cogido elementos)
  cin << n;
  cin << d;
  cin << e;
  S[0]=e; //cogemos el primero
  marcas[0]+=1; //marcamos que ya lo hemos cogido una vez
  solve(n,d,e,S,1,marcas);
}
