//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using namespace std;
bool col[15];
char a[15][15];
long long ans = 0;
int n, k;

void dfs(int level, int cnt) {
	if (cnt >= k) {
		ans++;
		return;
	}
	if(level>=n) return ;
	for (int i = level ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((!col[j]) && (a[i][j] == '#')) {
				col[j] = 1;
				dfs(level + 1, cnt + 1);
				col[j] = 1; 
			}
		}
	}
	return;
}

int main() {
	while (scanf("%d%d",&n,&k)&&(n!=-1)) {
		memset(col, 0, sizeof col);
		memset(a,0,sizeof a);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s",a[i]);
		}
		dfs(0, 0);
		Pn(ans);
	} 
	return 0;
} 
