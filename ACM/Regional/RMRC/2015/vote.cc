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
int T,n,cnt;
pii a[15];
int main() {
	R(T);
	while(T--) {
		R(n); cnt=0;
		rep(i,1,n,1) {
			R(a[i].fi);
			a[i].se=i;
			cnt+=a[i].fi;
		}
		sort(a+1,a+n+1);
		if(a[n].fi==a[n-1].fi) {
			puts("no winner");
		} else if(a[n].fi>(cnt>>1)) {
			printf("majority winner %d\n",a[n].se);
		} else {
			printf("minority winner %d\n",a[n].se);
		}
	}
}

