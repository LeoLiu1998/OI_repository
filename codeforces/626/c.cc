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
int a,b;
int l=0,r=10000000;
bool check(int v) {
	int c2=v/2,c3=v/3,c6=v/6;
	c2-=c6; c3-=c6;
	int ta=max(0,a-c2);
	int tb=max(0,b-c3);
	return ta+tb<=c6;
}
int main() {
	R(a); R(b);
	while(r-l>1) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid;
		}
	}
	Pn(r);
}

