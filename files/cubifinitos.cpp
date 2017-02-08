#include <iostream>
#include <algorithm>
#define MAX 32
using namespace std;

bool sumaRepetida(int sumas[],int suma, int i){
	for (int j = 0; j<=i;j++)
		if (sumas[j]==suma)return true;
	return false;
}

void solve(int n, int (&sumas)[MAX], int i){
	cout << n;
	if(n==1)	
		cout << " -> cubifinito." << endl;
	else{
		int suma = 0;
		sumas[i] = n;
		for (n; n > 0; n/=10) suma+=((n%10)*(n%10)*(n%10));
		cout << " - ";
		if (sumaRepetida(sumas, suma, i)) 
			cout << suma << " -> no cubifinito." << endl;
		else solve(suma, sumas, ++i);
	}
}

int main (int argc, char **args ){
	int sumas[MAX],n;
	cin >> n;
	while(n!=0){
		solve(n, sumas, 0);
		cin >> n;
	}
return 0;
}