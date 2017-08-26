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
int n;
pii a[205500];
pii b[205500];

int ans[205500];

bool cmp(pii a,pii b) {
	return b<a;
}

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i].fi); a[i].se=i;
	}
	for(int i=1;i<=n;++i) {
		R(b[i].fi); b[i].se=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;++i) {
		ans[b[i].se]=a[i].fi;
	}
	for(int i=1;i<=n;++i) {
		Ps(ans[i]);
	}
	puts("");
}

