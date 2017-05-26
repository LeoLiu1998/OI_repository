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
int n,k;
int a[100050];
int pre[100050];
int suf[100050];
int main() {
	R(n); R(k);
	memset(pre,0x3f,sizeof pre);
	memset(suf,0x3f,sizeof suf);
	for(int i=1;i<=k;++i) {
		int t; R(t);
		a[t]=1;
	}
	for(int i=1;i<=n;++i) {
		if(a[i]) pre[i]=0;
		else pre[i]=pre[i-1]+1;
	}
	for(int i=n;i;--i) {
		if(a[i]) suf[i]=0;
		else suf[i]=suf[i+1]+1;
	}
	int l,r;
	while(cin>>l>>r) {
		if(min(pre[l],suf[l])<=min(pre[r],suf[r])) {
			puts("TAK");
		} else {
			puts("NIE");
		}
	}
	
}

