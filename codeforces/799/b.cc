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
const int maxn=200010;
bool vis[maxn];
int price[maxn];
priority_queue<pii,vector<pii>, greater<pii> > pq[4];
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(price[i]);
	}
	for(int i=1;i<=n;++i) {
		int co; R(co);
		pq[co].push(mp(price[i],i));
	}
	for(int i=1;i<=n;++i) {
		int co; R(co);
		pq[co].push(mp(price[i],i));
	}
	int m; R(m);
	for(int i=1;i<=m;++i) {
		int co; R(co);
		if(!pq[co].size()) {
			Ps(-1);
			continue;
		}
		int ret=pq[co].top().se;
		while(vis[ret]) {
			pq[co].pop();
			if(!pq[co].size()) {
				Ps(-1);
				goto NEX;
			}
			ret=pq[co].top().se;
		}
		vis[ret]=1;
		Ps(price[ret]);
NEX:
		int a;
	}
	puts("");
}

