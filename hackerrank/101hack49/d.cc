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
const int maxn=100050;
int a[maxn];
int l,r;
int n,m;
const int mod=int(1e9+7);
ll qpow(ll b,ll x) {
	ll ret=1;
	while(x) {
		if(x&1) {
			ret*=b;
			ret%=mod;
		}
		b*=b;
		b%=mod;
		x>>=1;
	}
	return ret%mod;
}
struct Seg{
	ll s,t,lv,l,r;
	bool lazy;
	Seg() {
		s=t=lv=lazy=0;
	}
	Seg operator + (const Seg &b) const  {
		Seg ret;
		ret.s=(s*b.s)%mod;
		ret.t=(t*b.t)%mod;
		ret.lazy=0;
		ret.l=l;
		ret.r=b.r;
		return ret;
	};
}seg[maxn*5];
void DL(int p) {
	if(seg[p].lazy) {
		seg[p].lazy=0;
		seg[p].s=qpow(seg[p].lv,seg[p].r-seg[p].l+1);
		seg[p].t=qpow(seg[p].lv-1,seg[p].r-seg[p].l+1);
		if(seg[p].l!=seg[p].r) {
			seg[p<<1].lazy=seg[p<<1|1].lazy=1;
			seg[p<<1].lv=seg[p<<1|1].lv=seg[p].lv;
		}
	}
}
void Build(int p, int l, int r) {
	if(l==r) {
		seg[p].l=seg[p].r=l;
		seg[p].s=a[l];
		seg[p].t=a[l]-1;
		return ;
	}
	Build(p<<1,l,(l+r)>>1);
	Build(p<<1|1,((l+r)>>1)+1,r);
	seg[p]=seg[p<<1]+seg[p<<1|1];
}

void Update(int p, int l, int r,int k) {
	if(seg[p].l==l&&seg[p].r==r) {
		seg[p].s=qpow(k,r-l+1);
		seg[p].t=qpow(k-1,r-l+1);
		seg[p].lazy=0;
		if(seg[p].l!=seg[p].r) {
			seg[p<<1].lazy=seg[p<<1|1].lazy=1;
			seg[p<<1].lv=seg[p<<1|1].lv=k;
		}
		return ;
	}
	ll mid=(seg[p].l+seg[p].r)>>1;
	DL(p<<1); DL(p<<1|1);
	if(r<=mid) {
		Update(p<<1,l,r,k);
	} else if(l>mid) {
		Update(p<<1|1,l,r,k);
	} else {
		Update(p<<1,l,mid,k);
		Update(p<<1|1,mid+1,r,k);
	}
	seg[p]=seg[p<<1]+seg[p<<1|1];
}

Seg Query(int p,int l, int r) {
	DL(p);
	if(seg[p].l==l&&seg[p].r==r) {
		return seg[p];
	} else {
		ll mid=(seg[p].l+seg[p].r)>>1;
		if(r<=mid) {
			return Query(p<<1,l,r);
		} else if(l>mid) {
			return Query(p<<1|1,l,r);
		} else {
			return Query(p<<1,l,mid)+Query(p<<1|1,mid+1,r);
		}
	}
}

int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	Build(1,1,n);
	while(m--) {
		int cmd; R(cmd);
		if(cmd==1) {
			R(l); R(r); int k; R(k);
			Update(1,l,r,k);
		} else  {
			R(l); R(r);
			Seg ans=Query(1,l,r);
			cout<<(ans.s-ans.t+2*mod)%mod<<endl;
		}
	}
}

