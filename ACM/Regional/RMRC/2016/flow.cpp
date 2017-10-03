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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int cost[1005][1005];
ll dp[1005][1005];
int n,m;
int main() {
	ll cur=0;
	R(n); R(m);
	rep(i,1,n,1) {
		rep(j,1,m,1) {
			R(cost[i][j]);
		}
	}
	rep(i,1,n,1) {
		rep(j,1,m,1) {
			dp[i][j]=max(dp[i-1][j]+cost[i][j],dp[i][j-1]+cost[i][j]);
		}
		Pls(dp[i][m]);
	}
	puts("");
}
