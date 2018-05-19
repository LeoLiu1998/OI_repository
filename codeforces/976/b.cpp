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
ll n,m,k;
int main() {
	cin>>n>>m>>k;
	pii pos=mp(1l,1l);
	if(k<=n-1) {
		pos.fi+=k;
	} else {
		m--;
		pos.fi+=n-1;
		k-=n-1;
		ll level=(k+m-1)/m;
		level--;
		pos.fi-=level;
		ll rk=k%m;
		if(level%2==0) {
			pos.se+=(rk==0?m:rk);
		} else {
			pos.se+= m;
			pos.se-= (rk-1+m)%m;
		}
	}
	cout<<pos.fi<<" "<<pos.se<<endl;
}


