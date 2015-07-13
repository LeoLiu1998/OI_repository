#ifdef YGHDEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cassert>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#define PROB "" 
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
const int maxn=100005;
struct Seg {
	int l,r,sum;
	bool lazy;
	int lazy_v;
	Seg(int _l=0,int _r=0,int _sum=0):l(_l),r(_r),sum(_sum),lazy(0){}
};
int a[maxn];
Seg seg[4*maxn];
int n,m;
Seg Merge(Seg sl,Seg sr) {// Merge do not handle lazy tag
	assert(sl.r+1==sr.l);
	Seg ret(sl.l,sr.r,sl.sum+sr.sum);
	return ret;
}
void pushdown(int sp) {
	if(seg[sp].lazy) {
		if(seg[sp].l!=seg[sp].r){
			seg[sp<<1].lazy=1;seg[sp<<1].lazy_v=seg[sp].lazy_v;
			seg[sp<<1|1].lazy=1;seg[sp<<1|1].lazy_v=seg[sp].lazy_v;
		}
		seg[sp].sum=(seg[sp].r-seg[sp].l+1)*seg[sp].lazy_v;
		seg[sp].lazy=0;
	}
	return ;
}
void Build(int sp,int l,int r) {
	if(l==r){ seg[sp]=Seg(l,r,a[l]); return;}
	Build(sp<<1,l,(l+r)>>1);
	Build(sp<<1|1,((l+r)>>1)+1,r);
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
void Modify(int sp,int l,int r,int v) {
	if(seg[sp].l==l&&seg[sp].r==r) {
		seg[sp]=Seg(l,r,(r-l+1)*v);
		if(l!=r) {
			seg[sp<<1].lazy=seg[sp<<1|1].lazy=1;
			seg[sp<<1].lazy_v=seg[sp<<1|1].lazy_v=v;
		}
		return ;
	}
	pushdown(sp);
	pushdown(sp<<1);
	pushdown(sp<<1|1);
	int mid=seg[sp<<1].r;
	if(r<=mid) { Modify(sp<<1,l,r,v); } 
	else if(l>mid){	Modify(sp<<1|1,l,r,v);} 
	else {
		Modify(sp<<1,l,mid,v);
		Modify(sp<<1|1,mid+1,r,v);
	}
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
}
Seg getSeg(int sp,int l,int r){
	pushdown(sp);
	if(l==seg[sp].l&&r==seg[sp].r) return seg[sp];
	int mid=seg[sp<<1].r;
	if(r<=mid) return getSeg(sp<<1,l,r);
	if(l>mid) return getSeg(sp<<1|1,l,r);
	Seg sl=getSeg(sp<<1,l,mid), sr=getSeg(sp<<1|1,mid+1,r);
	return Merge(sl,sr);
}
void Query(int sp,int l,int r) {
	Seg sg=getSeg(sp,l,r);
	Pn(sg.sum);
}
int main() {
	R(n); R(m);
	rep(i,1,n,1) R(a[i]);
	Build(1,1,n);
	char cmd;
	while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='Q') {
			int l,r;
			R(l);R(r);
			Query(1,l,r);
		} else {
			int l,r,v;
			R(l); R(r); R(v);
			Modify(1,l,r,v);
		}
	}
}
