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
vector<pair<pll,ll> > plog;
int bin[4][100];
int Binary(int pos,ll v) {
	int len=0;
	while(v) {
		bin[pos][++len]=v&1;
		v>>=1;
	}
	for(int i=len,j=1;i>=1;--i,++j) {
		bin[pos+1][j]=bin[pos][i];
	}
	return len;
}
ll LCA(ll a,ll b) {
	memset(bin,0,sizeof bin);
	int len1=Binary(0,a);
	int len2=Binary(2,b);
	ll ret=0;
	int l=min(len1,len2);
	for(int i=1;i<=l&&bin[1][i]==bin[3][i];++i) {
		ret<<=1;
		ret+=bin[1][i];
	}
	return ret;
}
void Modify() {
	ll l,r,v;
	cin>>l>>r>>v;
	ll lca=LCA(l,r);
	plog.pb(mp(mp(lca,l),v));
	plog.pb(mp(mp(lca,r),v));
}
ll interLen(pll l,pll r) {
	ll lca=LCA(l.se,r.se);
	if(lca<l.fi||lca<r.fi) return 0;
	ll s=max(l.fi,r.fi);
	ll ret=0;
	while(s<lca) {
		ret++;
		lca>>=1;
	}
	return ret;
}
void Query() {
	ll l,r;
	cin>>l>>r;
	ll lca=LCA(l,r);
	ll ans=0;
	for(int i=0;i<plog.size();++i) {
		ans+=(interLen(mp(lca,l),plog[i].fi)+interLen(mp(lca,r),plog[i].fi))*plog[i].se;
	}
	cout<<ans<<endl;
}

int main() {
	int M; R(M);
	while(M--) {
		int cmd; R(cmd);
		if(cmd==1) {
			Modify();
		} else {
			Query();
		}
	}
}

