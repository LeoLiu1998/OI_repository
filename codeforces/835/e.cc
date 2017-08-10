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
int n,x,y;
int xo;
pii ans;
void RQ(int l,int r) {
	printf("? %d ",r-l+1);
	rep(i,l,r,1) Ps(i);
	puts("");
	fflush(stdout);
}
pii S2(int l, int r) {
	if(r-l+1==2) return mp(l,r);
	int mid=(l+r)>>1;
	if((mid-l+1)%2) {
		mid--;
	}
	int cur=RQ(l,mid);
	if()
}
int main() {
	R(n); R(x); R(y);
	xo=x^y;
	Ans=S2(1,n);	
}

