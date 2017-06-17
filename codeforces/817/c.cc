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
ll n,s;
bool check(ll x) {
	ll ori=x;
	ll cnt=0;
	while(x) {
		cnt+=(x%10);
		x/=10;
	}
	return (ori-cnt)>=s;
}
int main() {
	R(n); R(s);
	if(!check(n)) {
		puts("0");
		return 0;
	}
	ll l=0,r=n;
	while(r-l>1) {
		ll mid=(l+r)>>1;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid;
		}
	}
	cout<<n-l<<endl;
}

