/*
Copyright (C) 2017 javimv36 
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. 
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>
*/

/*

  pseudo code

  fun(A[],N){
    int v,p=0
    int i=1
    while(i<N){
      if (A[i-1]>A[i]&&A[i+1]>A[i])v++;
      else if (A[i-1]<A[i]&&A[i+1]<A[i])p++
      i++
    }
    return p, v;
  }

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000


#define REC
#ifdef REC
int isolve(int A[], int N, int n, int *p, int *v){
  if (n>=N) return;
  else{
    *p+=(A[n-1]<A[n]&&A[n+1]<A[n]);
    *v+=(A[n-1]>A[n]&&A[n+1]>A[n]);
    isolve(A,N,n+1,p,v);
    return;
  }
}

int solve(int A[], int N, int *p, int *v){
  return isolve(A, N, 1,p,v);
}

#else
void solve(int A[], int N){
  int n;
  for (p=v=0,n=1; n<N-1; n++){
    p += (A[n-1]<A[n]&&A[n+1]<A[n]);
    v += (A[n-1]>A[n]&&A[n+1]>A[n]);
  }
  cout << p <<" "<< v << endl;
}
#endif
int main(int argc, char **argv)
{
  int p,v;
  int n;
  int N;
  int A[MAX];

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    for (int j=0; j<N; j++) cin >> A[j];
    solve(A,N);
  }
  return 0;
}