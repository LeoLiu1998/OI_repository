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
#define PROB "landscape"
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
int n,x,y,z;
const int maxn=100050;
int a[maxn],b[maxn],c[maxn];
struct Seg{
	int l,r;
	int lp,ln,rp,rn,ml,mr;
};
Seg seg[maxn*4];
Seg Merge(int lp,int rp) {
	if(seg[lp].r>seg[rp].l) swap(lp,rp);
	Seg ret;
	ret.l=seg[lp].l; ret.r=seg[rp].r;
	if(seg[lp].lp!=-1) {
		ret.lp=seg[lp].lp;
	} else {
		ret.lp=seg[rp].lp;
	} 
	ret.ln= (seg[lp].ln==-1) ? seg[rp].ln: seg[lp].ln;
	ret.rn= (seg[rp].rn==-1) ? seg[lp].rn : seg[rp].rn;
	ret.rp= (seg[rp].rp==-1) ? seg[lp].rp : seg[rp].rp;
	ret.ml=ret.mr=-1;
	if(seg[lp].ml!=-1) {
		ret.ml=seg[lp].ml;
		ret.mr=seg[lp].mr;
	} 
	if(seg[rp].ml!=-1) {
		int d=seg[rp].mr-seg[rp].ml;
		if(ret.ml==-1||(d<(ret.mr-ret.ml)))  {
			ret.ml=seg[rp].ml;
			ret.mr=seg[rp].mr;
		}
	}
	if(seg[rp].lp!=-1&&seg[lp].rn!=-1) {
		int d=seg[rp].lp-seg[lp].rn;
		if(ret.ml==-1||d<(ret.mr-ret.ml)) {
			ret.ml=seg[lp].rn;
			ret.mr=seg[rp].lp;
		}
	}
	if(seg[rp].ln!=-1&&seg[lp].rp!=-1) {
		int d=seg[rp].ln-seg[lp].rp;
		if(ret.ml==-1||d<(ret.mr-ret.ml)) {
			ret.ml=seg[lp].rp;
			ret.mr=seg[rp].ln;
		}
	}
	return ret;
}
void Build(int p,int l,int r) {
	seg[p].l=l; seg[p].r=r;
	if(l==r) {
		int lp,ln,rp,rn,ml,mr;
		if(c[l]==0) {
			lp=ln=rp=rn=ml=mr=-1;
		} else if(c[l]>0) {
			lp=rp=l;
			ln=rn=ml=mr=-1;
		} else {
			ln=rn=l;
			lp=rp=ml=mr=-1;
		}
		seg[p].lp=lp; seg[p].rp=rp; seg[p].ln=ln; seg[p].rn=rn; seg[p].ml=ml; seg[p].mr=mr;
		return ;
	} else {
		Build(p<<1,l,(l+r)>>1);
		Build(p<<1|1,((l+r)>>1)+1,r);
		seg[p]=Merge(p<<1,p<<1|1);
	}
}
void Modify(int sp,int p,int d) {
	if(seg[sp].l==seg[sp].r) {
		c[p]+=d;
		int lp,rp,ln,rn,ml,mr;
		if(c[p]==0) {
			lp=ln=rp=rn=ml=mr=-1;
		} else if(c[p]>0) {
			lp=rp=p;
			ln=rn=ml=mr=-1;
		} else {
			ln=rn=p;
			lp=rp=ml=mr=-1;
		}
		seg[sp].ln=ln; seg[sp].rn=rn; seg[sp].rp=rp; seg[sp].lp=lp; seg[sp].ml=ml; seg[sp].mr=mr;
	} else {
		int mid=seg[sp].l+seg[sp].r;
		mid=(mid>>1);
		if(p<=mid) {
			Modify(sp<<1,p,d);
		} else {
			Modify(sp<<1|1,p,d);
		}
		seg[sp]=Merge(sp<<1,sp<<1|1);
	}
}
pii Query() {
	return mp(seg[1].ml,seg[1].mr);
}
ll ans=0;
int main() {
	Redirect();
	R(n); R(x); R(y); R(z);
	for(int i=1;i<=n;++i) {
		R(a[i]); R(b[i]);
		c[i]=a[i]-b[i];
	}
	Build(1,1,n);
	do {
		pii cur=Query();
		if(cur.fi==-1) break;
		ll mi=min(abs(c[cur.fi]),abs(c[cur.se]));
		ll cost=mi*(cur.se-cur.fi)*z;
		ll c2=mi*(x+y);
		if(c2<cost) break; 
		else {
			ans+=cost;
			if(c[cur.fi]>0) {
				Modify(1,cur.fi,-1*mi);
				Modify(1,cur.se,mi);
			} else {
				Modify(1,cur.fi,mi);
				Modify(1,cur.se,-1*mi);
			}
		}
	}while(1);
	for(int i=1;i<=n;++i) {
		if(c[i]) {
			if(c[i]<0) ans+= (ll)-1*x*c[i];
			else ans+=c[i]*y;
		}
	}
	cout<<ans<<endl;
}
