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
ll s,m,d;
ll dp[100050][105];
ll mod=1e9+9;
int main() {
	//R(s); R(m); R(d);
	cin>>s>>m>>d;
	for(int i=1;i<=m;++i) dp[i][i]=1;
	for(int i=2;i<=s;++i) {
		for(int j=1;j<=m&&j<=i;++j) {
			for(int k=1;k<=m;++k) {
				if(abs(k-j)>d) continue;
				dp[i][j]+=dp[i-j][k];
				dp[i][j]%=mod;
			}
		}
	}
	ll ans=0;
#ifdef YGHDEBUG
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=s;++j) {
			printf("%lld ",dp[j][i]);
		}
		puts("");
	}
#endif
	for(int i=1;i<=m;++i) {
		ans+=dp[s][i];
	}
	cout<<ans%mod<<endl;
}

