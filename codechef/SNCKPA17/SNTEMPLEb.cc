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
const int maxn=100500;
#define CL(x) memset(x,0,sizeof(x))
int l[maxn],r[maxn],a[maxn];
int T,n;
int mv=-1;
set<int> s;
ll ans=0;
ll Calc(int x) {
	ll ret=0;
	int d=min(min(x,n-x+1),a[x]);
	for(int i=1;i<=(d-1);++i) {
		int lp=x-i,rp=x+i;
		d=min(d,min(a[lp]+i,a[rp]+i));
	}
	for(int i=1;i<=n;++i) {
		int sup=max(0,d-abs(x-i));
		ret+=(a[i]-sup);
	}
	return ret;
}
int main() {
	R(T);
	while(T--) {
		mv=-1; s.clear();
		ans=LLONG_MAX;
		CL(l); CL(r); CL(a);
		R(n); rep(i,1,n,1) R(a[i]);
		for(int i=1;i<=n;++i) {
			l[i]=min(l[i-1]+1,a[i]);
			r[n+1-i]=min(r[n-i+2]+1,a[n+1-i]);
		}
		for(int i=1;i<=n;++i) {
			ans=min(ans,Calc(i));
		}
		cout<<ans<<endl;
	}
}

