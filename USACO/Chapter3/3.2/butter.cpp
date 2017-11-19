/*
USER: yeguang2
LANG: C++14
PROB: butter
*/
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB "butter"
#define next nex
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=803;
const int maxm=1505;
int dist[maxn][maxn];
int to[maxm*2],next[maxm*2],w[maxm*2],from[maxn];
int ecnt=0;
int cow[maxn];
int n,p,m;
void Add_edge(int u,int t,int v) {
	to[++ecnt]=t;
	next[ecnt]=from[u];
	w[ecnt]=v;
	from[u]=ecnt;
}
priority_queue<pii, vector<pii>,greater<pii> >pq;
void Dijkstra(int k) {
	pq.push(mp(0,k));
	dist[k][k]=0;
	while(pq.size()) {
		pii cur=pq.top(); pq.pop();
		int u=cur.se;
		for(int i=from[u];i;i=next[i]) {
			int t=to[i];
			if(dist[k][t]>dist[k][u]+w[i]) {
				dist[k][t]=dist[k][u]+w[i];
				pq.push(mp(dist[k][t],t));
			}
		}
	}
}

int main() {
	Redirect();
	memset(dist,0x3f,sizeof dist);
	R(n); R(p); R(m);
	rep(i,1,n,1) {
		R(cow[i]);
	}
	rep(i,1,m,1) {
		int u,t,v;
		R(u); R(t); R(v);
		Add_edge(u,t,v);
		Add_edge(t,u,v);
	}
	rep(i,1,p,1) {
		Dijkstra(i);
	}
	int ans=INT_MAX;
	rep(i,1,p,1) {
		int cur_ans=0;
		rep(j,1,n,1) {
			cur_ans+=dist[i][cow[j]];
		}
		ans=min(cur_ans,ans);
	}
	Pn(ans);
}


