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
int n;
int a[1005];
int main() {
	R(n); rep(i,1,n,1) {
		char ch =0 ;
		while(!isdigit(ch)) ch=getchar();
		a[i]=ch-'0';
	}
	for(int i=2;i<=n;++i) {
		if(a[i]&&a[i-1])  {
			puts("No");
			return  0;
		}
	}
	for(int i=2;i<=n+1;++i) {
		if((!a[i-2])&&(!a[i-1])&&(!a[i])) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}


