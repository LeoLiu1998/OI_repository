#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))

char A[11001], B[11001];
int nA, nB;
unsigned short C[11001][11001];
int X, Y, Z;

int main(void)
{
  int i, j, n;
  
  freopen ("landscape.in", "r", stdin);
  freopen ("landscape.out", "w", stdout);

  scanf ("%d %d %d %d", &n, &X, &Y, &Z);
  for (i=0; i<n; i++) {
    scanf ("%d", &j); while (j>0) { A[++nA] = i; j--; } 
    scanf ("%d", &j); while (j>0) { B[++nB] = i; j--; } 
  }
  
  for (j=0; j<=nB; j++) C[0][j] = j*X;
  for (i=0; i<=nA; i++) C[i][0] = i*Y;

  for (i=1; i<=nA; i++)
    for (j=1; j<=nB; j++) {
      C[i][j] = INF;
      C[i][j] = MIN(C[i][j], C[i][j-1] + X);
      C[i][j] = MIN(C[i][j], C[i-1][j] + Y);
      C[i][j] = MIN(C[i][j], C[i-1][j-1] + Z * ABS(A[i]-B[j]));
    }
  
 cout<<C[nA][nB]<<endl; 
  //printf ("%d\n", C[nA][nB]);
  return 0;
}
