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
const double eps=1e-8;
struct Edge {
	double k,b;
};
const double PI = 3.141592653589793; 
typedef pair<double,double> Point;
Point p[10][10];
Point vec[10][10];
int main() {
	for(int i=3;i<=8;++i) {
		for(int j=0;j<i;++j) {
			double rad = 1.0* j /i *2*PI;
			Point cur = make_pair(cos(rad),sin(rad));
			p[i][j]=cur;
		}
		for(int j=0;j<i;++j) {
			Point l = p[i][j];
			Point r = p[i][(j+1)%i];
			vec[i][j] = mp(r.fi-l.fi,r.se-l.se);
		}
	}
}


