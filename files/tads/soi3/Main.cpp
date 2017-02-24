#include "SetOfInts3.h"
#include <iostream>

using namespace std;

int main(){
	SetOfInts3 *s =  new SetOfInts3();
	cin >> *s;
	cout << *s << endl;
	delete s;
	return 0;
}

