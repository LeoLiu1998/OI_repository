//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
struct Point {
	int x,y;
	Point(ll _x=0, ll _y=0):x(_x),y(_y) {};
	Point operator - (const Point &a) const {
		Point ret=Point(x-a.x,y-a.y);
		return ret;
	}
	Point operator + (const Point &a) const  {
		Point ret= Point(x+a.x,y+a.y);
		return ret;
	}
	ll operator * (const Point &a) const  {
		ll ret= x*a.x+y*a.y;
		return ret;
	}
	ll operator ^ (const Point &a) const  {
		ll ret= x*a.y- y*a.x;
		return ret;
	}
	bool isLeft(const Point &a) const  {
		return (((*this) ^ a ) > 0);
	}
	void Read() {
		R(x); R(y);
	}
};
const int maxn=500050;
int f[maxn],m[maxn];
int rev[maxn];
int revf[maxn];
int n;
int ans[maxn];
int cnt=0;
void Solve(Point pf,Point pm) {
	if(pm.y<pm.x) return ;
	if((pf.y-pf.x)!=(pm.y-pm.x)) {
		Pn(-1);
		exit(0);
	}
	if((pm.y-pm.x==0)) {
		ans[++cnt]=f[pf.x];
		return ;
	}
	int rv=f[pf.x];
	int rp=rev[rv];
	Point ml(pm.x,rp-1),mr(rp+1,pm.y);
	Point fl(pf.x+1,revf[m[rp-1]]),fr(revf[m[rp-1]]+1,pf.y);
	if(rp==pm.x) {
		fr.x=pf.x+1;
	}
	if(rp!=pm.x) 
		Solve(fl,ml); 
	if(rp!=pm.y) 
		Solve(fr,mr);
	ans[++cnt]=rv;
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(f[i]);
		revf[f[i]]=i;
	}
	for(int i=1;i<=n;++i) {
		R(m[i]); 
		rev[m[i]]=i;
	}
	Solve(Point(1,n),Point(1,n));
	for(int i=1;i<cnt;++i) Ps(ans[i]);
	Pn(ans[cnt]);
}

