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
pii operator - (const pii &a, const pii &b) {
	return mp(a.fi-b.fi,a.se-b.se);
}
pii s,t;
int x,y;
int main() {
	R(s.fi); R(s.se); R(t.fi); R(t.se);
	R(x); R(y);
	pii d=t-s;
	if((d.fi%x!=0)||(d.se%y!=0)) {
		puts("NO");
		return 0;
	}
	int m=d.fi/x,n=d.se/y;
	if((m+n)%2) {
		puts("NO");
	} else {
		puts("YES");
	}
}

