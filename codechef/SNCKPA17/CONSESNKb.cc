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
int T;
int n,l,a,b;
const int maxn=100050;
int p[maxn];
int del[maxn];
ll ans=0;
ll tl=0;
int cnt[3];
ll mv,tot;
ll Calc(ll x) {
	ll ret=0;
	for(int i=1;i<=n;++i) {
		ret+=abs(x+(i-1)*l-p[i]);
	}
	return ret;
}
int main() {
	R(T);
	while(T--) {
		ans=LLONG_MAX; tot=0;
		R(n); R(l); R(a); R(b);	
		tl=(ll)l*(n);
		ll rr=b-tl;
		for(int i=1;i<=n;++i) {
			R(p[i]);
		}
		sort(p+1,p+n+1);
		ll l=a,r=rr,m,mm;
		for(int i=a;i<=rr;++i) {
			ans=min(ans,Calc(i));
		}
		cout<<ans<<endl;
	}
}

