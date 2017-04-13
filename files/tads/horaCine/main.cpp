#include <iostream>
#define MAX 10000
using namespace std;
#include "Error.h"
#include "pelicula.h"

int solve(Pelicula V[], int n)
{
    try
    {
    }
    catch (Error e)
    {
        cout << e.getMessage() << endl;
    }
    return 0;
}

int main()
{
    int n;
    Pelicula V[MAX];
    int pos;
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> V[i];
        }
        //solve(V, n);
        for (int i = 0; i < n; i++)
        {
            cout << V[i];
        }
        cout << "---" << endl;
    }
    return 0;
}