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
ll cur[500];
ll s,m,d;
ll ans=0;
void Print(int x) {
#ifdef YGHDEBUG
	for(int i=1;i<=x;++i) {
		printf("%lld ",cur[i]);
	}
	puts("");
#endif
}
void dfs(ll pos, ll rem) {
	if(rem==0) {
		ans++;
		Print(pos);
		return ;
	}
	ll l=max((ll)1,cur[pos]-d),r=min(m,min(rem,cur[pos]+d));
	for(int i=l;i<=r;++i) {
		cur[pos+1]=i;
		dfs(pos+1,rem-i);
	}
}
int main() {
	R(s); R(m); R(d);
	for(int i=1;i<=m;++i) {
		cur[1]=i;
		dfs(1,s-i);
	}
	cout<<ans<<endl;
}

