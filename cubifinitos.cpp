#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

bool sumaRepetida(int (&sumas)[MAX], int i){
	bool iguales = false;
	for (int j = 0; j<i;j++)
		if (sumas[j]==sumas[i])iguales=true;
	return iguales;
}

void solve(int n, int (&sumas)[MAX], int i){
	int num=n;
	int cubo;
	int suma = 0;
	cout << n;
	if(n==1)	
		cout << " -> cubifinito." << endl;
	else{
		for (num; num > 0; num/=10){
			cubo=(num%10)*(num%10)*(num%10);
			suma+=cubo;
		}
		sumas[i] = suma;
		cout << " - ";
		if (sumaRepetida(sumas, i)) 
			cout << suma << " -> no cubifinito." << endl;
		else solve(suma, sumas, ++i);
	}
}

int main (int argc, char **args ){
	int sumas[MAX];
	int n;
	cin >> n;
	while(n!=0){
		solve(n, sumas, 0);
		cin >> n;
	}
return 0;
}