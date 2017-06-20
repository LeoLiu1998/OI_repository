//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%I64d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(long long &x) {
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
ll n,k;
map<pll,ll>mem;
ll check(ll s,ll m) {
	if(!s) return 0;
	if(mem.count(mp(s,m))) return mem[mp(s,m)];
	ll ret=0;
	ll l=(s-1)>>1;
	ll r=s-1-l;
	if(l<m) return 0;
	return mem[mp(s,m)]=1+check(l,m)+check(r,m);
}
ll put(ll l, ll r,ll low,ll k) {
	ll mid=(l+r)>>1;
	if(k==1) return mid;
	k--;
	ll ls=check(mid-l,low);
	ll rs=check(r-mid,low+1);
	if(ls+rs>=k) {
		return put(l,mid-1,low,k-rs);
	} else {
		return put(mid+1,r,low,k-ls);
	}
}
int main() {
	R(n); R(k);
	if(k==1) {
		Pn(1l);
		return 0;
	} else if(n==2||k==2) {
		Pn(n);
		return 0;
	} 
	k-=2; 
	ll l=0,r=n+1;
	while(r-l>1) {
		register ll mid=(l+r)>>1; 
		if(check(n-2,mid)>=k) l=mid;
		else r=mid;
#ifdef YGHDEBUG
		cerr<<l<<" "<<r<<endl;
#endif
	}
	Pn(k=put(2,n-1,l,k));
#ifdef YGHDEBUG
	cerr<<k<<endl;
#endif
}

