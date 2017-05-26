#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)	for(ll i=j;i<=n;i++)
#define down(i,j,n)	for(ll i=j;i>=n;i--)
#define cmax(a,b)	a=max(a,b)
#define cmin(a,b)	a=min(a,b)
#define fi		first
#define se		second
#define pii		pair<ll,ll>

const ll mod=1e9+7;
const ll MAXN=1e5+5;

ll N,Q,a[MAXN];

ll qpow(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)(c*=a)%=mod;
		b>>=1;(a*=a)%=mod;
	}
	return c;
}

namespace SegTree{
	struct tree{
		ll s1,s2,mk;
	}t[MAXN<<2];
	void rel(int k){
		t[k].s1=t[k<<1].s1*t[k<<1|1].s1%mod;
		t[k].s2=t[k<<1].s2*t[k<<1|1].s2%mod;
	}
	void mark(int le,int ri,int k,int p){
		t[k].s1=qpow(p,ri-le+1);
		t[k].s2=qpow(p-1,ri-le+1);
		t[k].mk=p;
	}
	void Pushdown(int le,int ri,int k){
		int mi=(le+ri)>>1;
		if(t[k].mk==-1||le==ri)return;
		mark(le,mi,k<<1,t[k].mk);
		mark(mi+1,ri,k<<1|1,t[k].mk);
		t[k].mk=-1;
	}
	void Build(int le,int ri,int k){
		t[k].mk=-1;
		if(le==ri){
			t[k].s1=a[le];
			t[k].s2=a[le]-1;
			return;
		}
		int mi=(le+ri)>>1;
		Build(le,mi,k<<1);
		Build(mi+1,ri,k<<1|1);
		rel(k);
	}
	void Modify(int le,int ri,int k,int l,int r,int p){
		Pushdown(le,ri,k);
		if(l<=le&&ri<=r){
			mark(le,ri,k,p);
			return;
		}
		int mi=(le+ri)>>1;
		if(l<=mi)Modify(le,mi,k<<1,l,r,p);
		if(r>=mi+1)Modify(mi+1,ri,k<<1|1,l,r,p);
		rel(k);
	}
	pii Query(int le,int ri,int k,int l,int r){
		Pushdown(le,ri,k);
		if(le>=l&&ri<=r)return make_pair(t[k].s1,t[k].s2);
		int mi=(le+ri)>>1;
		ll sumx=1,sumy=1;
		if(l<=mi){
			pii tmp=Query(le,mi,k<<1,l,r);
			(sumx*=tmp.fi)%=mod;
			(sumy*=tmp.se)%=mod;
		}
		if(r>=mi+1){
			pii tmp=Query(mi+1,ri,k<<1|1,l,r);
			(sumx*=tmp.fi)%=mod;
			(sumy*=tmp.se)%=mod;
		}
		return make_pair(sumx,sumy);
	}
}using namespace SegTree;

namespace solution{
	void Prepare(){
		scanf("%lld%lld",&N,&Q);
		up(i,1,N)scanf("%lld",&a[i]);
		Build(1,N,1);
	}
	void Solve(){
		while(Q--){
			ll op=1;
			scanf("%lld",&op);
			if(op==1){
				ll l,r,p;
				scanf("%lld%lld%lld",&l,&r,&p);
				Modify(1,N,1,l,r,p);
			}else{
				ll l,r;
				scanf("%lld%lld",&l,&r);
				pii tmp=Query(1,N,1,l,r);
				printf("%lld\n",(tmp.fi+mod-tmp.se)%mod);
			}
		}
	}
}

int main(){
	//freopen("input.in","r",stdin);
	using namespace solution;
	Prepare();
	Solve();
	return 0;
}