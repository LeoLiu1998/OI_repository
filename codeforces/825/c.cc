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
int a[105000];
int ans=0;
int main() {
	R(n); R(k);
	rep(i,1,n,1) R(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		if(2*k>=a[i]) {
			k=max(a[i],k);
			continue;
		}
		while(2*k<a[i]) {
			ans++;
			k<<=1;
		}
		k=max(k,a[i]);
	}
	Pn(ans);
}

