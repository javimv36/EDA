//Author Javi

/*
pseudocode

fun solve(){
  for (i<p) max=max(m,V[i])
  for (j=p+1;j<N) min=min(m,V[j])
  return (max<min);
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000


bool solve(int A[], int n, int p){
  int i, j, M, m;
  for (i=m=0;i<=p; i++)M=max(M,A[i]);
  for (j=p+1, m=A[j]; j<n; j++)m=min(m, A[j]);
  return M<m;
}

int main(int argc, char **argv)
{
  int c; //casos a probar
  int p;
  int n;
  int A[MAX];
  cin >> c;
  for (int i=0; i<c; i++){
    cin >> n;
    cin >> p;
    for (int j=0; j<n; j++) cin >> A[j];
    if (solve(A,n,p)) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
