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
int n,m;
int a[105];
int cn=0;
int cnt[205];
bool check() {
	for(int i=1;i<=n;++i) {
		if(a[i]<a[i-1]) {
			return 1;
		}
	}
	return 0;
}
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		if(!a[i]) cn++;	
	}
	for(int j=1;j<=m;++j) {
		int t;R(t);
		cnt[t]++;
	}
	for(int i=1;i<=n;++i) {
		if(a[i]) continue;
		int cur;
		for(int j=200;j;--j) {
			if(cnt[j]) {
				cur=j;
				cnt[j]--;
				break;
			}
		}
		a[i]=cur;
	}
	puts(((cn==m)&&check())?"Yes":"No");
	return 0;
}

