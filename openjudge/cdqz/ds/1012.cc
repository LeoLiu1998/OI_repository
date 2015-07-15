#include <bits/stdc++.h>
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
struct Seg{
	int l,r,sum;
	Seg *sl,*sr;
	Seg(int _l=0,int _r=0;int _sum=0):l(_l),r(_r),sum(_sum),sl(NULL),sr(NULL){}
	Seg(int _l,int _r,int _sum,Seg *_sl,Seg *_sr) {
		l=_l; r=_r; sum=_sum;
		sl=_sl; sr=_sr;
	}
};
const int maxn=100050;
int a[maxn];
int b[maxn];
int n,m;
inline int getRank(int k) {
	return (lower_bound(b+1,b+n+1,k)-b);
}
int use=0;
Seg *root[maxn];
Seg sg[30*maxn];
void Build(int sp,int l,int r,int k) {
	if(l==r) {
		sg[sp]=Seg(l,r,k==l);	
		return ;
	} else {
		int sl=++use;
		int sr=++use;
		int mid=(l+r)>>1;
		Build(sl,l,mid,k);
		Build(sr,mid+1,r,k);
		seg[sp]=Seg(l,r,sg[sl].sum+sg[sr].sum,&sg[sl],&sg[sr]);
	}
}
void Merge(Seg *sl, Seg *sr) {
	assert(sl->r +1 ==sr->l);
	Seg ret=Seg(sl->l,sr->r,sl->sum+ sr->sum,sl,sr);
	return ret;

}
void Insert(int t_num,int k) {
	int l=1,r=n;
	root[t_num]=&sg[++use];
}
int main() {
	R(n); R(m);
	rep(i,1,n,1) { R(a[i]); b[i]=a[i];}
	sort(b+1,b+n+1);
	Build(++use,1,n,getRank(a[1]));
	root[1]= &sg[1];
	for(int i=2;i<=n;++i) {
		Insert(i,getRank(a[i]));
	}
}
