#include "SetOfInts3.h"
#include <iostream>
using namespace std;
#define MAX 10000
#include <stdlib.h> 
int main(){
	SetOfInts3 *s =  new SetOfInts3();
	SetOfInts3 *s2 =  new SetOfInts3();
	cin >> *s;
	cin >> *s2;
	cout << *s << endl;
	cout << *s2 << endl;
	if(*s== *s2) cout << "son iguales"<< endl;
	else cout << "no son iguales"<< endl;
	delete s;
	delete s2;
	return 0;
}

bool solve(){

}
