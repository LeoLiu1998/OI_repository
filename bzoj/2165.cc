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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
} 
const int maxn=105;
ll dp[80][maxn][maxn];
ll cur[maxn][maxn],tmp[maxn][maxn];
ll n,m;
int p=1;
void prt(ll a[][maxn]) {
/*	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			printf("% 3lld ",a[i][j]<0?-1:a[i][j]);
		}
		puts("");
	}
*/}
void Floyd(){
	for(;(((ll)1)<<p)<=m;++p) {
		for(int k=1;k<=n;++k) {
			for(int i=1;i<=n;++i) {
				for(int j=1;j<=n;++j) {
					dp[p][i][j]=max(dp[p][i][j],dp[p-1][i][k]+dp[p-1][k][j]);
					if(i==1&&dp[p][i][j]>=m) return;
				}
			}
		}
	}
}
bool check(int pos) {
	memset(tmp,0xef,sizeof tmp);
	for(int k=1;k<=n;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				tmp[i][j]=max(tmp[i][j],cur[i][k]+dp[pos][k][j]);
				if(i==1&&tmp[i][j]>=m) return 0; 
			}
		}
	}
	return 1;
}
int main() {
	int M; R(M);
	while(M--) {
		memset(dp,0xef,sizeof dp);
		memset(cur,0xef,sizeof cur);
		R(n); R(m);
		p=1;
		for(int i=1;i<=n;++i) {
			cur[i][i]=0;
			for(int j=1;j<=n;++j){
				R(dp[0][i][j]);
				if(!dp[0][i][j]) dp[0][i][j]=dp[75][0][0];
			}
		}
		Floyd();
		ll ans=0;
		for(int i=p-1;i>-1;--i) {
			if(check(i)) {
				for(int i=1;i<=n;++i) {
					for(int j=1;j<=n;++j) {
						cur[i][j]=tmp[i][j];
					}
				}
				ans+= (((ll)1)<<i);
			}
		}/*
		for(int i=0;i<=p;++i){
//			cout<<i<<endl;
			prt(dp[i]);
		}
		//puts("");	*/
		printf("%lld\n",ans+1);
	}
}

