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
inline void R(int &x) {
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
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n;
int num[75];
int cnt[76][19];
const int mod=1e9+7;
ll dp[2][1<<20];
ll qpow(ll b,ll k) {
	ll ret=1;
	while(k) {
		if(k&1) {
			ret*=b;
			ret%=mod;
		}
		k>>=1;
		b*=b;
		b%=mod;
	}
	return ret;
}
int main() {
	R(n);
	rep(i,1,n,1) {
		int t;
		R(t);
		num[t]++;
	}
	rep(i,2,70,1) {
		int k=i;
		rep(j,0,18,1) {
			while(k&&(k%primes[j]==0)) {
				k/=primes[j];
				cnt[i][j]++;
			}
		}
	}
	int cur=0;
	ll ans=0;
	dp[cur][0]=(qpow(2,num[1])+mod)%mod;
	rep(i,2,70,1) {
		if(!num[i]) continue;
		cur^=1;
		ll odd=qpow(2,num[i]-1);
		ll even=(odd+mod)%mod;
		int sta=0;
		rep(j,0,18,1) {
			if(cnt[i][j]&1) sta|=1;
			sta<<=1;
		}
		sta>>=1;
		memset(dp[cur],0,sizeof dp[cur]);
		for(int j=0;j<(1<<19);++j) {
			dp[cur][j^sta]+=dp[cur^1][j]*odd%mod;
			dp[cur][j]+=dp[cur^1][j]*even%mod;
			dp[cur][j]%=mod;
			dp[cur][j^sta]%=mod;
		}
		cerr<<dp[cur][0]<<endl;
	}
	Pln((dp[cur][0]-1+mod)%mod);
}


