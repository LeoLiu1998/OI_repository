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
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m,k;
ll mod=1000000007;
ll qpow(ll base, ll k) {
	ll ret=1;
	while(k) {
		if(k&1)
			ret*=base;
		base*=base;
		base%=mod;
		k>>=1;
		ret%=mod;
	}
	return ret;
}
int main() {
	R(n); R(m); R(k);
	if(k==-1) {
		if((n&1)+(m&1)==1){
			puts("0");
			return 0;
		}
	}
	ll ans=qpow(2,(((n-1)%(mod-1))*((m-1)%(mod-1))%(mod-1)));
	cout<<ans<<endl;
}


