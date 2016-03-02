/*
PROB: stamps
ID : yeguang2
LANG: C++11
*/
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
#define PROB "stamps"
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
int a[205];
int dp[2005000];
int n,k;
int main() {
	Redirect();
	R(k); R(n);
	rep(i,1,n,1) {
		R(a[i]);
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0; int i;
	for(i=0;dp[i]<=k;++i) {
		for(int j=1;j<=n;++j) {
			dp[i+a[j]]=min(dp[i]+1,dp[i+a[j]]);
		}
	}
	Pn(i-1);
}

