//Autor Javier Martin Villarreal

/*
	int r,l=0
	
	while (i<N){
		zero(V,l);
		one(V,r); 

	}
	dev r-l

*/

#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

void zero(int V[],int N, int &l){
	for(l=0; l<N && V[l]==0; l++);
}

void one(int V[], int N, int &r){
	for(r=N; r>=0 && V[r]==1; r--);
}

int solve(int V[], int N){
	int l, r;
	zero(V,N,l);
	one(V,N,r);
	return r-l;
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