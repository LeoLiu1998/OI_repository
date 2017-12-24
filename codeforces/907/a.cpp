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
int a[5];
int ans[5];
int main() {
	rep(i,1,4,1) {
		R(a[i]);
	}
	ans[1]=2*a[1];
	ans[4]=a[4];
	for(int i=ans[4];i<=2*ans[4];++i) {
		if(i>=a[3]&&i<=a[3]*2)
		for(int j=max(i+1,2*ans[4]+1);j<ans[1];++j) {
			if(j>=a[2]&&j<=a[2]*2)  {
				ans[2]=j;
				ans[3]=i;
				rep(k,1,3,1) {
					Pn(ans[k]);
				}
				return 0;
			}
		}
	}
	Pn(-1);
}
