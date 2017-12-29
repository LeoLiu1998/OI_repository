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
double ans[1005];
double y[1005];
bool ball[1005];
//set<int> s;
pii cir[1005];
int n,r;
int main() {
	R(n); R(r);
	rep(i,1,n,1) {
		
		R(cir[i].fi); cir[i].se=i;
	}
	ans[1]=0;
	ball[cir[1].fi]=1;
	for(int i=2;i<=n;++i) {
		int x=cir[i].fi;
		double yy=0;
		for(int j=x-2*r;j<=x+2*r;++j) {
			if(j<0||j>1000) continue;
			if(!ball[j]) continue;
			double ny=sqrt(1.0*4*r*r-(j-x)*(j-x))+y[j];
			yy=max(yy,ny);
		}
		ans[i]=yy;
		ball[x]=1;
		y[x]=max(yy,y[x]);
	}
/*	s.insert(cir[1].fi);
	s.insert(1e8);
	s.insert(-1e8);*/
/*	for(int i=2;i<=n;++i) {
	//	auto it=s.lower_bound(cir[i].fi);
		int rp=*it;
		it--;
		int l=*it;
		double ly=l<0 ? 0: y[l];
		double ry=rp>1e3 ? 0: y[rp];
		int x=cir[i].fi;
		double rny=sqrt(4*r*r-(rp-x)*(rp-x))+ry;
		double lny=sqrt(4*r*r-(l-x)*(l-x))+ly;
		if(rp-x>2*r) {
			rny=0;
		}
		if(x-l>2*r) {
			lny=0;
		}
		ans[i]=max(lny,rny);
		y[x]=max(y[x],ans[i]);
		s.insert(x);
	}*/
	for(int i=1;i<=n;++i) {
		printf("%.10f ",ans[i]+r);
	}
	puts("");
}


