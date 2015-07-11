#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
//#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void Out(int x) {
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x>9) Out(x/10);
	putchar(x%10+'0');
}
inline void Pn(const int &x) {
	Out(x);
	putchar('\n');

}
#define mp make_pair
#define pn first
#define pv second
const int maxn=100050;
int a[maxn];
/*
struct Seg {
	int l,r;
	bool flag;
	int sum;
	Seg(int _l=0,int _r=0):l(_l),r(_r),flag(0){}
};
Seg seg[4*maxn];
*/
int bit[maxn];
int f[maxn];
int n;
inline void Modify(int,int);
inline int Query(int);
#define lowbit(x) (x&(-x))
inline void Update(int x,int delta) {
	for(x;x<=n;x+=lowbit(x)) {
		bit[x]+=delta;
	}
}
int main() {
	R(n);
	rep(i,1,n,1){R(a[i]);Update(i,a[i]);}
	int T;
	R(T);
	register int cmd,l,r;
	while(T--) {
		R(cmd);R(l);R(r);
		if(l>r) swap(l,r);
		if(cmd==1){
			Pn(Query(r)-Query(l-1));
		} else {
			Modify(l,r);
		}
	}
}

int getf(int x) {
	if(!f[x]||f[x]==x)
		return f[x]=x;
	return f[x]=getf(f[x]);  
}
inline void Modify(int l,int r) {
	for(int i=l;i<=r;i=getf(i+1)) {
		int delta=sqrt(a[i])-a[i];
		a[i]+=delta;
		Update(i,delta);
		if(a[i]==0||a[i]==1) {
			f[i]=getf(i+1);  	
		}
	}
}
inline int Query(int x) {
	int ret=0;
	 for(;x;x-=lowbit(x)) 
		 ret+=bit[x];
	return ret;
}


/*inline void Build(int sp,int l,int r) {
	seg[sp]=Seg(l,r);
	if(l==r) {
		seg[sp].sum=a[l];
		return ;
	}
	Build(sp<<1,l,(l+r)>>1);
	Build(sp<<1|1,((l+r)>>1)+1,r);
	seg[sp].sum=seg[sp<<1].sum+seg[sp<<1|1].sum;
}
inline void Modify(int sp,int l,int r) {
	if(seg[sp].flag) return;
	if(seg[sp].l==seg[sp].r) {
		a[l]=sqrt(a[l]);
		seg[sp].sum=a[l];
		if(seg[sp].sum==0||seg[sp].sum==1) {
			seg[sp].flag=1;
			return ;
		}
	} else {
		int mid=seg[sp].l+seg[sp].r;
		mid>>=1;
		if(r<=mid) {
			Modify(sp<<1,l,r);
		} else if(l>mid){
			Modify(sp<<1|1,l,r);
			
		} else {
			Modify(sp<<1,l,mid);
			Modify(sp<<1|1,mid+1,r);
		}
		if(seg[sp<<1].flag&&seg[sp<<1|1].flag){
			seg[sp].flag=1;
		}
		seg[sp].sum=seg[sp<<1].sum+seg[sp<<1|1].sum;
	}
}

inline int Query(int sp,int l,int r) {
	if(seg[sp].l==l&&seg[sp].r==r) {
		return seg[sp].sum;
	}
	int mid=seg[sp].l+seg[sp].r;
	mid >>= 1;
	if(r<=mid) return Query(sp<<1,l,r);
	if(l>mid) return Query(sp<<1|1,l,r);
	else {
		int ret=Query(sp<<1,l,mid);
		ret+=Query(sp<<1|1,mid+1,r);
		return ret;
	}
}
*/
