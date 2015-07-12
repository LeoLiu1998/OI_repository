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
#include <cassert>
#include <algorithm>
#include <vector>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%lld\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

typedef long long ll;
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct Seg {
	int l,r;
	ll sqr,mul,sum;
	Seg(int _l=0,int _r=0,ll _sqr=0,ll _mul=0,ll _sum=0):l(_l),r(_r),sqr(_sqr),mul(_mul),sum(_sum){}
};
int n,m;
const int Kmod=1000000007;
const int maxn=100050;
Seg seg[maxn<<2];
ll a[maxn];
Seg Merge(Seg sl,Seg sr) {
	//assert(sl.r+1==sr.l);
	Seg ret=Seg(sl.l,sr.r,(sl.sqr+sr.sqr)%Kmod,0,(sl.sum+sr.sum)%Kmod);
	ret.mul=(sl.mul+sr.mul)%Kmod;
	ret.mul+=a[sl.r]*a[sr.l];
	ret.mul%=Kmod;
	return ret;
}

void Build(int sp,int l,int r) {
	if(l==r) {
		seg[sp]=Seg(l,r,(a[l]*a[l])%Kmod,0,a[l]);
		return ;
	}
	Build(sp<<1,l,(l+r)>>1);
	Build(sp<<1|1,((l+r)>>1)+1,r);
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
void Modify(int sp,int pos, ll v) {
	if(seg[sp].l==seg[sp].r&&seg[sp].l==pos) {
		a[pos]=v;
		seg[sp]=Seg(pos,pos,(v*v)%Kmod,0,v);
		return ;
	}
	if(pos<=seg[sp<<1].r)
		Modify(sp<<1,pos,v);
	else Modify(sp<<1|1,pos,v);
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
Seg getSeg(int sp,int l,int r) {
	if(l==seg[sp].l&&r==seg[sp].r) return seg[sp];
	int mid=seg[sp<<1].r;
	if(r<=mid) 
		return getSeg(sp<<1,l,r);
	if(l>mid)
		return getSeg(sp<<1|1,l,r);
	Seg sl=getSeg(sp<<1,l,mid);
	Seg sr=getSeg(sp<<1|1,mid+1,r);
	return Merge(sl,sr);
}
void Mod(ll &num) {
	if(num<0){
		num+=((-num)/Kmod+1)*Kmod;
		return ;
	}
	num%=Kmod;
	return ;
}
void QuerySqr(int sp,int l,int r) {
	Seg sg=getSeg(sp,l,r);
	ll ans=sg.sum*sg.sum;
	ans-= sg.sqr;
	//assert(!(ans&1));
	ans%=Kmod;
	ans*=500000004;
	Mod(ans);
	Pn(ans);
}
void QueryMul(int sp,int l,int r){
	Seg sg=getSeg(sp,l,r);
	ll ans=0;
	ans=sg.mul;
	Mod(ans);
	Pn(ans);
}
int main() {
	R(n); R(m);
	rep(i,1,n,1) {R(a[i]);a[i]%=Kmod;}
	Build(1,1,n);
	char cmd;
	while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='M') {
			int pos;
			ll v;
			R(pos); R(v);
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
