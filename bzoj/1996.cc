//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int Kmod=19650827;
const int maxn=1005;
int dp[maxn][maxn][2];//0left 1right
int a[maxn];
int n;
int solve(int l,int r,int k) {
	if(dp[l][r][k]>=0) return dp[l][r][k];
	int ans=0;
	if(k) {
		if(a[l]<a[r]) ans+=solve(l,r-1,0);
		if(l!=r-1&&a[r-1]<a[r]) ans+= solve(l,r-1,1);
	} else {
		if(a[l+1]>a[l]) ans+=solve(l+1,r,0);
		if(l+1!=r&&a[r]>a[l]) ans+=solve(l+1,r,1) ;
	}
	ans%=Kmod;
	dp[l][r][k]=ans;
	return ans;
}
int main() {
	memset(dp,-1,sizeof(dp));
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
		dp[i][i][0]=dp[i][i][1]=1;
	}
	solve(1,n,0);
	solve(1,n,1);
	Pn((dp[1][n][0]+dp[1][n][1])%Kmod);
}
