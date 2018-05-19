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
int T,n;
int w[105],h[105];
int p;
double maxi;
int main() {
	R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		R(n); R(p);
		maxi=0;
		bool small = 1;
		for(int i=1;i<=n;++i) {
			R(w[i]); R(h[i]);
			if((i>1)&&((w[i]!=w[i-1])||(h[i]!=h[i-1]))) small=0;
			maxi+=w[i]*2;
			maxi+=h[i]*2;
			maxi+=sqrt(w[i]*w[i]+h[i]*h[i])*2;
		}
		double ans = min((double)p,maxi);
		if(small) {
			ans = 0;
			for(int i=0;i<=n;++i) {
				for(int qqq=0;qqq<=0;++qqq) { // j is cut again
					int j=n-i;
					double base=(double)(i+j)*(w[1]+h[1])*2;
					double low = base + j*(2*min(w[1],h[1]));
					double high = base + sqrt(w[1]*w[1]+h[1]*h[1])*j*2;
					if(high<=p) {
						if(fabs(p-high) <fabs(p-ans))
							ans = high;
					} else if(low<=p&&high>=p) {
						ans = p;
					}
				}
			}
		}
		printf("Case #%d: %.6f\n",qwq,ans);
	}
}


