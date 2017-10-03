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
#define PROB
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
int dist[305];
int f[305];
priority_queue<pii,vector<pii>,greater<pii> > pq;
typedef vector<pii> Node;
Node node[305];
int cli[305];
int len[305];
int n,m,c;

void Dijkstra() {
	dist[0]=0;
	f[0]=-1;
	pq.push(mp(0,0));
	while(pq.size()) {
		pii cur=pq.top();
		pq.pop();
		for(auto i:node[cur.se]) {
			int v=i.fi;
			int w=dist[cur.se]+i.se;
			if(w<dist[v]) {
				len[v]=len[cur.se]+1;
				dist[v]=w;
				f[v]=cur.se;
				pq.push(mp(w,v));
			} else if(w==dist[v]) {
				if(len[v]<len[cur.se]+1) {
					len[v]=len[cur.se]+1;
					f[v]=cur.se;
					pq.push(mp(w,v));
				}
			}
		}

	}
}

bool cmp(int a,int b) {
	return dist[a]>dist[b];
}
bool vis[305];
int ans=0;

int main() {
	memset(dist,0x3f,sizeof dist);
	R(n); R(m); R(c);
	rep(i,1,c,1) R(cli[i]);
	rep(i,1,m,1) {
		int u,v,w; R(u); R(v); R(w);
		node[u].pb(mp(v,w));
	}
	Dijkstra();
	sort(cli+1,cli+c+1,cmp);
	rep(i,1,c,1) {
		if(vis[cli[i]])	continue;
		ans++;
		int cur=cli[i];
		do{
			vis[cur]=1;
			cur=f[cur];
		} while(cur!=-1);
	}
	Pn(ans);
}

