//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%lld\n",x)
#define Ps(x) printf("%lld ",x)
#define NEX(x) x[++x[0].fi]
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
pll m[100050];
pll lg[2][100050];
ll a[20050];
ll gcd(ll a,ll b) {
	return (b==0)? a:gcd(b,a%b);
}
ll pre[200500];
int n,T;

void Solve(int k) {
	int l=0,r=m[0].fi;
	if(k>pre[m[0].fi-1]) {
		Pn(m[m[0].fi].fi);
		return ;
	}
	while(r-l>1) {
		int mid=(l+r)>>1;
		if((pre[mid-1]<k)&&(pre[mid]>=k)) {
			Pn(m[mid].fi);
			return ;
		}
		if(pre[mid]<k) l=mid;
		else r=mid;
	}
	Pn(m[r].fi);
}
void Add(pll arr[],ll v,ll num) {
	for(int i=1;i<=arr[0].fi;++i) {
		if(arr[i].fi==v) {
			arr[i].se+=num;
			return ;
		}
	}
	NEX(arr)=mp(v,num);
}
int main() {
	R(n); R(T);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
//	sort(a+1,a+n+1);
	NEX(m)=mp(a[1],1);
	NEX(lg[1&1])=mp(a[1],1);
	for(int i=2;i<=n;++i) {
		memset(lg[i&1],0,sizeof(lg[i&1]));
		for(int j=1;j<=lg[(i-1)&1][0].fi;++j) {
			ll g=gcd(lg[(i-1)&1][j].fi,a[i]);
			Add(lg[i&1],g,lg[(i-1)&1][j].se);
			Add(m,g,lg[(i-1)&1][j].se);
		}
		Add(lg[i&1],a[i],1);
		Add(m,a[i],1);
	}
	sort(m+1,m+m[0].fi+1);
	for(int i=0;i<=m[0].fi;++i) {
		pre[i]=pre[i-1]+m[i].se;
	}
	while(T--) {
		int k; R(k);
		Solve(k);
	}
}

