//Seldom has chance to write problem F :P
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
inline void R(long long &x) {
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
struct Seg{
	int ls,rs;
	ll l,r,mex,num,nmex;
	int lazy;
	Seg() {
		ls=rs=-1;
		nmex=1e18+1;
		mex=0;
	}
	Seg operator + (const Seg &a) const {
		Seg ret;
		ret.l=l;
		ret.r=a.r;
		ret.num=num+a.num;
		ret.mex=min(mex,a.mex);
		ret.nmex=min(nmex,a.nmex);
		return ret;
	}
};
Seg seg[1000500];
int cnt=-1;
int T;
Seg ms(ll l,ll r,ll mex,ll num,int lazy=0) {
	Seg ret;
	ret.l=l;
	ret.r=r;
	ret.mex=mex;
	ret.num=num;
	ret.lazy=lazy;
	return ret;
}
void Prep(int);
void Pushdown(int pos,int ty) {
	if(ty==1) {
		seg[pos].nmex=seg[pos].l;
		seg[pos].mex=1e18+1;
		seg[pos].num=seg[pos].r-seg[pos].l+1;
	} else if(ty==2) {
		seg[pos].nmex=1e18+1;
		seg[pos].mex=seg[pos].l;
		seg[pos].num=0;
	} else {
		swap(seg[pos].nmex,seg[pos].mex);
		seg[pos].num=seg[pos].r-seg[pos].l+1-seg[pos].num;
		if(seg[pos].lazy==3) {
			seg[pos].lazy=0;
			return ;
		}
	}
	ll mid=(seg[pos].l+seg[pos].r)>>1;
	if(seg[pos].ls==-1) {
		seg[pos].ls=++cnt;
		seg[cnt]=ms(seg[pos].l,mid,seg[pos].l,0);
	}
	if(seg[pos].rs==-1) {
		seg[pos].rs=++cnt;
		seg[cnt]=ms(mid+1,seg[pos].r,mid+1,0);
	}
	seg[pos].lazy=ty;
}
void Prep(int pos) {
	ll mid=(seg[pos].l+seg[pos].r)>>1;
	if(seg[pos].ls==-1) {
		seg[pos].ls=++cnt;
		seg[cnt]=ms(seg[pos].l,mid,seg[pos].l,0);
	}
	if(seg[pos].rs==-1) {
		seg[pos].rs=++cnt;
		seg[cnt]=ms(mid+1,seg[pos].r,mid+1,0);
	}
	if(seg[pos].lazy) {
		Pushdown(seg[pos].ls,seg[pos].lazy);
		Pushdown(seg[pos].rs,seg[pos].lazy);
		seg[pos].lazy=0;
	}
	return ;
}
void Update(int pos) {
	int lp=seg[pos].ls,rp=seg[pos].rs;
	seg[pos].num=seg[lp].num+seg[rp].num;
	seg[pos].mex=min(seg[lp].mex,seg[rp].mex);
	seg[pos].nmex=min(seg[lp].nmex,seg[rp].nmex);
	return ;
}
void Init() {
	seg[++cnt]=ms(1,1e18,1,0);
}
void Fill(int pos,int l,int r) {
	if(seg[pos].l==l&&seg[pos].r==r) {
		seg[pos].mex=1e18+1;
		seg[pos].num=r-l+1;
		seg[pos].nmex=l;
		seg[pos].lazy=1;
		return ;
	}
	ll mid=(seg[pos].l+seg[pos].r)>>1;
	Prep(pos);
	if(r<=mid) {
		Fill(seg[pos].ls,l,r);
	} else if(l>mid) {
		Fill(seg[pos].rs,l,r);
	} else {
		Fill(seg[pos].ls,l,mid);
		Fill(seg[pos].rs,mid+1,r);
	}
	Update(pos);
}
void Remove(int pos,int l,int r) {
	if(seg[pos].l==l&&seg[pos].r==r) {
		seg[pos].mex=l;
		seg[pos].nmex=1e18+1;
		seg[pos].num=0;
		seg[pos].lazy=2;
		return ;
	}
	ll mid=(seg[pos].l+seg[pos].r)>>1;
	Prep(pos);
	ll lp=seg[pos].ls,rp=seg[pos].rs;
	if(r<=mid) {
		Remove(lp,l,r);
	} else if(l>mid) {
		Remove(rp,l,r);
	} else {
		Remove(lp,l,mid);
		Remove(rp,mid+1,r);
	}
	Update(pos);
}
void Revert(int pos,int l,int r) {
	if(seg[pos].l!=seg[pos].r) Prep(pos);
	if(seg[pos].l==l&&seg[pos].r==r) {
		swap(seg[pos].nmex,seg[pos].mex);
		seg[pos].lazy=3;
		seg[pos].num=(r-l+1)-seg[pos].num;
		
		return ;
	}
	ll mid=(seg[pos].l+seg[pos].r)>>1;
	//Prep(pos);
	ll lp=seg[pos].ls,rp=seg[pos].rs;
	if(r<=mid) {
		Revert(lp,l,r);
	} else if(l>mid) {
		Revert(rp,l,r);
	} else {
		Revert(lp,l,mid);
		Revert(rp,mid+1,r);
	}
	Update(pos);
}
int main() {
	R(T);
	int opt,l,r;
	Init();
	while(T--) {
		R(opt); R(l); R(r);
		if(opt==1) {
			Fill(0,l,r);		
		} else if(opt==2) {
			Remove(0,l,r);
		} else {
			Revert(0,l,r);
		}
		cout<<seg[0].mex<<endl;
	}
}	

