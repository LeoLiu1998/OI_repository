//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include  <functional>
#include <vector>
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif
#include <cctype>
#include <climits>
#include <algorithm>	
using namespace std;
inline void R(int &x) {
	x = 0; int f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}
 
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define px first
#define py second
typedef pair<int,int> pii;
inline void R(pii &x) {
	R(x.first); R(x.second);
}
const int maxn = 100;
int map[maxn+5][maxn+5];
int n, m, t;
pii s, e;
int ans = 0;
pii mov[4] = { mp(0,1),mp(1,0),mp(-1,0),mp(0,-1) };
pii add(pii a, pii b) {
	pii ret;
	ret.first = a.first + b.first;
	ret.second = a.second + b.second;
	return ret;
}
bool check(pii a) {
	if (a.first >= 1 && a.first <= n&&a.second >= 1 && a.second <= m&&map[a.first][a.second]) return 1;
	return 0;
}
int dp[16][101][101];

void DP() {
	dp[0][s.px][s.py]=1;
	for(int k=1;k<=t;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				pii cur=mp(i,j);
				if(map[i][j]==0) continue;
				for(int cnt=0;cnt<4;++cnt) {
					pii temp=add(cur,mov[cnt]);
					if(check(temp)) {
						dp[k][i][j]+=dp[k-1][temp.px][temp.py];
					}
				}
			}
		}
	}
}
int main()
{
	R(n); R(m); R(t);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char cur = getchar();
			while (cur != '.'&&cur != '*') cur = getchar();
			map[i][j] = cur == '.';
		}
		getchar();
	}
	R(s); R(e);
	DP();
	ans=dp[t][e.px][e.py];
	Pn(ans);
	return 0;
}
