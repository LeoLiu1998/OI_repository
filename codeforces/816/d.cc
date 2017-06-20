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
int n;
const int maxn=200500;
int a[2][maxn];
int cur,nex;
int sta=0;
int b[maxn];
const ll mod=int(1e9)+7;
ll fac[maxn];
ll rev[maxn];
ll cnt[maxn];
ll qpow(ll x,ll n) {
	ll ret=1;
	while(n) {
		if(n&1) {
			ret=ret*x%mod;
		}
		x*=x;
		x%=mod;
		n>>=1;
	}
	return ret;
}
int main() {
	nex=1;
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[cur][i]);
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	while(n%4!=0) {
		if(n==1) {
			cout<<a[cur][1]<<endl;
			return 0;
		}
		n--;
		for(int i=1;i<=n;++i) {
			if(sta==0) {
				a[nex][i]=a[cur][i]+a[cur][i+1];
				a[nex][i]%=mod;
			} else {
				a[nex][i]=a[cur][i]-a[cur][i+1];
				a[nex][i]=(a[nex][i]+mod)%mod;
			}
			sta^=1;
		}
		cur^=1;
		nex^=1;
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	fac[0]=1;
	int qwq=((n/4)-1)*2+1;
	for(int i=1;i<=n;++i) {
		fac[i]=(fac[i-1]*i)%mod;
	}
	for(int i=0;i<=qwq;++i) {
		rev[i]=qpow(fac[i],mod-2);
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	for(int i=1;i<=(n/2);++i) {
		if(i%2==0) {
			cnt[i]=cnt[i-1]*-1;
			if(sta) cnt[i]*=-1;
			continue;
		}
		int k=i/2;
		cnt[i]=fac[qwq]*rev[k]%mod;
		cnt[i]=cnt[i]*rev[qwq-k]%mod;
	}
	for(int i=(n/2)+1;i<=n;++i) {
		cnt[i]=abs(cnt[n+1-i]);
		if((sta==0)&&(i%2==0)) cnt[i]*=-1;
	}
	ll ans=0;
	for(int i=1;i<=n;++i) {
		ans+=((cnt[i]*a[cur][i])%mod);
		ans%=mod;
		while(ans<0) ans=(ans+mod*(ans/mod*-1+5))%mod;
	}
	cout<<ans<<endl;

}

