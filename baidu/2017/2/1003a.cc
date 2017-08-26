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

const ll mod=1000000007;

ll qpow(ll a,ll k) {
	ll b=a;
	ll ret=1;
	while(k) {
		if(k&1) {
			ret*=b;
			ret%=mod;
		}
		k>>=1;
		b= b*b%mod;
	}
	return ret;
}

ll ans[100055];

int T;
int x,y;
ll rev=qpow(2,mod-2);
int main() {
	R(T);
	ans[0]=1;
	for(int i=1;i<=10050;++i) {
		if(i&1) {
			ans[i]=ans[i-1];
		} else {
			ans[i]=ans[i-1]*(i-1)%mod;
			ans[i]=ans[i]*i%mod;
		}
	}
	rep(i,1,10050,1) {
		if(i&1) {
			ans[i]=ans[i]*(i>>1)%mod;
			ans[i]=ans[i]*(i>>1)%mod;
		} else {
			ans[i]=ans[i]*(i>>1)%mod;
			ans[i]=ans[i]*rev%mod;
		}
	}
	while(T--) {
		int n; R(n);
		cout<<ans[n+2]<<endl;
	}
}

