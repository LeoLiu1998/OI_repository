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
const int maxn=2505;
int dp[maxn];
int m[maxn];
int n;
int main() {
	R(n);
	rep(i,0,n,1) {
		R(m[i]);
	}
	dp[1]=m[1]+m[0];
	rep(i,2,n,1) {
		dp[i]=dp[i-1]+m[i];	
	}
	rep(i,2,n,1) {
		rep(j,1,i-1,1) {
			dp[i]=min(dp[i],dp[i-j]+m[0]+dp[j]);
		}
	}
	Pn(dp[n]);
}
