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
int n,b;
const int maxn=5005;
int c[maxn],d[maxn];
ll dp[maxn][maxn][2];
ll temp[maxn][2];
int size[maxn];
vector<int> node[maxn];
void dfs(int k,int f=0) {
	size[k]=1;
	dp[k][0][0]=0;
	dp[k][1][0]=c[k];
	dp[k][1][1]=c[k]-d[k];
	for(auto t:node[k]) {
		dfs(t,k);
		memset(temp,0x3f,sizeof temp);
		for(int i=0;i<=size[k];++i) {
			for(int j=1;j<=size[t];++j) {
				temp[i+j][1]=min(temp[i+j][1],dp[k][i][1]+min(dp[t][j][0],dp[t][j][1]));
				temp[i+j][0]=min(temp[i+j][0],dp[k][i][0]+dp[t][j][0]);
			}
		}
		size[k]+=size[t];
		for(int i=1;i<=size[k];++i) {
			for(int q=0;q<2;++q) {
				dp[k][i][q]=min(dp[k][i][q],temp[i][q]);
			}
		}
	}
}
int main() {
	R(n); R(b);
	for(int i=1;i<=n;++i) {
		R(c[i]); R(d[i]);
		if(i==1) continue;
		int f; R(f);
		node[f].pb(i);
	}
	memset(dp,0x3f,sizeof dp);
	dfs(1);
	ll ans=0;
	for(int i=n;~i;--i) {
		if(min(dp[1][i][0],dp[1][i][1])<=b) {
			Pn(i);
			return 0;
		}
	}
}

