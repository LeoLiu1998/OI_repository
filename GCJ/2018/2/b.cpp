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
int dp[505][505][33][33];
int r,b;
int solve(int i, int j, int k ,int l) {
	if(i<0||j<0||k<0||l<0) return 0;
	if(dp[i][j][k][l]!=0) return dp[i][j][k][l];
	int cur=0;
	if(l!=0)
		cur=solve(i,j-l,k,l-1)+1;
	else {
		for(int q=0;q<=b;++q) {
			cur=max(cur,1+solve(i-k,j,k-1,q));
		}
	}
	return dp[i][j][k][l]=cur;
}

int main() {
	int T=0; R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		R(r); R(b);
		int ans=0;
		for(int i=0;i<=r;++i) {
			for(int j=0;j<=b;++j) {
				ans=max(ans,solve(r,b,min(r,33),min(b,33)));
			}
		}
		printf("Case #%d: %d\n",qwq,ans);
	}
}


