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
pii a[2005];
int dp[2005][2005];
pii l[2005][2005];
int ans;
int n,m;
bool cmp(pii a,pii b) {
	if(a.fi!=b.fi) return a.fi<b.fi;
	else return a.se>b.se;
}
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		R(a[i].fi); R(a[i].se);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		dp[i][i]=0;
		l[i][i]=a[i];
		ans=max(ans,l[i][i].se+1-l[i][i].fi+m);
		for(int j=i+1;j<=n;++j) {
			int del=(a[j].fi-1)-l[i][j-1].se;
			del=max(0,del);
			dp[i][j]=dp[i][j-1]+del;
			l[i][j]=l[i][j-1];
			l[i][j].se=max(l[i][j].se,a[j].se);
			if(dp[i][j]<=m) {
				ans=max(ans,l[i][j].se+1-l[i][j].fi+max(0,m-dp[i][j]));
			}
		}
	}
	Pn(ans);
}

