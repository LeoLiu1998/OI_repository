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
int n,r,w,h;
pll a[100050];
ll d[100050];
int main() {
	R(n); R(r); R(w); R(h);
	rep(i,1,n,1) {
		ll x; ll y;
		R(x); R(y);
		a[i].fi=r*x+y;
		a[i].se=y-r*x;
	}
	sort(a+1,a+n+1);
	int ans=0;
	d[0]=INT_MIN;
	for(int i=1;i<=n;++i) {
		if(a[i].se>=d[ans]) d[++ans]=a[i].se;
		else d[lower_bound(d+1,d+ans+1,a[i].se)-d]=a[i].se;
	}
	Pn(ans);
}


