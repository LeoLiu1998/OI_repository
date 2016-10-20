#include <bits/stdc++.h>

using namespace std ;

int n, d, MOD ; 

const int MAXN = 1010 ;
const int MAXD = 11; 

int dp[MAXN][MAXN][MAXD] ;

int Inv[MAXN] ;

inline void update(int &a, int b) {
  a += b ;
  if (a >= MOD) a -= MOD ; 
}
int qpow(int a,int b) {
  int tmp = a, ret = 1; 
  for (; b; b >>= 1, tmp = 1LL * tmp * tmp % MOD ){
    if (b & 1) ret = 1LL * ret * tmp % MOD ; 
  }
  return ret;
}

void Init() {
  for (int i = 1; i <= 1000; i ++) {
    Inv[i] = qpow(i, MOD - 2) ; 
  }
}

int f[MAXN] ; 
void Dodp() {
  f[1] = 1; 
  dp[0][0][0] = 1; 
  for (int j = 0;j <= d;j ++) {
    dp[1][j][j] = 1 ; 
  }
  for (int i = 2; i + i <= n; i ++) { 
    f[i] = dp[i - 1][i - 1][d - 1] ; 
    for (int k = 0; k <= d; k ++) { 
      for (int j = 0; j <= n; j ++) { 
        if (dp[i - 1][j][k]) {
          int tmp = dp[i - 1][j][k] ; 
          for (int use = 0; j + use * i <= n && use + k <= d && tmp; use ++) {
            update(dp[i][j + use * i][use + k], tmp) ; 
               tmp = 1LL * tmp * (f[i] + use) % MOD * Inv[use + 1] % MOD ; 
          }
        }
      }
    }
  }
}

void Solve() {
  if (n <= 2) {
    puts("1");
    return ; 
  }
  if (n & 1) {
    printf("%d\n", dp[n >> 1][n - 1][d]) ; 
  }
  else {
    int ans = dp[(n >> 1) - 1][n - 1][d], tmp = f[n >> 1] ; 
    tmp = 1LL * (tmp + 1) * tmp % MOD * Inv[2] % MOD ; 
    ans = (ans + tmp) % MOD ; 
    printf("%d\n", ans) ; 
  }
}

  

            

int main() {
#ifdef YJQ_LOCAL
  freopen(".in", "r", stdin) ;
#endif 
  scanf("%d%d%d", &n, &d, &MOD) ; 
  Init() ; 
  Dodp() ; 
  Solve() ; 
}