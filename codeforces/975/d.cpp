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
typedef pair<double,double> pdd;
double theta;
int n,a,b;
const int maxn=200050;
int x[maxn];
pii v[maxn];
pdd vn[maxn];
double eps=1e-7;
double csi,ssi;
ll ans=0;
bool cmp(pdd a,pdd b) {
	if(fabs(a.fi-b.fi)<eps)
		return a.se<b.se;
	else 
		return a.fi<b.fi;
}

void count(int l,int r) {
	int tot=r-l+1;
	for(int i=l;i<=r;++i) {
		int rr=i;
		while(fabs(vn[rr+1].se-vn[i].se)<eps) rr++;
		int len=(rr-i+1);
		ans+=len*(tot-len);
		i=rr+1;
	}
}

int main() {
	R(n); R(a); R(b);
	theta=atan(a);
	csi=cos(theta); ssi=sin(theta);
	rep(i,1,n,1) {
		R(x[i]);
		R(v[i].fi); R(v[i].se);
		vn[i].fi=csi*v[i].fi+ssi*v[i].se;
		vn[i].se=csi*v[i].se-ssi*v[i].fi;
	}
	sort(vn+1,vn+n+1,cmp);
	for(int i=1;i<=n;++i) {
		int r=i;
		while(fabs(vn[r+1].fi-vn[i].fi)<eps)  r++;
		count(i,r);
		i=r+1;
	}
	cout<<ans<<endl;
}


