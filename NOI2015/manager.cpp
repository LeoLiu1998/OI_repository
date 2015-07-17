#ifdef YGHDEBUG
#include <iostream>
#endif
#include <iostream>
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
#define PROB "manager" 
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

inline void Redirect() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
const int maxn=100050;
struct Seg{
	int l,r,sum;
	bool lazy;
	int lazy_v;
	Seg(){sum=0;}
	Seg(int _l,int _r):l(_l),r(_r){sum=0;lazy=0;}
	Seg(int _l,int _r,int _sum):l(_l),r(_r),sum(_sum),lazy(0){}
};
struct Node{
	int size,f;
	int heavy_child;
	int seg_pos;
	int depth;
	vector<int> son;
	Node(){}
};
Seg seg[4*maxn];
int a[maxn];
Node node[maxn];
int f[maxn];
int tree_pos[maxn];
bool deal[maxn];
int n;
#define pb push_back
//add 1 by brute
void init(int);
void cut(int);
int Install(int);
int Uninstall(int);
void Build(int,int,int);
int temp;
namespace Brute{
	set<int> have;
	int Install(int pos) {
	if(have.count(pos)) return 0;
	if(!pos) {
		have.insert(pos);
		return 1;
	}
	have.insert(pos);
	return 1+Install(node[pos].f);
}

int Uninstall(int pos) {
	if(!have.count(pos)) return 0;
	have.erase(pos);
	int ret=1;
	for(int i=0;i<node[pos].son.size();++i) {
		ret+=Uninstall(node[pos].son[i]);
	}
	return ret;
}
}
int main(){
	Redirect();
	R(n);
	for(int i=2;i<=n;++i){
		R(temp);
		temp++;
		node[temp].son.pb(i);
		node[i].f=temp;
	}
	init(1);
	memset(deal,0,sizeof(deal));
	cut(1);
	
	Build(1,1,n);
	int m;
	R(m);
	char cmd=0;
	if(n<=8000) {
		int pos;
		while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		R(pos);
		if(cmd=='i') Pn(Brute::Install(pos));
		else Pn(Brute::Uninstall(pos));
		
			
		}
			return 0;
	} else {
	while(m--) {
		cmd=0; while(!isalpha(cmd)) cmd=getchar();
		R(temp);
		if(cmd=='i') {
			Pn(Install(temp+1));
		} else {
			Pn(Uninstall(temp+1));
		}
	}
	}
	return 0;
}
int cur_depth=0;
void init(int pos) {
	cur_depth++;
	node[pos].depth=cur_depth;
	deal[pos]=1;
	node[pos].size=1;
	register int cur;
	int heavy_size=-1;
	int size=node[pos].son.size();
	for(int i=0;i<=size-1;++i) {
		cur=node[pos].son[i];
		if(deal[cur]) continue;
		init(cur);
		node[pos].size+=node[cur].size;
		if(node[cur].size>heavy_size) {
			heavy_size=node[cur].size;
			node[pos].heavy_child=cur;
		}
	}
	cur_depth--;
	return ;
}
bool done=1;
int cur_f;
int cnt=1;
void cut(int pos) {
	if(deal[pos]) return ;
	if(!done) {
		f[pos]=cur_f;
	} else {
		done=0;
		f[cur_f]=pos;
		cur_f=pos;
	}
	node[pos].seg_pos=cnt;
	tree_pos[cnt]=pos;
	deal[pos]=1;
	cnt++;
	if(!node[pos].son.size()) done=1;
	else cut(node[pos].heavy_child);
	rep(i,0,(int(node[pos].son.size())-1),1) {
		temp=node[pos].son[i];
		if(!deal[temp]) cut(temp);
	}
}


Seg Merge(Seg sl,Seg sr) {// Merge do not handle lazy tag
//	assert(sl.r+1==sr.l);
	Seg ret(sl.l,sr.r,sl.sum+sr.sum);
	return ret;
}
void Build(int sp,int l,int r) {
	if(l==r){ seg[sp]=Seg(l,r,a[l]); return;}
	Build(sp<<1,l,(l+r)>>1);
	Build(sp<<1|1,((l+r)>>1)+1,r);
	seg[sp]=Merge(seg[sp<<1],seg[sp<<1|1]);
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
void Modify(int sp,int l,int r,int v) {
	if(l>r) swap(l,r);
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
	if(l>r) swap(l,r);
	pushdown(sp);
	if(l==seg[sp].l&&r==seg[sp].r) return seg[sp];
	int mid=seg[sp<<1].r;
	if(r<=mid) return getSeg(sp<<1,l,r);
	if(l>mid) return getSeg(sp<<1|1,l,r);
	Seg sl=getSeg(sp<<1,l,mid), sr=getSeg(sp<<1|1,mid+1,r);
	return Merge(sl,sr);
}
int Seg_S (int sp,int l,int r) {
	Seg sg=getSeg(sp,l,r);
	return sg.sum;
}
int Install(int pos) {
	int a=1,b=pos;
	int ans=0;
	if(f[a]==f[b]) {
		ans+=abs(node[a].seg_pos-node[b].seg_pos+1);
		ans-=Seg_S(1,node[a].seg_pos,node[b].seg_pos);	
		Modify(1,node[a].seg_pos,node[b].seg_pos,1);
	} else {
		while(f[a]!=f[b]){
			if(node[a].depth<node[b].depth) swap(a,b);
			ans+=abs(node[a].seg_pos-node[f[a]].seg_pos+1);
			ans-=Seg_S(1,node[a].seg_pos,node[f[a]].seg_pos);
			Modify(1,node[a].seg_pos,node[f[a]].seg_pos,1);
			a=node[f[a]].f;
		}
		ans+=abs(node[a].seg_pos-node[b].seg_pos);
		ans-=Seg_S(1,node[a].seg_pos,node[b].seg_pos);
		Modify(1,node[a].seg_pos,node[b].seg_pos,1);
	}
	Pn(ans);
}

int Uninstall(int pos) {
	int l=node[pos].seg_pos;
	int r=node[pos].seg_pos+node[pos].size-1;
	int ans=0;
	ans+=Seg_S(1,l,r);
	Modify(1,l,r,0);
}
