/* 
Pseudo-code


{P: N >= 1}
i=1;
{I}
V[0]=A[0];
while(i<N)	{I ^ B}{
	V[i] = A[i]+V[i-1]
	i++;
{I}
}{I^¬B}
{Q}

P:{N>=1}
fun suma(A[0...N) de ent,V[0...N) de ent,N) dev V[0...N] ent
Q:{forall(i): 0<=i<N:V[i] = sum(A[0]...A[i])}
I:{Q[N/n] ^ 0<=n<N}

B:n>N

*/

#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;
#define MAX 100000;


void solve(int A[], int V[], int N){
	V[0] = A[0];
	for(i=1; i< N; i++) V[i] = A[i]+V[i-1];	
}

int main(int argc, char **argv){
	
	int V[MAX];
	int A[MAX];
	int N;
	
	cin>>N;
	for(int j=0; j<N; j++)cin>>A[i];
	
	solve(A, &V, N);

	for(int i=0; i < N; i++)cout<<V[i];

}
