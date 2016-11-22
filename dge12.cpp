//Author Javi

/*
  pseudo code
  fun(A[],N,a){
   i,o,f,l;
   while(i<N){
    if(A[i]<=a){
       o=i+1;	
       
    }
    if(l<(i+1-o)){
       l=(i+1-o);
    }		
    i++;
   }
   f=o+l-1;
  }
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

void solve(int A[], int N, int a){
  int i, o, f, l;
  for (i=o=f=l=0; i<N; i++){
	if(A[i]<=a)o=i+1;
	if(l<(i+1-o))l=(i+1-o);
  }
  f=o+l-1;
  cout << o << " " << f;
}

int main(int argc, char **argv)
{
  int n;
  int a;
  int N;
  int A[MAX];

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    cin >> a;
    for (int j=0; j<N; j++) cin >> A[j];
    solve(A,N,a);
  }
  return 0;
}
