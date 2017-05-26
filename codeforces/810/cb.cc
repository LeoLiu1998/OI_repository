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
int n;
int a[100];
int sel[100];
int ans=0;
void pri(int x) {
	for(int i=1;i<=n;++i) {
		if(!((1<<(i-1))&i)) Ps(0);
		else Ps(1);
	}
	puts("");
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=(1<<n)-1;i;--i) {
		//pri(i);
		int cur=0;
		for(int j=1;j<=n;++j) {
			if(!((1<<(j-1))&i)) continue;
			for(int k=1;k<=n;++k) {
				if(!((1<<(k-1))&i)) continue;	
				cur=max(cur,abs(a[j]-a[k]));
			}
		}
		ans+=cur;
	}
	Pn(ans);
}

