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
#define PROB "team"
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
const int maxn=1005;
int a[maxn],b[maxn];
ll dp[12][maxn][maxn];
ll pre[12][maxn][maxn];
const ll mod=1e9+9;
int n,m,k;
int main() {
	Redirect();
	R(n); R(m); R(k);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=m;++j) {
		R(b[j]);
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=n;++i ) {
		for(int j=1;j<=m;++j) {
			dp[1][i][j]= (a[i]>b[j]); 
			pre[1][i][j]=pre[1][i-1][j] + pre[1][i][j-1] - pre[1][i-1][j-1] + dp[1][i][j];
			pre[1][i][j] %= mod;
		}
	}
	ll ans=0;
	for(int c=2;c<=k;++c) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				ll cnt=0; 
				if(a[i]>b[j]) cnt=pre[c-1][i-1][j-1];
				dp[c][i][j]=cnt%mod;
				pre[c][i][j]= pre[c][i-1][j]+ pre[c][i][j-1]-pre[c][i-1][j-1]+ dp[c][i][j];
				pre[c][i][j] %= mod;
			}
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			ans+= dp[k][i][j];
		}
		ans%=mod;
	}
	cout<<ans<<endl;
}

