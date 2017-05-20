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
const int maxn=100050;
ll dp[maxn][4];
int a[maxn][4];
int n;
int main() {
	R(n);
	for(int i=1;i<=3;++i) {
		for(int j=1;j<=n;++j) {
			R(a[j][i]);
		}
	}
	dp[1][1]=a[1][1];
	dp[1][2]=dp[1][1]+a[1][2];
	dp[1][3]=dp[1][2]+a[1][3];
	for(int i=2;i<=n;++i) {
		for(int j=1;j<=3;++j) {
			dp[i][j]=dp[i-1][j]+a[i][j];
			if(i==2) continue;
			if(j==1) {
				dp[i][j]=max(dp[i][j],max(dp[i-1][j+1]+a[i-1][j]+a[i][j],dp[i-1][j+2]+a[i-1][j+1]+a[i-1][j]+a[i][j]));
			} else if (j==2) {
				dp[i][j]=max(dp[i][j],max(dp[i-1][j+1]+a[i-1][j],dp[i-1][j-1]+a[i-1][j])+a[i][j]);
			} else if(j==3) {
				dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]+a[i-1][j],dp[i-1][j-2]+a[i-1][j-1]+a[i-1][j])+a[i][j]);
			}
		}
	}
	dp[n][2]=max(dp[n][2],dp[n][1]+a[n][2]);
	dp[n][3]=max(dp[n][3],dp[n][2]+a[n][3]);
	cout<<dp[n][3]<<endl;
}

