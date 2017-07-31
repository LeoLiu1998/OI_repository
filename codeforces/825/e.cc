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

typedef vector<int> Node;
const int maxn=100050;
int out[maxn],ans[maxn];
Node node[maxn];
priority_queue<int> pq;
int n,m;
int main() {
	R(n); R(m);
	for(int i=1;i<=m;++i) {
		int l,r;
		R(l); R(r);
		out[l]++;
		node[r].pb(l);
	}
	rep(i,1,n,1) {
		if(!out[i]) {
			pq.push(i);
		}
	}
	int cur=n;
	while(pq.size()) {
		int v=pq.top(); pq.pop();
		ans[v]=cur--;
		for(int i=0;i<node[v].size();++i) {
			int t=node[v][i];
			out[t]--;
			if(!out[t]) pq.push(t);
		}
	}
	rep(i,1,n,1) Ps(ans[i]);
	puts("");
}

