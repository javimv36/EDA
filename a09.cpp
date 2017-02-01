//Author Javi

/*

Problem: Soy rico

  pseudo code

}
*/

#include <iostream>
using namespace std;

int isolve (int i);
int solve(int n);

int main(int argc, char **argv)
{
  int n;
  int N;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> N;
    cout << solve(N) << endl;
  }
  return 0;
}

int solve(int n){
    int i, s, s1,s2,s0;
    for(i=0,s=0;s<n;i++){
        if (i == 0){
          s2=1;
          s+=s2;
        }else if(i==1){
          s1=1;
          s+=s1;
        }
        else{
          s0=s1+2*s2;
          s+=s0;
          s2=s1;
          s1=s0;
        }
    }
 return i;
}

