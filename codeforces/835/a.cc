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
int s,v1,v2,t1,t2;
double a,b;
int main() {
	R(s); R(v1); R(v2); R(t1); R(t2);
	a=1.0*s*v1+2*t1;
	b=1.0*s*v2+2*t2;
	cerr<<a<<endl<<b<<endl;
	if(fabs(a-b)<1e-6) {
		puts("Friendship");
	} else if(a<b) {
		puts("First");
	} else {
		puts("Second");
	}
}

