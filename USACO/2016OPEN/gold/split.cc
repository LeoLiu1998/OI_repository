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
#define PROB "split"
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
const int maxn=50050;
pii cow[maxn];
int n;
int pmin[maxn],pmax[maxn],smin[maxn],smax[maxn];
ll S;
ll nS=LLONG_MAX;
bool cmp(const pii &a,const pii &b) {
	if(a.se==b.se) return a.fi<b.fi;
	else return a.se<b.se;
}
void Solve(){
	memset(pmax,0,sizeof pmax);
	memset(smax,0,sizeof smax);
	memset(pmin,0x7f,sizeof pmin);
	memset(smin,0x7f,sizeof smin);
	sort(cow+1,cow+n+1,cmp);
	for(int i=1;i<=n;++i) {
		pmax[i]=max(pmax[i-1],cow[i].fi);
		pmin[i]=min(pmin[i-1],cow[i].fi);
	}
	for(int i=n;i;--i) {
		smax[i]=max(smax[i+1],cow[i].fi);
		smin[i]=min(smin[i+1],cow[i].fi);
	}
	for(int i=1;i<n;++i) {
		if(cow[i].se==cow[i+1].se) continue;
		ll s1=(ll)(cow[i].se-cow[1].se)*(pmax[i]-pmin[i]);
		ll s2=(ll)(cow[n].se-cow[i+1].se)*(smax[i+1]-smin[i+1]);
		nS=min(nS,s1+s2);
	}
}
int main() {
	Redirect();
	R(n);
	for(int i=1;i<=n;++i) {
		R(cow[i].fi); R(cow[i].se);
	}
	memset(pmin,0x7f,sizeof pmin);
	memset(smin,0x7f,sizeof smin);
	sort(cow+1,cow+n+1);
	for(int i=1;i<=n;++i) {
		pmax[i]=max(pmax[i-1],cow[i].se);
		pmin[i]=min(pmin[i-1],cow[i].se);
	}
	for(int i=n;i;--i) {
		smax[i]=max(smax[i+1],cow[i].se);
		smin[i]=min(smin[i+1],cow[i].se);
	}
	S=(ll)(cow[n].fi-cow[1].fi)*(pmax[n]-pmin[n]);
	for(int i=1;i<n;++i) {
		if(cow[i].fi==cow[i+1].fi) continue;
		ll s1=(ll)(cow[i].fi-cow[1].fi)*(pmax[i]-pmin[i]);
		ll s2=(ll)(cow[n].fi-cow[i+1].fi)*(smax[i+1]-smin[i+1]);
		nS=min(nS,s1+s2);
	}
	Solve();
	cout<<S-nS<<endl;
}

