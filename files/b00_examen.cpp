pseudo-code
sintax flavour

P:{0<=N ^ alles(i):0<=i<N:0<=V[i]<=99999}
fun par(V[0..N) of ints) dev p int
Q:{#i:0<=i<N:(V[i]mod2=0)}
I:{Q[N/n]^0<=n<N}

fun par(V,N){
	p:=0
	i:=0
	{I}
	while (i<N){	
		{I^B}
		if (V[i]%2==0)
			p=p+1
		i++
		{I}
	}{I^¬B}
	{Q}
	dev p 
}

#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000

int solve(int V[], int N){
	p=0;
	for(int i=0; i<N; i++)p+=(V[i]%2==0);
	return p;
}

int main(int argc, char **argv)
{
  int n;
  int N;
  int A[MAX];
  cin >> n;
  for (int i=0; i < n ; i++)
    {
      cin >> N  ;
      for (int j=0; j < N ; j++)
	cin >> A[j];
      cout << solve(A,N) << endl;
    }
  return 0;
}