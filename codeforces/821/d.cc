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
int n,M,k;
bool flit;
const int maxn=10040;
pii p[maxn];
vector<int> vx[maxn];
vector<int> vy[maxn];
int dist[maxn];
priority_queue<pii,vector<pii>,greater<pii> >pq;
map<pii,int >m;
bool Adj(pii a,pii b) {
	if((!flit)&&b==p[k]) return 0;
	if((a.fi!=b.fi)&&(a.se!=b.se)) return 0;
	return (abs(a.fi-b.fi)+abs(a.se-b.se))<=1;
}
int main() {
	R(n); R(M); R(k);
	for(int i=1;i<=k;++i) {
		R(p[i].fi); R(p[i].se);
		vx[p[i].fi].pb(i);
		vy[p[i].se].pb(i);
		m[p[i]]=i;
		if(p[i]==mp(n,M)) flit=1;
	}
	if(!flit) {
	p[++k]=mp(n,M); // fi row ;se col
	m[p[k]]=k;
	vx[p[k].fi].pb(k);
	vy[p[k].se].pb(k);
	}
	memset(dist,0x3f,sizeof dist);
	dist[m[mp(1,1)]]=0;
	pq.push(mp(0,m[mp(1,1)]));
	while(pq.size()) {
		pii cur=pq.top();
		pq.pop();
		if(cur.fi>dist[cur.se]) continue;
		pii pp=p[cur.se];
		for(int i=0;i<vx[pp.fi].size();++i) {
			int to = vx[pp.fi][i];
			if(Adj(pp,p[to])) {
				if(dist[to]<=dist[cur.se]) continue;
				dist[to]=dist[cur.se];
				pq.push(mp(dist[to],to));
			} else {
				if(dist[to]<=dist[cur.se]+1) continue;
				dist[to]=dist[cur.se]+1;
				pq.push(mp(dist[to],to));
			}
		}
		for(int i=0;i<vy[pp.se].size();++i) {
			int to = vy[pp.se][i];
			if(Adj(pp,p[to])) {
				if(dist[to]<=dist[cur.se]) continue;
				dist[to]=dist[cur.se];
				pq.push(mp(dist[to],to));
			} else {
				if(dist[to]<=dist[cur.se]+1) continue;
				dist[to]=dist[cur.se]+1;
				pq.push(mp(dist[to],to));
			}
		}
		for(int i=1;i<=2;++i) {
			for(int j=-1;j<=1;j+=2) {
				int res=i*j;
				int tx=pp.fi+res;
				int ty=pp.se+res;
				if(tx>n||tx<1) goto YYY;
				for(int qwq=0;qwq<vx[tx].size();++qwq) {
					int to=vx[tx][qwq];
					if((!flit)&&(to==k)&&(i==2)) continue;
					if(dist[to]<=dist[cur.se]+1) continue;
					dist[to]=dist[cur.se]+1;
					pq.push(mp(dist[to],to));
				}
YYY:
				if(ty>M||ty<1) continue;
				for(int qwq=0;qwq<vy[ty].size();++qwq) {
					int to=vy[ty][qwq];
					if((!flit)&&(to==k)&&(i==2)) continue;
					if(dist[to]<=dist[cur.se]+1) continue;
					dist[to]=dist[cur.se]+1;
					pq.push(mp(dist[to],to));
				}
			}
		}
		continue;
	}
	Pn((dist[m[mp(n,M)]]>1e8+3)?-1:dist[m[mp(n,M)]]);
#ifdef YGHDEBUG
	Pn(Adj(p[37],p[1]));
#endif
}

