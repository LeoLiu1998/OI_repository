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
const int maxn=100050;
bool b[maxn];
vector<pii> node[maxn];
int f[maxn];
int s[maxn];
pll sum[maxn][2];
ll ans=0;
int n;

void dfs(int k) {
	//sum[k][b[k]].fi=1;
	if(node[k].size()==1&&node[k][0].fi==f[k]) {
		sum[k][b[k]].fi=1;
		return ;
	}
	for(int i=0;i<node[k].size();++i) {
		if(node[k][i].fi==f[k]) continue;
		pii t=node[k][i];
		f[t.fi]=k; s[t.fi]=t.se;
		dfs(t.fi);
		ans+=sum[t.fi][0].se*sum[k][1].fi;
		ans+=sum[t.fi][1].se*sum[k][0].fi;
		ans+=sum[t.fi][0].fi*sum[k][1].se;
		ans+=sum[t.fi][1].fi*sum[k][0].se;
		ans+=t.se*(sum[t.fi][0].fi*sum[k][1].fi+sum[t.fi][1].fi*sum[k][0].fi);
		sum[k][0].fi+=sum[t.fi][0].fi;
		sum[k][0].se+=(sum[t.fi][0].se+sum[t.fi][0].fi*t.se);
		sum[k][1].fi+=sum[t.fi][1].fi;
		sum[k][1].se+=(sum[t.fi][1].se+sum[t.fi][1].fi*t.se);
		ans+=(sum[t.fi][!b[k]].se+sum[t.fi][!b[k]].fi*t.se);
	}
	sum[k][b[k]].fi+=1;
}

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int t; R(t);
		b[i]=t;
	}
	for(int i=1;i<n;++i) {
		int u,v,w; R(u); R(v); R(w);
		node[u].pb(mp(v,w));
		node[v].pb(mp(u,w));
	}
	dfs(1);
	cout<<ans<<endl;
}

