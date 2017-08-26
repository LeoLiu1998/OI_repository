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
int a[10005];
int t,f;
int c;
int main() {
	R(n); R(k);
	for(int i=1;i<=k;++i) {
		R(a[i]);
	}
	for(int i=1;i<=k;++i) {
		int rm=n-f;
		int del=min(rm,a[i]/4);
		f+=del;
		a[i]-=4*del;
	}
	for(int i=1;i<=k;++i) {
		int rm=2*n-t;
		int del=min(rm,a[i]/2);
		t+=del;
		a[i]-=2*del;
	}
	for(int i=1;i<=k;++i) {
		int rm=n-f;
		int del=min(rm,a[i]/2);
		f+=del;
		a[i]-=2*del;
		c+=del;
	}
	int rm=0;
	for(int i=1;i<=k;++i) {
		rm+=a[i];
	}
	if(rm<=(2*n-t+c+(n-f)*2)) {
		puts("YES");
	} else {
		puts("NO");
	}
}

