//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
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
//typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;
const int maxn=(1e7)+5;
int pre[maxn];
int cnt[maxn];
int n;
int m;
int main() {
	R(n); R(m);
	register int tmp;
	for(int i=1;i<=n;++i) {
		R(tmp);
		cnt[tmp]++;
	}
	for(int i=1;i<=(1e7);++i) {
		pre[i]=pre[i-1]+cnt[i];	
	}
	register int l,r;
	while(m--) {
		R(l); R(r);
		Pn(pre[r]-pre[l-1]);
	}
}

