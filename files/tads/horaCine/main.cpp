#include <iostream>
#include "Hora.h"
#define MAX 10000
using namespace std;
#include "Error.h"

int solve(Hora V[], int nTrenes, Hora consulta)
{
    int i;
    for (i = 0; i <= nTrenes && V[i] < consulta; i++);
    return i;
}

int main()
{
    int nTrenes, nConsultas;
    Hora V[MAX];
    Hora consulta;
    Hora consulta2;
    int pos;
    cin >> nTrenes;
    cin >> nConsultas;
    while (nTrenes != 0 || nConsultas != 0)
    {
        cin << consulta;
        cin << consulta2;
        cout << consulta+consulta2 << endl;
       /*
        for (int i = 0; i < nTrenes; i++)
        {
            cin >> V[i];
        }

        for (int i = 0; i < nConsultas; i++)
        {
            try
            {
                cin >> consulta;
                pos = solve(V, nTrenes, consulta);
                if (pos < nTrenes)
                    cout << V[pos];
                else
                    cout << "NO" << endl;
            }
            catch (Error e)
            {
                cout << e.getMessage() << endl;
            }
        }
        
        cout << "---" << endl;
        cin >> nTrenes;
        cin >> nConsultas;
        */
    }
    return 0;
}