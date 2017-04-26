#include "Polinomio.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    Polinomio polinomio;
    cin >> polinomio;
    for (int i = 0; i < polinomio.getGrado(); i++)
    {
        int c = polinomio.getCoef(i);
        cout << c << " ";
    }
    char d = 'd';
    cout << "Write something to exit";
    cin >> d;
    return 0;
}
