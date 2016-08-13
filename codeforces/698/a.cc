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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int dp[105][5];
int a[105];
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][2]=0;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=2;++j) {
			dp[i][2]=min(dp[i-1][j]+1,dp[i][2]);		
		}
		for(int j=0;j<=1;++j) {
			if((1<<j)&a[i]) {
				dp[i][j]=min(dp[i-1][j^1],dp[i][j]);
				dp[i][j]=min(dp[i-1][2],dp[i][j]);
			}
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<3;++i) ans=min(ans,dp[n][i]);
	Pn(ans);
}


