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
int n,m;
pii a[100500];
bool flag[100500];
pii b[100500];
struct Seg {
	int l,r,c,lm,rm;
	Seg() {
	}
	Seg(int _l,int _r,int _c,int _lm,int _rm) {
		l=_l; r=_r; c=_c; lm=_lm; rm=_rm;
	}
	Seg operator + (const Seg &a) {
		Seg ret=Seg(l,a.r,c+a.c,min(lm,a.lm),max(rm,a.rm));
		ret.c += max(0,a.lm-1-rm);
		return ret;
	}
};

Seg seg[500005];
void Build(int pos,int l,int r) {
	if(l==r) {
		seg[pos]=Seg(l,r,0,a[l].fi,a[l].se);
	} else {
		Build(pos<<1,l,(l+r)>>1);
		Build(pos<<1|1,((l+r)>>1)+1,r);
		seg[pos]=seg[pos<<1]+seg[pos<<1|1];
	}
}

#define qmid ((seg[pos].l+seg[pos].r)>>1)

Seg Query(int pos,int l, int r) {
	if(seg[pos].l==l&&seg[pos].r==r) {
		return seg[pos];
	} 
	if(r<=qmid) {
		return Query(pos<<1,l,r);	
	} else if(l>qmid) {
		return Query(pos<<1|1,l,r);
	} else {
		return Query(pos<<1,l,qmid)+Query(pos<<1|1,qmid+1,r);
	}
}

int ans=0;
int main() {
	while(~scanf("%d%d",&n,&m)) {
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ans=0;
		for(int i=1;i<=n;++i) {
			R(a[i].fi); R(a[i].se);	
		}
		memset(seg,0,sizeof seg);
		sort(a+1,a+n+1);
		int cr=0;
		for(int i=1;i<=n;++i) {
			if(a[i].se<=cr) flag[i]=1;
			cr=max(cr,a[i].se);
		}
		int cnt=0;
		for(int i=1;i<=n;++i) {
			if(flag[i]) continue;
			b[++cnt]=a[i];
		}
		n=cnt;
		swap(a,b);
		Build(1,1,n);
		for(int i=1;i<=n;++i) {
			Seg cur=Query(1,i,n);
			if(cur.c<=m) {
				ans=max(ans,cur.rm-cur.lm+1+(m-cur.c));	
			} else {
				int l=i,r=n;
				while(r-l>1) {
					int mid=(l+r)>>1;
					Seg smg=Query(1,i,mid);
					if(smg.c<=m) {
						l=mid;
					} else {
						r=mid;
					}
				}
				cur=Query(1,i,l);
				ans=max(ans,cur.rm-cur.lm+1+(m-cur.c));
			}
			continue;
		}
		Pn(ans);
	}
}

