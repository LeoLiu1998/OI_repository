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
typedef long double ld;
int l,r,n;
ll ans=0;
int gcd(int a, int b) {
	return b ? gcd(b,a%b) : a;
}
ll qpow(ll base, int k) {
	ll ret=1;
	while(k) {
		if(k&1) {
			ret*=base;
		}
		k>>=1;
		base*=base;
	}
	return ret;
}
void Check(int p, int q) {
	ll a1=qpow(q,n-1);
	ll an=qpow(p,n-1);
	ll s=(l%a1) ? (l/a1)+1 : l/a1; while(s*a1 < l) s++;
	ll e=r/an; while(e*an > r) e--;
	ans+= max((ll)0,e-s+1);
/*	if(e-s+1 > 0) {
		for(int i=e;i<=s;++i) {
			int b1=a1*i;
			int b2= b1/q*p;
			int b3= b2/q*p;
			if(1.0*b2/b1 - 1.0*b3/b2 > 1e6) {
				cout<<"!"<<endl;
			}
		}
	}*/
}
int main() {
	R(n); R(l); R(r);
	if(n==1) {
		cout<<r+1-l<<endl;
		return 0;
	} else if(n==2) {
		int k=r-l+1;
		cout<<(ll)k*(k-1)<<endl;
		return 0;
	}
	ld bound=pow(r,1.0/(n-1))+0.5;
	for(int i=1;i<=bound;++i) {
		for(int j=i+1;j<=bound;++j) {
			if(gcd(i,j)==1) {
				Check(j,i);
			}
		}
	}
	cout<<ans*2<<endl;
}

