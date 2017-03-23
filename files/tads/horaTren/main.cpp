#include <iostream>
#include "Hora.h"
#define MAX 10000
using namespace std;

int solve(Hora V[], int nTrenes, Hora consulta)
{
    int i;
    for (i = 0; i <= nTrenes && V[i] < consulta; i++)
        ;
    return i;
}

int main()
{
    int nTrenes, nConsultas;
    Hora V[MAX];
    Hora consulta;
    int pos;
    cin >> nTrenes;
    cin >> nConsultas;
    while (nTrenes != 0 || nConsultas != 0)
    {
        for (int i = 0; i < nTrenes; i++)
        {
            cin >> V[i];
        }

        for (int i = 0; i < nConsultas; i++)
        {
            cin >> consulta;
            pos = solve(V, nTrenes, consulta);
            if (pos < nTrenes)
                cout << V[pos];
            else
                cout << "NO" << endl;
        }
        cout << "---" << endl;
        cin >> nTrenes;
        cin >> nConsultas;
    }
    return 0;
}