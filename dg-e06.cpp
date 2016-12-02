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

#define REC

#ifdef REC
void solve(int V[], int N){
	isolve(V N 1);
	return;
}

void isolve(int V[],int N, int n){
	if (n=N)return;
	if(n<N){
		V[n]+=V[n-1];
		isolve(V,N,n+1);
		return;
	}
}
#else
void solve(int V[], int N){
	int n;
	for(n=1;n<N;n++)V[n]+=V[n-1];
	return;
}
#endif