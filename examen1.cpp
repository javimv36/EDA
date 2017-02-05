//Autor Javier Martin Villarreal

/*
	P:{0<=N}
	fun solve(V[0...N)) dev r-l
	Q:{r-l:{
		(l=#i:0<=i<N:i<=		 && V[i]==0)
		(r=#i:0<=i<N:i>=l && V[i]==1)}}
	I:Q[N/n] and 0<=l<=r<N


								{P}
	fun solve(V[0...N) de enteros){
		int l,r = 0,N-1
								{I1}
		while(l<=r && V[l]==0){	{I1 and B1}
			l++
								{I1}
		}						{I1 and notB1}
								{I2}
		while(r>=l && V[r]==1){	{I2 and B2}
			r--
								{I2}
		} 						{I2 and notB2}
		dev r-l
	}							{Q}

*/

#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int solve(int V[], int N){
 int l,r,i;
 	for(l=0,r=N-1,i=0; l<=r && i<N; i++){
 		l+=(V[l]==0);
 		r-=(V[r]==1);
 	}
	return r-l+1;
}

int main(int argc, char **argv)
{
  int n;
  int N;
  int V[MAX];

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    for (int j=0; j<N; j++) cin >> V[j];
  cout << solve(V,N) << endl;
  }
  return 0;
}

/*
	Quicksort and mergesort

	Estos algoritmos de ordenación encuentran semejanzas en el coste
	sin llegar a ser iguales. Ambos tienen un coste estimado del
	orden de nlog(n), siendo así siempre para el mergesort.

	sin embargo en el quicksort encontramos que en los mejores casos de ordenación
	se comportaría mejor acercandose a un coste de O(n) pero llegando a O(n²) en los caso peores

	el mergesort es mas comodo para partirlo y es mas complejo a la hora de mezclarlo "merge"

*/
