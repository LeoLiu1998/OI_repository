//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define pow pox
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
ll quick_inverse(ll n, ll p) {
	ll ret = 1;
	ll exponent = p - 2;
	for (int i = exponent; i; i >>= 1, n = n * n % p) {
		if (i & 1) {
			ret = ret * n % p;
		}
	} 
	return ret;
}
const int maxn=1000500;
ll pow[maxn];
const ll mod=1e9+7;
ll a[maxn];
int n;
int main() {
	pow[0]=1;
	for(int i=1;i<=1000000;++i) {
		pow[i]=pow[i-1]<<1;
		pow[i]%=mod;
	}
	int T; R(T);
	while(T--) {
		ll ans=0;
		ll ansl=0;
		ll tmp=1;
		R(n);
		rep(i,1,n,1) {
			scanf("%lld",&a[i]);
		}
		for(int i=n;i;--i) {
			tmp=(tmp)*a[i]%mod;
			if(i<2) {
				ansl+=tmp;
			} else {
				ansl+=tmp*pow[i-2];
			}
			ansl%=mod;
		}
		ans+=ansl;
		for(int i=n-1;i;--i) {
			ansl=((ansl-a[i+1]*pow[i-1])+mod*mod)%mod;
			ansl=ansl*quick_inverse(a[i+1],mod)%mod;
			ans+=ansl*pow[n-i-1];
			ans%=mod;
		}
		cout<<ans<<endl;	
	}
}

