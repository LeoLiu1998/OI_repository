//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
//#include<unordered_map>
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
const int maxn=200500;
typedef pair<pii,int> P3;
typedef pair<pii,pii> P4;
P3 a[maxn];
int cnt,n,x;
int ans=INT_MAX;
map<int,int> um;
vector<P4> pl[maxn];
vector<P4> pr[maxn];
bool cmpl(P3 p, P3 q) {
	return p.fi.fi<q.fi.fi;
}
bool cmpr(P3 p, P3 q) {
	return p.fi.se<q.fi.se;
}
bool cmpla(int p,int q) {
	return cmpl(a[p],a[q]);
}
bool cmpra(int p,int q) {
	return cmpr(a[p],a[q]);
}
void Deal(int l,int r,int co) {
	int rem=x-(r-l+1);
	if(!um.count(rem)) {
		return ;
	}
	int po=um[rem];
	int cura=INT_MAX;
	auto p1=lower_bound(pl[po].begin(),pl[po].end(),mp(mp(r+1,0),mp(0,0)));
	if(p1!=pl[po].end()) {
		cura=min(cura,p1->se.se);
	}
	auto p2=upper_bound(pr[po].begin(),pr[po].end(),mp(mp(l-1,INT_MAX),mp(0,0)));
	if(p2!=pr[po].begin()) {
		p2--;
		cura=min(cura,p2->se.se);
	}
	if(cura==INT_MAX) return ;
	else ans=min(ans,co+cura);
}
int main() {
	R(n); R(x);
	for(int i=1;i<=n;++i) {
		R(a[i].fi.fi); R(a[i].fi.se);
		R(a[i].se);
		int qwq=1+a[i].fi.se-a[i].fi.fi;
		if(!um.count(qwq)) {
			um[qwq]=++cnt;
		}
	}
	sort(a+1,a+n+1,cmpl);
	for(int i=1;i<=n;++i) {
		int qwq=1+a[i].fi.se-a[i].fi.fi;
		int po=um[qwq];
		pii cp=mp(a[i].fi.fi,a[i].se);
		pl[po].pb(mp(cp,cp));
	}
	for(int i=1;i<=n;++i) {
		if(pl[i].size()<1) continue;
		for(int j=pl[i].size()-2;j>=0;--j) {
			if(pl[i][j].fi.se<=pl[i][j+1].se.se) continue;
			else {
				pl[i][j].se=pl[i][j+1].se;
			}
		}
	}
	sort(a+1,a+n+1,cmpr);
	for(int i=1;i<=n;++i) {
		int qwq=1+a[i].fi.se-a[i].fi.fi;
		int po=um[qwq];
		pii cp=mp(a[i].fi.se,a[i].se);
		if(!pr[po].size()) {
			pr[po].pb(mp(cp,cp));
		} else {
			P4 lp=pr[po][pr[po].size()-1];
			if(lp.se.se>=cp.se) {
				pr[po].pb(mp(cp,cp));
			} else {
				pr[po].pb(mp(cp,lp.se));
			}
		}
	}
	for(int i=1;i<=n;++i) {
		Deal(a[i].fi.fi,a[i].fi.se,a[i].se);
	}
	Pn((ans==INT_MAX)?-1:ans);
}

