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
int gcd(int a,int b) {
	if(!b) 
		return a;
	else
		return gcd(b,a%b);
}
int a[2005];
int n;
int g;
pii s;
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
	}
	g=a[1];
	rep(i,2,n,1)
		g=gcd(g,a[i]);
	if(g!=1) {
		puts("-1");
		return 0;
	}
	rep(i,1,n,1) {
		rep(j,i,n,1) {
			if(gcd(a[i],a[j])==1) {
				if(!s.fi) 
					s=mp(i,j);
				else {
					if(j-i<s.se-s.fi) 
						s=mp(i,j);
				}
			}
		}
	}
	if(!s.fi) {
		s=mp(1,n);
	}
	int ans=0;
	for(int i=s.fi+1;i<=s.se;i++) {
		if(a[i]!=1) {
			a[i]=gcd(a[i-1],a[i]);
			ans++;
		}
	}
	for(int i=s.se-1;i>0;--i) {
		if(a[i]!=1)
			ans++;
		a[i]=1;
	}
	for(int i=s.se+1;i<=n;++i) {
		if(a[i]!=1)
			ans++;
		a[i]=1;
	}
	Pn(ans);
}


