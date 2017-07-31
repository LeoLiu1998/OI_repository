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
ll n,k;
int a[105];
int p[int(1e7)+10];
int cnt=0;
ll C=0;
int main() {
	R(n); R(k);
	rep(i,1,n,1) {
		R(a[i]);
		C+=a[i];
		for(int j=1;j*j<=a[i];++j) {
			p[++cnt]=j;	
			p[++cnt]=(a[i]+j-1)/j;
		}
	}
	C+=k;
	ll ans=0;
	sort(p,p+cnt+1);
	cnt=unique(p,p+cnt+1)-p-1;
	for(int i=1;i<=cnt;++i) {
		ll d=p[i];
		ll cur=0; //p days check once
		rep(j,1,n,1) {
			cur+=(a[j]+(d-1))/d;
		}
		if(cur<=(1.0*C/d)) {
			ans=max(ans,C/cur);
		}
	}
	cout<<ans<<endl;
}
