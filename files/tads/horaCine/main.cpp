#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
#include "Error.h"
#include "pelicula.h"

bool ordenPorFinalizacion(const Pelicula &p1, const Pelicula &p2)
{
    return (p1<p2);
}

void solve(Pelicula V[], int n)
{
    try
    {
        //ordenar v por horaFin
        //horaFIN = (v[i]._horaInicio+v[i]._duracion)
        sort(V, V + n, ordenPorFinalizacion);

        for (int i = 0; i < n; i++)
        {
            Hora fin = V[i].getFin();
            string nombre = V[i].getNombre();
            cout << fin << " " << nombre << endl;
        }
    }
    catch (Error e)
    {
        cout << e.getMessage() << endl;
    }
}

int main()
{
    int n;
    Pelicula V[MAX];
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> V[i];
        }
        solve(V, n);
        cout << "---" << endl;
        cin >> n;
    }
    return 0;
}