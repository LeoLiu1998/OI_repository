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
//#define 1000000000000100000l 1000000000000100000l
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct Seg{
	int ls,rs;
	ll l,r,mex,nmex;
	int lazy;
	Seg() {
		ls=rs=-1;
		nmex=1000000000000100000l;
		mex=0;
	}
	Seg operator + (const Seg &a) const {
		Seg ret;
		ret.l=l;
		ret.r=a.r;
		ret.mex=min(mex,a.mex);
		ret.nmex=min(nmex,a.nmex);
		return ret;
	}
};
Seg seg[30000500];
int cnt=-1;
int T;
Seg ms(ll l,ll r,ll mex,int lazy=0) {
	Seg ret;
	ret.l=l;
	ret.r=r;
	ret.mex=mex;
	ret.lazy=lazy;
	return ret;
}
#define mid ((seg[pos].l+seg[pos].r)>>1)
void Prep(int);
void Pushdown(int pos,int ty) {
	if(ty==1) {
		seg[pos].nmex=seg[pos].l;
		seg[pos].mex=1000000000000100000l;
	} else if(ty==2) {
		seg[pos].nmex=1000000000000100000l;
		seg[pos].mex=seg[pos].l;
	} else {
		if(seg[pos].lazy) {
			Prep(pos);
		}
		swap(seg[pos].nmex,seg[pos].mex);
	}
	if(seg[pos].ls==-1) {
		seg[pos].ls=++cnt;
		seg[cnt]=ms(seg[pos].l,mid,seg[pos].l);
	}
	if(seg[pos].rs==-1) {
		seg[pos].rs=++cnt;
		seg[cnt]=ms(mid+1,seg[pos].r,mid+1);
	}
	seg[pos].lazy=ty;
}
void Prep(int pos) {
	if(seg[pos].ls==-1) {
		seg[pos].ls=++cnt;
		seg[cnt]=ms(seg[pos].l,mid,seg[pos].l);
	}
	if(seg[pos].rs==-1) {
		seg[pos].rs=++cnt;
		seg[cnt]=ms(mid+1,seg[pos].r,mid+1);
	}
	if(seg[pos].lazy) {
		Pushdown(seg[pos].ls,seg[pos].lazy);
		Pushdown(seg[pos].rs,seg[pos].lazy);
		seg[pos].lazy=0;
	}
	return ;
}
void Update(int pos) {
	seg[pos].mex=min(seg[seg[pos].ls].mex,seg[seg[pos].rs].mex);
	seg[pos].nmex=min(seg[seg[pos].ls].nmex,seg[seg[pos].rs].nmex);
	return ;
}
void Init() {
	seg[++cnt]=ms(1,1e18,1);
}
void Fill(int pos,ll l,ll r) {
	if(seg[pos].l==l&&seg[pos].r==r) {
		seg[pos].mex=1000000000000100000l;
		seg[pos].nmex=l;
		seg[pos].lazy=1;
		return ;
	}
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
void Remove(int pos,ll l,ll r) {
	if(seg[pos].l==l&&seg[pos].r==r) {
		seg[pos].mex=l;
		seg[pos].nmex=1000000000000100000l;
		seg[pos].lazy=2;
		return ;
	}
	Prep(pos);
	if(r<=mid) {
		Remove(seg[pos].ls,l,r);
	} else if(l>mid) {
		Remove(seg[pos].rs,l,r);
	} else {
		Remove(seg[pos].ls,l,(seg[pos].l+seg[pos].r)>>1);
		Remove(seg[pos].rs,((seg[pos].l+seg[pos].r)>>1)+1,r);
	}
	Update(pos);
}
void Revert(int pos,ll l,ll r) {
	if(seg[pos].l!=seg[pos].r) Prep(pos);
	if(seg[pos].l==l&&seg[pos].r==r) {
		swap(seg[pos].nmex,seg[pos].mex);
		seg[pos].lazy=3;
		
		return ;
	}
	//Prep(pos);
	if(r<=mid) {
		Revert(seg[pos].ls,l,r);
	} else if(l>mid) {
		Revert(seg[pos].rs,l,r);
	} else {
		Revert(seg[pos].ls,l,mid);
		Revert(seg[pos].rs,mid+1,r);
	}
	Update(pos);
}
int main() {
	R(T);
	ll opt,l,r;
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
	cerr<<cnt<<endl;
}	
