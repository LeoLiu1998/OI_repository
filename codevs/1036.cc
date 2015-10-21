//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}


const int maxn=30005;
const int maxe=maxn<<1;
int deep[maxn];
int p[maxn][22];

int head[maxn],to[maxe],next[maxe];
int n,ecnt=2;

void add_edge(int u,int v) {
	to[ecnt]=v; next[ecnt]=head[u]; head[u]=ecnt++;
	to[ecnt]=u; next[ecnt]=head[v]; head[v]=ecnt++;
}

void dfs(int k) {
	for(int i=head[k];i;i=next[i]) {
		int cur=to[i];
		if(!deep[cur]) {
			deep[cur]=deep[k]+1;
			p[cur][0]=k;
			dfs(cur);
		}
	}
}

void init() {
	for(int i=1;(1<<i)<=n;++i) {
		for(int j=1;j<=n;++j) {
			p[j][i]=p[p[j][i-1]][i-1];		
		}
	}
}

int LCA(int a,int b) {
	if(deep[a]<deep[b]) swap(a,b); //a is deeper than b
	int del=deep[a]-deep[b];
	for(int i=0;i<=15;++i) {
		if((1<<i)&del) {
			a=p[a][i];
		}
	}
	if(a==b) return a;
	assert(deep[a]==deep[b]);
	for(int i=20;i>=0;--i) {
		if(p[a][i]!=p[b][i]) {
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}

int main() {
	R(n);
	rep(i,1,n-1,1) {
		int a,b;
		R(a); R(b);
		add_edge(a,b);
	}
	deep[1]=1;
	dfs(1);
	init();
	int cur=1;
	int m;R(m);
	int ans=0;
	while(m--)  {
		int t; R(t);
		int lca=LCA(cur,t);
//		Pn(lca);
		ans+= deep[cur]+deep[t]-2*deep[lca];
		cur=t;
	}
	Pn(ans);
}

