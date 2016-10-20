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
const int maxn=200500;
const ll mod=1e9+7;
ll qpow(int k) {
	ll a=2;
	ll ret=1;
	while(k) {
		if(k&1)ret=ret*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return ret;
}
int head[maxn],to[maxn],nxt[maxn];
int ecnt=0;
void add_egde(int u,int v) {
	to[ecnt]=v; nxt[ecnt]=head[u]; head[u]=ecnt++;
	to[ecnt]=u; nxt[ecnt]=head[v]; head[v]=ecnt++;
}
int vis[maxn];
int depth[maxn];
ll ans=1;
int c_s=0;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		add_edge(i,a[i]);
	}
	for(int i=1;i<=n;++i) {
		if(vis[i]) continue;
		c_s=0;
		dfs(1,i);
	}
}

