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
int n,p;
int g[105];
int r[7];
int main() {
	R(T);
	for(int i=1;i<=T;++i) {
		int ans=0;
		R(n); R(p);
		for(int i=0;i<=5;++i) r[i]=0;
		for(int i=1;i<=n;++i) {
			R(g[i]);
			r[g[i]%p]++;
		}
		if(p==2) {
			ans=n-r[1]/2;	
		} else if(p==3) {
			ans=r[0]+min(r[2],r[1]);
			if(r[1]>r[2]) {
				ans+=((r[1]-r[2])/3)+((r[1]-r[2])%3!=0);
			} else {
				ans+=((r[2]-r[1])/3)+((r[2]-r[1])%3!=0);
			}
		} else {
			int remain=0;
			ans=r[0]+min(r[1],r[3])+r[2]/2;
			if(r[2]%2) {
				remain=2;
			}
			int r2=abs(r[1]-r[3]);
			ans+= ((r2+remain)/4) +((r2+remain)%4!=0);
		}
		printf("Case #%d: %d\n",i,ans);
	}
}

