//Author Javi

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
  int p,v,n;
  for (p=v=0,n=1; n<N-1; n++){
    p += (A[n-1]<A[n]&&A[n+1]<A[n]);
    v += (A[n-1]>A[n]&&A[n+1]>A[n]);
  }
  cout << p <<" "<< v << endl;
}
#endif
int main(int argc, char **argv)
{
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
