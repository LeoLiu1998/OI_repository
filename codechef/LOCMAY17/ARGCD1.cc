//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#include <unordered_map>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%lld\n",x)
#define Ps(x) printf("%lld ",x)
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
map<ll,ll> m;
map<ll,ll> lg[2];
ll a[20050];
ll gcd(ll a,ll b) {
	return b==0? a: gcd(b,a%b);
}
pll cnt[200500];
ll pre[200500];
int n,T;
void Solve(ll k) {
	/*int l=0,r=cnt[0].fi;
	if(k>pre[cnt[0].fi-1]) {
		Pn(cnt[cnt[0].fi].fi);
		return ;
	}
	while(r-l>1) {
		int mid=(l+r)>>1;
		if((pre[mid-1]<k)&&(pre[mid]>=k)) {
			Pn(cnt[mid].fi);
			return ;
		}
		if(pre[mid]<k) l=mid;
		else r=mid;
	}
	Pn(cnt[r].fi);*/
	int pos=lower_bound(pre+1,pre+cnt[0].fi+1,k)-pre;
	Pn(cnt[pos].fi);
}
int main() {
	R(n); R(T);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	m[a[1]]++;
	lg[1&1][a[1]]++;
	for(int i=2;i<=n;++i) {
		lg[i&1].clear();
		for(auto x:lg[(i-1)&1]) {
			ll g=gcd(x.fi,a[i]);
			m[g]+=x.se;
			lg[i&1][g]+=x.se;
		}
		m[a[i]]++;
		lg[i&1][a[i]]++;
	}
	for(auto x:m) {
		cnt[++cnt[0].fi]=x;
	}
	sort(cnt+1,cnt+cnt[0].fi+1);
	for(int i=0;i<=cnt[0].fi;++i) {
		pre[i]=pre[i-1]+cnt[i].se;
	}
	for(int i=1;i<=T;++i) {
		ll k; scanf("%lld",&k);
		Solve(k);
	}
}

