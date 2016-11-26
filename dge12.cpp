//Author Javi

/*
  pseudo code
  fun(A[],N,a){
   i,o,p,l;
   while(i<N){
    if(A[i]<=a){
       p=i+1;
    }
    if(l<(i+1-p)){
       l=(i+1-p);
       o=p
    }
    i++;
   }
  return o, o+l-1;
  }
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000
/*
A[]:Vector de alturas de los edificios
N:Número de edificios
a:altura minima
i:contador;
p:puntero de origen del nuevo subvector;
l:longitud del mayor subvector encontrado;
o:origen del mayor subvector encontrado;

El coste de la función está en O(N)
c1+c2*N
*/
void solve(int A[], int N, int a){
  int i, p, l, o;
  for (i=p=o=l=0; i<N; i++){
    if(A[i]<=a)p=i+1;
    else if(l<(i+1-p)){
      l=(i+1-p);
      o = p;
    }
  }
  cout << o << " " << o+l-1;
}

int main(int argc, char **argv)
{
  int n;
  int a;
  int N;
  int A[MAX];

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    cin >> a;
    for (int j=0; j<N; j++) cin >> A[j];
    solve(A,N,a);
  }
  return 0;
}
