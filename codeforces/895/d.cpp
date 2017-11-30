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
const int mod=1e9+7;
char a[1000500],b[1004000];
int frac[1000500];
int inv[1000500];
int cnt[26];
int n;
int l=1;

ll qpow(ll b,ll k) {
	ll ret=1;
	while(k) {
		if(k&1)
			ret=ret*b%mod;
		b=b*b%mod;
		k>>=1;
	}
	return ret;
}

ll Calc(char s[]) {
	memset(cnt,0,sizeof cnt);
	rep(i,1,n,1)
		cnt[a[i]-'a']++;
	ll comb=frac[n];
	rep(i,0,25,1)
		comb=comb*inv[cnt[i]]%mod;
	ll ret=0;
	for(int i=1;i<=n;++i) {
		comb=comb*qpow(n+1-i,mod-2)%mod;
		for(int j=0;j<(s[i]-'a');++j) {
			if(cnt[j])
				ret=(ret+comb*cnt[j]%mod)%mod;
		}
		comb=comb*cnt[s[i]-'a']%mod;
		cnt[s[i]-'a']--;
		if(cnt[s[i]-'a']<0) return ret;
	}
	cerr<<ret<<endl;
	return ret;
}

int main() {
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	frac[0]=1;
	for(int i=1;i<=n;++i) {
		frac[i]=(ll)frac[i-1]*i%mod;
	}
	inv[n]=qpow(frac[n],mod-2);
	for(int i=n;i;--i) {
		inv[i-1]=(ll)inv[i]*i%mod;
	}
	ll ans=Calc(b)-Calc(a);
	ans=(ans-1+mod)%mod;
	Pn(ans);
}


