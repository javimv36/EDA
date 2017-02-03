#include <iostream>
#define MAX 100000
using namespace std;

int solve(int V[], int N);

int main(int argc, char **args){
	int n;
	int N;
	int V[MAX];
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> N;
		for (int j=0; j<N; j++){
			cin >> V[j];
		}
		cout << solve(V,N) << endl;
	}
	return 0;
}

int solve(int V[], int N){
	int min = (V[0]<V[1])?V[0]:V[1];
	int max = (V[0]>V[1])?V[0]:V[1];
	for(int i=2;i<N;i++){
		min=(min<V[i])?min:V[i];
		max=(max>V[i])?max:V[i];
	}
	return max-min;
}