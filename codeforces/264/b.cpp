//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int gcd(int x, int y) {
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
int n;
int a[100050];
int opt[100050];
int ans=0;
int buff[100050];
int cnt=0;
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
		int k = a[i];
		int tans=1;
		cnt=0;
		for(int j=2;j*j<=k;++j) {
			if(k%j==0) {
				tans=max(tans,1+opt[j]);
				k/=j;
				buff[++cnt]=j;
			}
			while(k%j==0) {
				k/=j;
			}
		}
		if(k>1) {
			tans=max(tans,1+opt[k]);
			buff[++cnt]=k;
		}
		opt[a[i]]=tans;
		rep(j,1,cnt,1) {
			opt[buff[j]]=max(opt[buff[j]],tans);
		}
		ans=max(tans,ans);
	}
	Pn(ans);	
}


