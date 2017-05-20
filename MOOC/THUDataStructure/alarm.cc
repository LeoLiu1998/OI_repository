//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
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

struct Point {
	ll x,y;
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
typedef Point Line;
Line l[200050];
Point p[1000050];
ll n,m;
bool PLL(Line L, Point P) { // point left to line
	Point q=Point(L.x,0),p=Point(0,L.y);
	P=P-q; p=p-q;
	return p.isLeft(P);
}
int Solve(const Point & cur) {
	if(PLL(l[1],cur)) {
		return 0;		
	} else if(!PLL(l[n],cur)) {
		return n;
	}
	int lo=1,r=n;
	while(r-lo!=1) {
		int mid=(lo+r)>>1;
		if(PLL(l[mid],cur)) {
			r=mid;
		} else {
			lo=mid;
		}
	}
	return lo;
}

int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		l[i].Read();
	}
	for(int i=1;i<=m;++i) {
		p[i].Read();
		Pn(Solve(p[i]));
	}
}

