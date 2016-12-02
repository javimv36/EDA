#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/*

P: V[0..N)=A[0..N)
Q:/forall i : 0 <= i < N : V[i]=sum j : 0 <= j <= i : A[j]

I: I[N7n]
B: n<N
init: n =1
step:n=n+1
restore: Vn=Vn-1+An
quote: N - n

for(n=1;n<Nn++)V[n]+=V[n-1];


I: /forall i: 0<=i<n : V[i] = sum(j): 0<=j<=i V[j]
*/
#define MAX 10000
//#define REC

#  ifdef REC

void isolve(int *V,int N, int n){
	if (n=N)return;
	if(n<N){
		V[n]+=V[(n-1)];
		isolve(V,N,n+1);
		return;
	}
}
void solve(int *V, int N){
	isolve(V, N, 1);
	return;
}

#else
void solve(int V[], int N){
	int n;
	for(n=1;n<N;n++)V[n]+=V[n-1];
	return;
}
#endif

int main(int argc, char **argv)
{
  int n;
  int N;
  int A[MAX];
	do{
		N=0;
		do{
			cin >> A[N];
			N++;
		}while(A[N-1]!=0);
		solve((int*)A,N-1);
		for (int n=0;n<N-1;n++)cout << A[n] << endl;
	}while(N-1>0);
  return 0;
}
