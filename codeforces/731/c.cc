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
int n,m,k;
const int maxn=200500;
int colo[maxn];
int f[maxn];
bool vis[maxn];
int getf(int x) {
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}
struct G{
	map<int,int> cnt;
	int msock,tot;
	G() {
		cnt.clear();
		msock=0;
	}
};
map<int,G> cl;
int main() {
	R(n); R(m); R(k);
	for(int i=1;i<=n;++i) {
		R(colo[i]);
		f[i]=i;
	}
	while(m--) {
		int l,r,lf,rf; 
		R(l); R(r);
		lf=getf(l); rf=getf(r);
		f[lf]=f[rf]=min(lf,rf);
	}
	for(int i=1;i<=n;++i) {
		G &t = cl[f[i]];
		t.tot++;
		t.cnt[colo[i]]++;
		if(t.msock==0) t.msock=colo[i];
		else t.msock= t.cnt[t.msock] > t.cnt[colo[i]] ? t.msock : colo[i];
	}
	int ans=0;
	for(map<int,G>::iterator i=cl.begin();i!=cl.end();i++) {
		G &t = i->second;
		ans+= (t.tot-t.cnt[t.msock]);
	}
	Pn(ans);
}

