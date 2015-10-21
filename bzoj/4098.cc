//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int mod=1000000007;
const int maxn=505;
#define add(x,y) x=(x+y)%mod
int mape[maxn][maxn];
int dp[2][maxn][maxn];//dp[i][j][x] means for the right corner is at j,i for the right corner is at n+1-(i+j-x),n+1-x
int getc() {
	char ch=getchar();
	while(!isalpha(ch)) ch=getchar();
	return ch-'a'+1;
}
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			mape[i][j]=getc();
		}
	}
	if(mape[1][1]!=mape[n][n]) {
		puts("0"); return 0;
	}
	int ans=0;
	for(int i=1;i<=n;++i) {
		int cur=i&1; int last=cur^1;
		memset(dp[cur],0,sizeof(dp[cur]));
		for(int j=1;j<=n;++j) {
			if(i+j>=n+2) break;
			for(int k=1;k<=(i+j)&&k<=n;++k) {
				if(i==j&&k==1&&i==k) {
					dp[cur][j][k]=1;
				}
				if(mape[i][j]!=mape[n+1-k][n+1-(i+j-k)]) continue;
				add(dp[cur][j][k],dp[last][j][k]);
				add(dp[cur][j][k],dp[last][j][k-1]);
				add(dp[cur][j][k],dp[cur][j-1][k]);
				add(dp[cur][j][k],dp[cur][j-1][k-1]);
				if(i+j==n+1&&n+1-k==i) {
					add(ans,dp[cur][j][k]);			
				}
			}
		}
	}
	Pn(ans);
}
