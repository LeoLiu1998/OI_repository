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
const int maxn=5000500;
ll f[maxn];
int fd[maxn];
bool p[maxn];
int t,l,r;
const int mod=(int)1e9+7;
void Init() {
	memset(f,-1,sizeof f);
	memset(p,1,sizeof p);
	for(int i=2;i<=r;++i) {
		if(!p[i]) continue;
		f[i]=(ll)i*(i-1)/2;
		f[i]%=mod;
		for(ll j=2;j*i<=r;++j) {
			if(p[j*i]) {
				p[j*i]=0;
				fd[j*i]=i;
			}
		//	fd[j*i]=i;
		}
	}
}
int Calc(int k) {
	if(f[k]!=-1) return f[k];
	else {
		ll cur=(ll)f[fd[k]]*k/fd[k]+(ll)Calc(k/fd[k]);
		cur%=mod;
		f[k]=cur;
		return f[k];
	}
}
ll ans=0;
int main() {
	R(t); R(l); R(r);
	Init();
#ifdef YGHDEBUG
	for(int i=l;i<=r;++i) {
		Pn(Calc(i));
	}
#endif
	for(int i=r;i>=l;--i) {
		ans=ans*t;
		ans%=mod;
		ans+=Calc(i);
		ans%=mod;
	}
	cout<<ans%mod<<endl;
}

