#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;


int main(){
  int numCasos;
  int n;
  int pringao;
  cin >> numCasos;
  for (int i = 0; i < numCasos; i++){
    Queue<int>* q = new Queue<int>();
    cin >> n;
    while (n != -1){
      q->push_back(n);
      cin >> n;
    }

    cin >> pringao;
    Queue<int>* colegas = new Queue<int>();
    cin >> n;
    while (n != -1){
      colegas->push_back(n);
      cin >> n;
    }

    cout << *q;
    q->jump(pringao,*colegas);
    cout << *q;
    delete q;
    delete colegas;
  }
}
