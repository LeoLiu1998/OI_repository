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
ll dp[105][105][105];
int cost[105][105];
int colo[105];
int n,m,k;
int main() {
	R(n); R(m); R(k);
	for(int i=1;i<=n;++i) {
		R(colo[i]);
	}
	memset(dp,0x4f,sizeof dp);
//	cout<<dp[0][0][0]<<endl;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j)
			R(cost[i][j]);
	
	}
	if(colo[1]==0) {
		for(int i=1;i<=m;++i) {
			dp[1][1][i]=cost[1][i];
		}
	} else {
		dp[1][1][colo[1]]=0;
	}
	for(int i=2;i<=n;++i) {
		if(colo[i]) {
			for(int j=1;j<=k;++j) {
				for(int q=1;q<=m;++q) {
					dp[i][j+(q!=colo[i])][colo[i]]=min(dp[i][j+(q!=colo[i])][colo[i]],dp[i-1][j][q]);
				}
			}
		} else {
			for(int j=1;j<=m;++j) {//colo current
				for(int q=1;q<=k;++q) {//last beatu
					for(int p=1;p<=m;++p) {//colo last
						dp[i][q+(j!=p)][j]=min(dp[i][q+(j!=p)][j],dp[i-1][q][p]+cost[i][j]);
					}
				}
			}
		}
	}
	ll ans=LLONG_MAX;
	for(int i=1;i<=m;++i) {
		ans=min(ans,dp[n][k][i]);
	}
	cout<<(ans==dp[0][0][0]?-1:ans)<<endl;
}

