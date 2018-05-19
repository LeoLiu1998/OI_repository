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
int n,a,b;
ll ans=0;
ll tot;
pii mon[200500];

bool cmp(pii a,pii b) {
	return (a.fi-a.se)>(b.fi-b.se);
}

int swaps=0;

ll check(int k) {
	ll new_damge = (1ll<<a)*mon[k].fi;
	if(k<=swaps) {
		return tot-mon[k].fi+new_damge;
	} else if(swaps<b) {
		return tot-mon[k].se+new_damge;
	} else {
		return tot-mon[swaps].fi+mon[swaps].se-mon[k].se+new_damge;
	}
}

int main() {
	R(n); R(a); R(b);
	for(int i=1;i<=n;++i) {
		R(mon[i].fi); R(mon[i].se);
	}
	sort(mon+1,mon+n+1,cmp);
	for(int i=1;i<=n;++i) {
		if(mon[i].fi>mon[i].se&&swaps<b) {
			swaps++;
			tot+=mon[i].fi;
		} else {
			tot+=mon[i].se;
		}
	}
	if(b==0||a==0) {
		Pln(tot);
	} else {
		for(int i=1;i<=n;++i) {
			ans=max(ans,check(i));
		}
		Pln(ans);
	}
}


