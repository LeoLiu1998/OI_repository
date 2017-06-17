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
char s[105];
string ans[105][105];
int dp[105][105];
int n;
int main() {
	R(n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) {
		dp[i][i]=1;
		ans[i][i]="()";
	}
	for(int l=1;l<=n;++l) {
		for(int i=1;i<=n-l;++i) {
			int j=i+l;
			dp[i][j]=INT_MAX;
			if(s[i]=='('&&s[j]==')') {
				if(dp[i][j]>dp[i+1][j-1]) {
					dp[i][j]=dp[i+1][j-1];
					ans[i][j]="("+ans[i+1][j-1]+")";
				} else if(dp[i][j]==dp[i+1][j-1]) {
					ans[i][j]=min(ans[i][j],"("+ans[i+1][j-1]+")");				
				}
			}
			if(s[i]=='('&&s[j]!=')') {
				if(dp[i][j]>(dp[i+1][j]+1)) {
					dp[i][j]=dp[i+1][j]+1;
					ans[i][j]="("+ans[i+1][j]+")";
				} else if(dp[i][j]==(dp[i+1][j]+1)) {
					ans[i][j]=min(ans[i][j],"("+ans[i+1][j]+")");
				}
				
			}
			if(s[i]!='('&&s[j]==')') {
				if(dp[i][j]>(dp[i][j-1]+1)) {
					dp[i][j]=dp[i][j-1]+1;
					ans[i][j]="("+ans[i][j-1]+")";
				} else if(dp[i][j]==(dp[i][j-1]+1)) {
					ans[i][j]=min(ans[i][j],"("+ans[i][j-1]+")");
				}
			}
			for(int k=i;k<j;++k) {
				if(dp[i][j]>(dp[i][k]+dp[k+1][j])) {
					dp[i][j]=dp[i][k]+dp[k+1][j];
					ans[i][j]=ans[i][k]+ans[k+1][j];
				} else if(dp[i][j]==(dp[i][k]+dp[k+1][j])) {
					ans[i][j]=min(ans[i][j],ans[i][k]+ans[k+1][j]);
				}
				
			}
		}
	}
	cout<<ans[1][n]<<endl;
}

