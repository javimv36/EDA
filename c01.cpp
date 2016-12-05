//Author Javi
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000


/*
mplementa una funcion que cumpla la siguiente especi cacion:
{b >1^n >1}
fun log(intb,intn)
return int r
{b^r-1<n<=b^r}
*/
void solve(unsigned long b, unsigned log n){

}

int main(int argc, char **argv)
{
  int c; //casos a probar
  int b;
  int n;

  cin >> c;
  for (int i=0; i<c; i++){
    cin >> b;
    cin >> n;
    solve(b,n);
  }
  return 0;
}
