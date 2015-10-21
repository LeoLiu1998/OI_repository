//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp(a,b) make_pair(b,a)
#define pb push_back
typedef long long ll;
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
#define to second
#define v first
const int maxn=1000000;
const ll INF=9000000000000000000LL;
typedef pair<ll,int> Edge;
typedef pair<int,int> pii;
typedef vector<pii> Point;
Point p[maxn];
ll dist[maxn];
ll n,m;
ll x,y,z,a,b;
ll T,rxa,rxc,rya,ryc,rp;
__gnu_pbds::priority_queue<Edge,greater<Edge>,pairing_heap_tag > pq;
__gnu_pbds::priority_queue<Edge,greater<Edge>,pairing_heap_tag>::point_iterator id[maxn+5];
void dijkstra() {
	rep(i,1,n,1) dist[i]=INF; 
	dist[1]=0;id[1]=pq.push(mp((ll)1,(ll)0));
	while(pq.size()) {
		Edge u=pq.top();
		pq.pop();
		for(int i=0;i<(int)p[u.to].size();++i) {
			Edge v=p[u.to][i];
			ll alt=dist[u.to]+v.v;
			if(alt< dist[v.to]) {
				dist[v.to]=alt;
				if(id[v.to]!=0) {
					pq.modify(id[v.to],mp(v.to,alt));
				} else {
					id[v.to]=pq.push(mp(v.to,alt));
				}
			}
		}
	}
	cout<<dist[n]<<endl;
}

int main() {
	R(n); R(m);
	R(T); R(rxa); R(rxc); R(rya); R(ryc); R(rp);
	for(int i=1;i<=T;++i) {	//	while(T--) {
		x=(x*rxa+rxc)%rp;
		y=(y*rya+ryc)%rp;
		a=min(x%n+1,y%n+1);
		b=max(y%n+1,y%n+1);
		p[a].pb(mp(b,1e8-100*a));
	}
	for(int i=T+1;i<=m;++i) {
		R(x); R(y); R(z);
		p[x].pb(mp(y,z));
	}
	dijkstra();
}
