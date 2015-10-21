//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
using namespace __gnu_pbds;
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

struct Edge {
	int to,next,v;
	Edge(int _to=0,int _v=0,int _next=0):to(_to),v(_v),next(_next){}
};
int ecnt=2;
const int maxn=1005;
Edge edge[maxn*maxn];
bool del[maxn*maxn];
int head[maxn];
int dist[3][maxn];
int pre[maxn];
int ans=0;
int n,m;
typedef pair<int,int> Pos;
#define pos second
typedef __gnu_pbds::priority_queue<Pos,greater<Pos> > heap; 
heap::point_iterator id[maxn];
const int INF=0x3f3f3f3f;
void add_edge(int u,int v,int w) {
	edge[ecnt].to=v; edge[ecnt].v=w; edge[ecnt].next=head[u]; head[u]=ecnt++;
	edge[ecnt].to=u; edge[ecnt].v=w; edge[ecnt].next=head[v]; head[v]=ecnt++;
}

void dijkstra() {
	memset(dist[0],0x3f,sizeof(dist[0]));
	int k=0;
	memset(id,0,sizeof(id));
	heap pq;
	dist[k][1]=0; id[1]=pq.push(mp(0,1));
	while(pq.size()) {
		int cur=pq.top().pos; pq.pop();
		for(int i=head[cur];i;i=edge[i].next) {
			int v=edge[i].to;
			if(dist[k][v]> dist[k][cur]+ edge[i].v) {
				dist[k][v]=dist[k][cur]+edge[i].v;
				pre[v]=cur;
				if(id[v]!=0) {
					pq.modify(id[v],mp(dist[k][v],v));
				} else {
					id[v]=pq.push(mp(dist[k][v],v));
				}
			}
		}
	}
}
int dijk(int u,int v) {
	memset(dist[1],0x3f,sizeof(dist[1])); int k=1;
	memset(id,0,sizeof(id));
	heap pq;
	while(pq.size()) pq.pop();
	dist[k][1]=0; id[1]=pq.push(mp(0,1));
	while(pq.size()!=0) {
		int cur=pq.top().pos; pq.pop();
		for(int i=head[cur];i;i=edge[i].next) {
			int to=edge[i].to; if(u==cur&&to==v) continue;
			if(dist[k][to]>dist[k][cur]+edge[i].v) {
				dist[k][to]=dist[k][cur]+edge[i].v;
				if(id[to]!=0) {
					pq.modify(id[to],mp(dist[k][to],to));
				} else {
					id[to]=pq.push(mp(dist[k][to],to));
				}
			}
		}
	}
	return dist[k][n];
}
vector<int> sp;
void dfs(int k) {
	if(k==1) return ;
	sp.pb(pre[k]);
	dfs(pre[k]);
}


int main() {
	R(n); R(m);
	for(int i=1;i<=m;++i) {
		int a,b,v; R(a); R(b); R(v);
		add_edge(a,b,v);
	}
	dijkstra();
	sp.pb(n);
	dfs(n);
	for(int i=0;i<sp.size();++i) { //del the edge between sp[i] and pre[sp[i]]
			int temp=dijk(pre[sp[i]],sp[i]);	
			ans=max(ans,temp);
	}
	Pn(ans);
}
