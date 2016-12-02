/*
{
  P : N>=0 , V=A[0..N)
  Q : V=sorted(A)
}
fun mergeSort(V) dev C
  case size(V) <= 1 : V
       size(V) > 1  :
                      let h=N/2
		          V1=mergeSort(V[0..h))
			  V2=mergeSort(V[h..N))
		      in
		          merge(V1,V2)
  esac


{
   P : j1+1>=i1 and j2+1>=i2  Even empty
   Q :sorted(V3)
fun merge(V1[i1..j1],V2[i2..j2]  dev V3[i1..(j1-i1)+(j2-i2)+2]
{
   n=i1
   while (i1 <= j1) and (i2 <= j2)
      if V[i1] <= V[i2]
          V[n]=V[i1]
	  i1=i1+1
      else
          V[n]=V[i2]
	  i2=i2+1
      n=n+1
   while (i2 <= j2)
      V[n]=V[i2]
      n,i2=n+1,i2+1
   while (i1 <= j1)
      V[n]=V[i1]
      n,i1=n+1,i1+1
}
*/

#include <iostream>  // cin, cout
#include <algorithm> // max, min
#include <cstdlib> // abs

#define  MAX 10000

using namespace std;

// The C-Code has a different flavour.

int merge(const int* v1, int len1,
	  const int* v2, int len2,
	  int* v3)
{
  int n,i1,i2;
  for (n=i1=i2=0; (i1<len1) && (i2<len2) ; n++)
    {
      if (v1[i1] <= v2[i2])
	v3[n]=v1[i1++];
      else
	v3[n]=v2[i2++] ;
    }
  for ( ; (i2<len2) ; n++) v3[n]=v2[i2++];
  for ( ; (i1<len1) ; n++) v3[n]=v1[i1++];

  return n ;
}

int mergeSort(const int* A,int len,int *V)
{
  switch(len)
    {
    case 0 :
      return 0;
    case 1 :
      V[0]=A[0];
      return 1;
    default:
      {
	int AUX[MAX]; // Can use malloc for finer approach.
	int h=len/2;
	mergeSort(A,h,AUX);
	mergeSort(A+h,len-h,AUX+h);
	return merge(AUX,h,AUX+h,len-h,V);
      }
    }
}

/*
   P : len>=2 and sorted(AA)
*/
int isolve(const int AA[],int len)
{
  int h, m1, m2;
  if (len==2)
    return abs(AA[0]-AA[1]);
  if (len==3)
    return min(isolve(AA, 2), isolve(AA+h, 2));
  else {
    h=(len/2);
    m1=isolve(AA, h);
    m2=isolve(AA+h, h);
    return min(m1, min(m2,  isolve(AA+h-1, 2)));
  }
}


int solve(const int A[],int len)
{
  int V[MAX];
  mergeSort(A,len,V);
  return isolve(V,len);
}


int main(int argc, char **argv)
{
  int n;
  int N;
  int A[MAX];
  int S[MAX];
  cin >> n;
  for (int i=0; i < n ; i++)
    {
      cin >> N  ;
      for (int j=0; j < N ; j++)
	cin >> A[j];
      cout << solve(A,N) << endl;
    }
  return 0;
}
