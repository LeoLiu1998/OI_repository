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
const int maxn=400050;
pii a[maxn];
pii l[maxn];
pii r[maxn];
bool vis[maxn];
int n,k,cnt;
typedef vector<int> Node;
//priority_queue<Node,vector<Node>,greater<Node> >pq;
vector<Node> pq;
Node temp;
void NP(const Node &x) {
	if(!x.size()) return ;
	for(int i=0;i<x.size()-1;++i) {
		Ps(x[i]);
	}
	Pn(x[x.size()-1]);
}
void print() {
	temp.clear();
	for(int i=1;i<=n;++i) {
		if(vis[i]) {
			temp.pb(i);
		}
	}
	if(temp.empty()) return ;
//	NP(temp);
	pq.pb(temp);
}
int main() {
	R(n); R(k);
	k--;
	for(int i=1;i<=n;++i) {
		R(a[i].fi); R(a[i].se);
	}
//	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		l[i].fi=a[i].fi;
		r[i].fi=a[i].se;
		l[i].se=r[i].se=i;
	}
	r[n+1].fi=l[n+1].fi=INT_MAX;
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	int i=0;
	do {
		if(l[l[0].fi+1].fi<r[r[0].fi+1].fi) {
			l[0].fi++;
			i=l[l[0].fi].fi;
			vis[l[l[0].fi].se]=1;
			if((l[l[0].fi+1].fi!=i)&&(r[r[0].fi+1].fi!=i)) 
				print();	
		} else {
			r[0].fi++;
			i=r[r[0].fi].fi;
			vis[r[r[0].fi].se]=0;
			if((r[r[0].fi+1].fi!=i)&&(l[l[0].fi+1].fi!=i)) 
				print();
		}
	}while((r[0].fi!=n)&&(cnt<k));
	sort(pq.begin(),pq.end());
	unique(pq.begin(),pq.end());
	Pn(pq[k].size());
	NP(pq[k]);	
/*	for(int i=0;i<pq.size();++i) {
		NP(pq[i]);
	}*/
}


