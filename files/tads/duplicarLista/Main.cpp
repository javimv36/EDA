#include "Queue.h"
#include <iostream>
using namespace std;
#include <stdlib.h>


bool resuelve(){
    if(!cin){
        return false;
    }else{
        Queue<int>* cola = new Queue<int>();
        int n;
        cin >> n;
        while(n!=0){
            cola->push_back(n);
            cin >> n;
        }
        cola->meDuplico();
        cout << *cola;
        delete cola;
        return true;
    }
}

int main()
{
    while (resuelve()){}
    return 0;
}
