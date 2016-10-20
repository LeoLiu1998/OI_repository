#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 100010 ;
int n ,m ;
char s[MAXN]; 

bool check(int x) { 
  int last = 0 ; 
  for (int i = 1;i <= n;i ++) {
    if (s[i] - 'a' <= x) last = i ; 
    if (i - last >= m) return 0 ; 
  }
  return 1 ; 
}

int cnt[30] ; 

void Solve(int x) { 
  for (int i = 1;i <= n;i ++) { 
    if (s[i] - 'a' < x) cnt[s[i] - 'a'] ++ ; 
  }
  int lastx = 0, last = 0 ; 
  for (int i = 1;i <= n;i ++) { 
    if (s[i] - 'a' < x) last = i ; 
    if (s[i] - 'a' == x) lastx = i ; 
    if (i - last >= m) { 
      last = lastx ;
      cnt[x] ++ ;
    }
  }
  for (int i = 0;i <= x;i ++) while (cnt[i] --)  putchar('a' + i) ;
  putchar(10) ; 
} 


int main() {
	R(m);
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,0,25,i) {
	
	}
}


int main() {
#ifdef YJQ_LOCAL
  freopen(".in", "r", stdin) ;
#endif
  scanf("%d", &m);
  scanf("%s", s + 1) ;
  n = strlen(s + 1) ; 
  for (int i = 0;i < 26;i ++) {
    if (check(i)) {
      Solve(i) ;
      break ; 
    }
  }
}
