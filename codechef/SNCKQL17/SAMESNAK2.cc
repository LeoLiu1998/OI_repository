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
struct Node {
	int x,y,id,nx,ny;
	Node(){};
	void RN() {
		R(x); R(y);
	}
};
bool cmpx(Node a, Node b) {
	return a.x<b.x;
}
bool cmpy(Node a, Node b) {
	return a.y<b.y;
}
bool cmpi(Node a,Node b) {
	return a.id<b.id;
}
Node node[5];
set<pii> e;
set<int> s;
int cnt[101];
int f[101];
int T;
inline int Calc(int a,int b) {
	return a*10+b;
}
void Add_edge(Node a, Node b) {
	s.insert(Calc(a.nx,a.ny));
	s.insert(Calc(b.nx,b.ny));
	if(a.nx==b.nx) {
		if(a.ny>b.ny) swap(a,b);
		for(int i=a.ny;i<b.ny;++i) {
			int l=Calc(a.nx,i),r=Calc(a.nx,i+1);
			s.insert(l); s.insert(r);
			e.insert(mp(l,r));
		}
	} else if(a.ny==b.ny) {
		if(a.nx>b.nx) swap(a,b);
		for(int i=a.nx;i<b.nx;++i) {
			int l=Calc(i,a.ny),r=Calc(i+1,a.ny);
			s.insert(l); s.insert(r);
			e.insert(mp(l,r));
		}
	}
}
int getf(int x) {
	if(f[x]!=x) return f[x]=getf(f[x]);
	else return f[x];
}
int main() {
	R(T);
	while(T--) {
		memset(node,0,sizeof node);
		memset(f,0,sizeof f);
		memset(cnt,0,sizeof cnt);
		s.clear();
		e.clear();
		int cnx=0;
		int cny=0;
		for(int i=1;i<=4;++i) {
			node[i].RN();
			node[i].id=i;
		}
		sort(node+1,node+5,cmpx);
		rep(i,1,4,1) {
			if(node[i].x==node[i-1].x) node[i].nx=cnx;
			else node[i].nx=++cnx;
			
		}
		sort(node+1,node+5,cmpy);
		rep(i,1,4,1) {
			if(node[i].y==node[i-1].y) node[i].ny=cny;
			else node[i].ny=++cny;
		}
		sort(node+1,node+5,cmpi);
		Add_edge(node[1],node[2]);
		Add_edge(node[3],node[4]);
		int ini=Calc(node[1].nx,node[1].ny);
		for(auto i:e) {
			cnt[i.fi]++;
			cnt[i.se]++;
		}
		for(int i=1;i<=100;++i) {
			f[i]=i;
		}
		for(auto i:e) {
			int ff=getf(i.fi),fs=getf(i.se);
			f[ff]=f[fs]=min(ff,fs);
		}
		for(auto i:s) {
			if((cnt[i]>2)||getf(i)!=getf(ini)) {
				puts("no");
				goto NEX;
			}
		}
		puts("yes");
NEX:
		continue;
	}
}

