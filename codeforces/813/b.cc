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
ll a[70];
ll b[70];
ll sum[10005];
ll x,y,l,r;
int main() {
	R(x); R(y); R(l); R(r);
	memset(a,-1,sizeof a);
	memset(b,-1,sizeof b);
	a[0]=1; b[0]=1;
	for(int i=1;i<=64;++i) {
		if(1e18/x<a[i-1]) break;
		a[i]=a[i-1]*x;
	}
	for(int i=1;i<=64;++i) {
		if(1e18/y<b[i-1]) break;
		b[i]=b[i-1]*y;
	}
	sum[++sum[0]]=l-1;
	sum[++sum[0]]=r+1;
	for(int i=0;a[i]!=-1;++i) {
		for(int j=0;b[j]!=-1;++j) {
			if((a[i]+b[j]>=l)&&(a[i]+b[j]<=r))
			sum[++sum[0]]=a[i]+b[j];
		}
	}
	ll ans=0;
	sort(sum+1,sum+sum[0]+1);
	for(int i=2;i<=sum[0];++i) {
		ans=max(ans,sum[i]-sum[i-1]-1);
	}
	cout<<ans<<endl;
}

