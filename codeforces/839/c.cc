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
typedef vector<int> Node;
Node node[100500];
int f[100500];
Node s[100500];
double dp[100500];
int n;

void dfs(int x) {
	for(auto v:node[x]) {
		if(v==f[x]) continue;
		f[v]=x;
		s[x].pb(v);
		dfs(v);
	}
	if(!s[x].size()) {
		dp[x]=0;
	} else {
		double cur=0;
		for(auto v:s[x]) {
			cur+=dp[v];
		}
		cur/=s[x].size();
		dp[x]=cur+1;
	}
}
int main() {
	R(n);
	for(int i=1;i<n;++i) {
		int l,r; R(l); R(r);
		node[l].pb(r);
		node[r].pb(l);
	}
	dfs(1);
	printf("%0.10f\n",dp[1]);
}

