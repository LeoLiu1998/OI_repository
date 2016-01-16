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
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=3500,maxm=80000;
vector<int> pre[maxn];
bool done[maxn];
int head[maxn],to[maxm],next[maxm];
long long len[maxm],ecnt=2;
long long dist[2][maxn]; 
int n,m;

void add_edge(int u,int v,int w) {
	to[ecnt]=v; next[ecnt]=head[u]; len[ecnt]=w; head[u]=ecnt++;
}
priority_queue<pair<ll,int> >pq;
void Dijkstra() {
	memset(dist,0xaf,sizeof dist);
	dist[1][0]=dist[1][1]=0; pq.push(mp((ll)0,1));
	while(pq.size()) {
		pair<ll,int> qf=pq.top(); pq.pop();
		long long v=dist[0][qf.second]=dist[1][qf.second]=max(dist[0][qf.second],dist[1][qf.second]);
		for(int i=head[pq.second];i;i=next[i]) {
			
		}
	}
}
int main() {
	R(n); R(m);
	for(int i=1;i<=m;++i) {
		int a,b,v; R(a); R(b); R(v);
		add_edge(a,b,v);
	}
	for(int i=1;i<=n;++i) {
		int k,t; R(k);
		if(!k) done[i]=1;
		while(k--) {
			R(t);
			pre[i].pb(t);
		}
	}
	Dijkstra();
}
