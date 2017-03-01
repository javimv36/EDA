/*
P={n<=0 && v=V}
int partition(int* v, int n) (:out)
Q={
  (forall k1 : 0 <= k1 < out : v[k1]>=0)
  &&
  (forall k2 : out <= k2 < n : v[k2]<0)
  &&
  (permutacion(v,V,n))
}

donde permutacion(v,w,n) = forall i : i<n : frec(v[i], v, n) = frec(v[i], w, n)
donde frec(...) = #i (conteo de elementos en el vector)

Invariante:

I={
  (forall k1 : 0 <= k1 <= i : v[k1] >=0)
  &&
  (forall k2 : j < k2 < n : v[k2] <0)
  &&
  (0 <= i <= n)
  &&
  (-1 <= j <= n)
  &&
  (permutacion(v,V,n))
}
*/
#include <iostream>
#define MAX 10000
using namespace std;

void swap(int v[], int i, int j){
  int c = v[i];
  v[i]=v[j];
  v[j]=c;
}

int solve(int v[], int n){
  int i = 0;
  int j = n-1;
  while(i<j){
    if(v[i]<0 && v[j] >=0){
        swap(v,i,j);
        i++;
        j--;
    }
    else if (v[i]>=0) i++;
    else if (v[j]<0) j--;
  }
  return i;
}

int main(){
  int v[MAX];
  int n;
  cin >> n;
  for (int i=0; i<n; i++) cin >> v[i];
  cout << solve(v,n) << endl;
  for (int i=0; i<n; i++) cout << v[i] << " ";
  cout << endl;
}
