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
int m,b;
const int maxn=100500;
ll Calc(ll l,ll r) {
	return (r+l)*(r-l+1)/2;
}
ll ans=0;
int main() {
	R(m); R(b);
	// when y==i
	for(int i=0;i<=b;++i) {
		ll r=((ll)b-i)*m;
		ll cur=Calc(0,r)*(i+1);
		cur+=Calc(0,i)*(r+1);
		ans=max(ans,cur);
	}
	cout<<ans<<endl;
}

