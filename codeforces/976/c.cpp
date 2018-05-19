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
pair<pii,int> a[300050];
pair<pii,int> max_left;
int pos;
bool cmp(pair<pii,int> a,pair<pii,int> b) {
	if(a.fi.se!=b.fi.se)
		return a.fi.se < b.fi.se;
	else
		return a.fi.fi > b.fi.fi;
}
int n;

int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i].fi.fi); R(a[i].fi.se);
		a[i].se=i;
	}
	sort(a+1,a+n+1,cmp);
	max_left=a[1];
	pos=1;
	for(int i=2;i<=n;++i) {
		if(a[i].fi.fi<=max_left.fi.fi) {
			Ps(a[pos].se); Pn(a[i].se);
			return 0;
		}
		if(a[i].fi.fi>max_left.fi.fi) {
			max_left=a[i];
			pos=i;
		}
	}
	Ps(-1); Pn(-1);
}


