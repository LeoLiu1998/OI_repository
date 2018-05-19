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
ll rob,B,C;
struct Cashier {
	ll m,s,p;
};
Cashier cas[1005];
ll cap[1005];
bool check(ll t) {
	memset(cap,0,sizeof cap);
	for(int i=1;i<=C;++i) {
		cap[i] = min(cas[i].m,(t-cas[i].p)/cas[i].s);
		cap[i] = max(0ll,cap[i]);
	}
	sort(cap+1,cap+C+1,greater<long long>());
	ll tot_cap = 0;
	for(int i=1;i<=rob;++i) {
		tot_cap += cap[i];
	}
	return tot_cap >= B;
}

int main() {
	int T; R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		R(rob); R(B); R(C);
		for(int i=1;i<=C;++i) {
			R(cas[i].m); R(cas[i].s); R(cas[i].p);
		}
		ll l=0,r=(ll)INT_MAX*INT_MAX;
		while(r-l > 1) {
			ll mid = (l+r)>>1;
			if(check(mid)) {
				r = mid; 
			} else {
				l = mid;
			}
		}
		printf("Case #%d: %lld\n",qwq,r);
	}
}


