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
const int maxn=200000;
pii rg[2*maxn+100];
int cnt[2*maxn+100];
int pre[maxn+100];
int n,k,q;
int pool;
int cur=0;
int main() {
	R(n); R(k); R(q);
	for(int i=1;i<=n;++i) {
		int l,r;
		R(l); R(r);
		rg[++pool]=mp(l,0);
		rg[++pool]=mp(r,1);
	}
	sort(rg+1,rg+pool+1);
	for(int i=1;i<=200000;++i) {
		cnt[i]=cnt[i-1];
		while(rg[cur+1]==mp(i-1,1)) {
			--cnt[i]; cur++;
		}
		while(rg[cur+1]==mp(i,0)) {
			cnt[i]++;
			cur++;
		}
	}
	for(int i=1;i<=200000;++i) {
		pre[i]=pre[i-1]+(cnt[i]>=k);
	}
	while(q--) {
		int l,r; R(l); R(r);
		Pn(pre[r]-pre[l-1]);
	}
}

