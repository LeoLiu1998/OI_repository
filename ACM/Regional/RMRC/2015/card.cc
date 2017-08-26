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
int T;
int n;
int f[150050],s[150050],e[150050];
int getf(int x) {
	if(f[x]==x) return x;
	f[x]=getf(f[x]);
	return f[x];
}

void Merge(int l,int r) {
	int fl=getf(l),fr=getf(r);
	if(fl==fr) {
		e[fl]+=1;
		return ;
	}
	int ff=min(fl,fr);
	int st=s[fl]+s[fr];
	int ef=e[fl]+e[fr]+1;
	f[fr]=f[fl]=f[ff];
	s[ff]=st;
	e[ff]=ef;
}

int main() {
	R(T);
	while(T--) {
		memset(e,0,sizeof e);
		R(n);
		rep(i,1,n,1) s[i]=1,f[i]=i;
		for(int i=1;i<=n;++i) {
			int l,r;
			R(l); R(r);
			Merge(l,r);
		}
		for(int i=1;i<=n;++i) {
			int fa=getf(i);
			cerr<<e[i]<<" "<<s[i]<<endl;
			if(e[i]>s[i]) {
				puts("impossible");
				goto NEX;
			}
		}
		puts("possible");
NEX:
		continue;
	}
}

