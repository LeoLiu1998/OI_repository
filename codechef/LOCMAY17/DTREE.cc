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
#define CL(x) memset(x,0,sizeof(x))
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
vector<pii> node[100050];
bool vis[100050];
int dist[100050];
int prev[100050];
int T,n;
int main() {
	R(T);
	while(T--) {
		R(n);
		memset(vis,0,sizeof vis);
		memset(node,0,sizeof node);
		memset(prev,0,sizeof prev);
		for(int i=1;i<=n;++i) {
			int l,r;
			R(l); R(r);
			node[l].pb(mp(r,-1));
			node[r].pb(mp(l,-1));
		}

	}
}

