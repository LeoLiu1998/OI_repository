#include <stdio.h>
#define INF 2000000000
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))

int A[8101], B[8101], nA, nB;
int C[8101][8101], X, Y, Z;

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
  
  printf ("%d\n", C[nA][nB]);
  return 0;
}
