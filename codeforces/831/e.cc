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
const int maxn=100500;
struct Seg {
	int l,r,cnt;
	Seg(){}
	Seg operator + (const Seg &a) {
		Seg ret;
		ret.l=l;
		ret.r=a.r;
		ret.cnt=cnt+a.cnt;
		return ret;
	}
};
Seg seg[4*maxn];
pii a[maxn];
int n;
int pos;
ll ans;

void Build(int p,int l,int r) {
	if(l==r) {
		seg[p].l=seg[p].r=l;
		seg[p].cnt=1;
		return ;
	}
	int mid=(l+r)>>1;
	Build(p<<1,l,mid);
	Build(p<<1|1,mid+1,r);
	seg[p]=seg[p<<1]+seg[p<<1|1];
}
void Update(int p, int l,int r,int v) {
	if(seg[p].l==seg[p].r) {
		seg[p].cnt=v;
		return ;
	}
	int mid=seg[p].l+seg[p].r;
	mid>>=1;
	if(r<=mid) {
		Update(p<<1,l,r,v);
	} else {
		Update(p<<1|1,l,r,v);
	}
	seg[p]=seg[p<<1]+seg[p<<1|1];
	return ;
}
int Query(int p,int l,int r) {
	if(seg[p].l==l&&seg[p].r==r) {
		return seg[p].cnt;
	}
	int mid=seg[p].l+seg[p].r;
	mid>>=1;
	if(r<=mid) {
		return Query(p<<1,l,r);
	} else if(l>mid) {
		return Query(p<<1|1,l,r);
	} else {
		return Query(p<<1,l,mid)+Query(p<<1|1,mid+1,r);
	}
}
inline int dist(int l,int r) {
	if(r>l) return r-l;
	else return r+n-l;//3 1 
}
int L_POS;
bool cmp(pii a,pii b) {
	return dist(L_POS,a.se)<dist(L_POS,b.se);
}
int cnt=0;
int main() {
	R(n);
	pos=n;
	for(int i=1;i<=n;++i) {
		R(a[i].fi);
		a[i].se=i;
	}
	a[0].se=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		int l=i,r=i;
		while(a[r+1].fi==a[l].fi) r++;
		L_POS=a[l-1].se;
		if(r!=l) {
			sort(a+l,a+r+1,cmp);
		}
		i=r;
	}
	Build(1,1,n);
	for(int i=1;i<=n;++i) {
		register int tmp=a[i].se;
		if(pos<tmp) ans+=Query(1,pos,tmp);
		else {
			if(pos==n) {
				ans+=Query(1,1,tmp);
			} else {
				ans+=Query(1,pos+1,n);
				ans+=Query(1,1,tmp);
			}
		}
		Update(1,tmp,tmp,0);
		pos=tmp;
		cnt+=(n-i+1);
#ifdef YGHDEBUG
		Pn(n-i+1);
#endif
	}
#ifdef YGHDEBUG
	Pn(cnt);
	Pn(n);
#endif
	cout<<ans<<endl;
}

