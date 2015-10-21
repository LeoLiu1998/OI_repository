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

struct Edge{
	int to,v;
	Edge(int _to=0,int _v=0) {
		to=_to; v=_v;
	}
};
typedef vector<Edge> Point;
const int maxn=10000;
Point p[maxn+1];
int dist[maxn+1];
bool been[maxn+1];
int n,m,k;
int INF=-5461;

void input();
bool SPFA(int);

int main() {
	input();
	if(!SPFA(INF)){
		Pn(-1);
	} else if(SPFA(0)) {
		Pn(0);
	} else {
		int l=0,r=INF;
		while(l+1!=r) { 
			int mid=(l+r)>>1;
			if(SPFA(mid)) {
				r=mid;
			} else {
				l=mid;
			}
		}
		Pn(r);
	}
}

void input() {
	R(n); R(m); R(k);
	for(register int i=1,l,r,v;i<=m;++i) {
		R(l); R(r); R(v);
		INF=max(INF,v);
		p[l].pb(Edge(r,v));
		p[r].pb(Edge(l,v));
	}

}
typedef pair<int,int> pii;
queue<int> q;
bool SPFA(int c) {
	memset(been,0,sizeof(been));
	memset(dist,0x3f,sizeof(dist)); 
	while(q.size()) q.pop();
	dist[1]=0; q.push(1); been[1]=0;
	while(q.size()) {
		int qf=q.front();
		for(int i=0;i<(int)p[qf].size();++i) {
			 Edge cur=p[qf][i];
			 int u=cur.to;
			 if(dist[u]>dist[qf]+(cur.v > c))  {
			 	dist[u]=dist[qf]+(cur.v > c);
				if(!been[u]) {
					q.push(u);
					been[u]=1;
				}
			 }
		}
		q.pop();
		been[qf]=0;
	}
	return dist[n]<=k;
}

/*void SPFA() {
	queue<pii> q; memset(dist,0x3f,sizeof(dist));
	dist[1][0]=0;
	q.push(mp(1,0)); been[1][0]=1;
	while(q.size()) {
		pii qf=q.front();
		for(int i=0;i<(int)p[qf.first].size();++i) {
			int cur=p[qf.first][i].to;
			if(dist[cur][qf.second]>dist[qf.first][qf.second]+p[qf.first][i].v) {
				dist[cur][qf.second]=dist[qf.first][qf.second]+p[qf.first][i].v;
				if(!been[cur][qf.second]) {
					been[cur][qf.second]=1;
					q.push(mp(cur,qf.second));
				}
			}
			if(dist[cur][qf.second+1]>dist[qf.first][qf.second]&&qf.second<k) {
				dist[cur][qf.second+1]=dist[qf.first][qf.second];
				if(!been[cur][qf.second+1]) {
					been[cur][qf.second+1]=1;
					q.push(mp(cur,qf.second+1));
				}
			}
		}
		q.pop();
		been[qf.first][qf.second]=0;
	}
	for(int i=0;i<=k;++i) ans=min(ans,dist[n][i]);

}*/
