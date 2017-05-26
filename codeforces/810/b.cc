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
int n,f;
pii a[100500];
inline int Calc(pii x) {
	return min(x.fi*2,x.se)-min(x.fi,x.se);
}
bool cmp(pii a, pii b) {
	return Calc(a)>Calc(b);	
}
int main() {
	R(n); R(f);
	for(int i=1;i<=n;++i) {
		R(a[i].fi); R(a[i].se);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=f;++i) {
		a[i].fi*=2;
	}
	ll ans=0;
	for(int i=1;i<=n;++i) {
		ans+=min(a[i].fi,a[i].se);
	}
	cout<<ans<<endl;
}

