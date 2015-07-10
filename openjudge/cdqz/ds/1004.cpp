#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
struct Seg {
	int l,r;
	ll sqr,mul,sum;
	Seg(int _l=0,int _r=0,ll _sqr=0,ll _mul=0,ll _sum=0):l(_l),r(_r),sqr(_sqr),mul(_mul),sum(_sum);
}
int n,m;
const int Kmod=1000000007;
const int maxn=100050;
Seg seg[maxn<<2];
ll a[maxn];
Seg merge(Seg sl,Seg sr) {
	assert(sl.r+1==sr.l);
	Seg ret=Seg(sl.l,sr.r,(sl.sqr+sr.sqr)%=Kmod,0,(sl.sum+sr.sum)%=Kmod);
	ret.mul=(sl.mul+sr.mul)%=Kmod;
	ret.mul+=a[sl.r]*a[sr].l;
	ret%=Kmod;
}

void Build(int sp,int l,int r) {
	if(l==r) {
		seg[sp]=Seg(l,r,a[l]*a[l],0,a[l]);
		return ;
	}
	Build(sp<<1,l,(l+r)>>1);
	Build(sp<<1|1,((l+r)>>1)+1,r);
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
void Modify(int sp,int pos, int v) {
	if(seg[sp].l==seg[sp].r&&seg[sp].l==pos) {
		a[pos]=v;
		seg[sp]=Seg(pos,pos,(v*v)%Kmod,0,v);
		return ;
	}
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
Seg getSeg(int sp,int l,int r) {
	if(l==seg[sp].l&&r==seg[sp].r) return seg[sp];
	int mid=(l+r)>>1;
	if(r>=mid) 
		return getSeg
}
void QuerySqr(int sp,int l,int r) {
	
}

int main() {
	R(n); R(m);
	rep(i,1,n,1) R(a[i]);
	Build(1,i,n);
	char cmd;
	while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='M') {
			int pos,v;
			Modify(1,pos,v);
		} else if(cmd=='Q'){
			int l,r;
			R(l); R(r);
			QuerySqr(1,l,r);
		} else {
			int l,r;
			R(l); R(r);
			QueryMul(1,l,r);
		}
	}
}
