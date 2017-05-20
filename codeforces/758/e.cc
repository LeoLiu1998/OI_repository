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
struct Edge {
	int u,v,nex;
	ll w,p;
	Edge(int _u=0,int _v=0,int _nex=0,ll _w=0,ll _p=0): u(_u), v(_v),nex(_nex),w(_w),p(_p) {};
};
const int maxn=400050;
Edge edge[maxn];
int head[maxn];
int ecnt=0;
int f[maxn];
ll wmax[maxn],wmin[maxn],tot[maxn];
inline void add_edge(int u,int v, int w, int p) {
	f[v]=u; edge[++ecnt].nex=head[u]; edge[ecnt].u=u; edge[ecnt].v=v; edge[ecnt].w=w; edge[ecnt].p=p; head[u]=ecnt;
}
ll d[maxn];
int n;

void dfs(int k) {
	int v=edge[k].v;
	ll ma=0,mi=0;
	for(int i=head[v];i;i=edge[i].nex) {
		dfs(i);
		ma+=wmax[i];
		mi+=wmin[i];
		tot[k]+=tot[i];
	}
	if(mi>edge[k].p) {
		puts("-1");
		exit(0);
	}
	tot[k]+=edge[k].w;
	wmin[k]=mi+edge[k].w - min(edge[k].p-mi,edge[k].w);
	wmax[k]=min(edge[k].p,ma)+edge[k].w;//ge[k].w
	d[k]=tot[k]-wmax[k];
}
ll dfs(int k,ll sum) {
/*	ll to=0;
	int v=edge[k].v;
	for(int i=head[v];i;i=edge[v].nex) {
		
	}*/
}
int main() {
	R(n);
	for(int i=1;i<n;++i) {
		int x,y,w,p;
		R(x); R(y); R(w); R(p);
		add_edge(x,y,w,p);
	}
	for(int i=head[1];i;i=edge[i].nex) {
		dfs(i);
//		dfs(i,LLONG_MAX);
	}
	for(int i=1;i<n;++i) {
		Ps(edge[i].u); Ps(edge[i].v);
		ll d=tot[i]-wmax[i];
		cout<<edge[i].w-d<<" "<<edge[i].p-d<<endl;
	}
}

