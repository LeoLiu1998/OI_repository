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
int n,k;
int univ[200500];
int f[200050];
int size[200050];
bool vis[200050];
int mc=1,mm=INT_MAX;
typedef vector<int> Point;
Point point[200050];
void dfs(int k) {
	if(vis[k]) return;
	vis[k]=1;
	int cnt=0;
	int cur_max=0;
	for(int i=0;i<point[k].size();++i) {
		if(!vis[point[k][i]]) {
			dfs(point[k][i]);
			cnt+=size[point[k][i]];
			cur_max=max(size[point[k][i]],cur_max);
		}
	}
	cur_max=max(cur_max,n-cnt-1);
	size[k]=cnt+1;
	if(cur_max<mm) {
		mm=cur_max;
		mc=k;
	}
}
int depth[200050];
void dfs2(int dep,int k) {
	vis[k]=1;
	depth[k]=dep;
	for(int i=0;i<point[k].size();++i) {
		if(!vis[point[k][i]]) {
			dfs2(dep+1,point[k][i]);
		}
	}
	return ;
}
int main() {
	R(n); R(k);
	k*=2;
	rep(i,1,k,1) {
		R(univ[i]);
	}
	for(int i=1;i<n;++i) {
		int a,b;
		R(a); R(b);
		point[a].pb(b);
		point[b].pb(a);
	}
	dfs(1);
	memset(vis,0,sizeof vis);
	dfs2(0,mc);
	ll ans=0;
	for(int i=1;i<=k;++i) {
		ans+=depth[univ[i]];
	}
	cout<<ans<<endl;
}

