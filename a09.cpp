//Author Javi

/*

Problem: Soy rico

  pseudo code

solve(d){
 if (d==1||d==2) p+=1;
 else p+=2*(solve(d-1)*solve(d-2));
 return p;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

int solve(int d){
 if (d==1||d==2) p+=1;
 else p+=2*(solve(d-1)*solve(d-2));
 return p;
}

int main(int argc, char **argv)
{
  int n;
  int N;

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    cout << solve(n) << endl;
  }
  return 0;
}
