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
int n,x;
int ans=1;
pii a[1005];
pair<double,int> t[1005];
double Calc(int k) {
	return 1.0*abs(a[k].fi-x)/a[k].se;
}
int main() {
	R(n); R(x);
	for(int i=1;i<=n;++i) {
		R(a[i].fi); 
	}
	rep(i,1,n,1) R(a[i].se);
	for(int i=1;i<=n;++i) {
		t[i]=mp(Calc(i),i-1);
	}
	sort(t+1,t+n+1);
	if(n==1||(fabs(t[1].fi-t[2].fi)>=1e-8))
		Pn(t[1].se);
	else {
		puts("-1");
	}
}

