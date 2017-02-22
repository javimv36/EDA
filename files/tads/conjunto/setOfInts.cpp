#include <iostream>
using namespace std;

#include "Error.h"
#include "SetOfInts.h"

class SetOfInts{

private:
  static const int MAXSIZE = 5;
  int elems[MAXSIZE];
  int size;

public:
  SetOfInts::SetOfInts(){
    size = 0;
  }
  void SetOfInts::add(int x) throw (Error){
    if(isFull()) throws Error("No se ha podido añadir elemento: El paquete esta lleno.");
    else{
      elems[size]=x;
      size++;
    }
  }

  bool SetOfInts::cointains(int x) const {
    bool found;
    int pos;
    linSearch(x,0,size,found,pos);
    return found;
  }

  void SetOfInts::remove(int x){
    bool found;
    int pos;
    linSearch(x,0,size,found,pos);
    while(found){
      size --;
      elems[pos]=elems[size];
      linSearch(x,pos,size,found,pos);
    }
  }

  void SetOfInts::linSearch(int x, int i, int s, bool f, int pos){

  }
}
