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
#define dp f
ll dp[2][55][55][55][55];
int a[55];
int n;
#define cur c
const int mod=(int)1e9+7;
int main() {
	R(n);
	for(int i=1;i<=n;++i) R(a[i]);
	int c=1,nex=0;
	dp[1][a[1]==2][a[1]==3][a[2]==2][a[2]==3]=1;
	for(int i=2;i<n;++i) {
		memset(dp[nex],0,sizeof dp[nex]);
		for(int p1=0;p1<=n;++p1) {
			for(int p2=0;p1+p2<=n;++p2) {
				for(int c1=0;p1+p2+c1<=n;++c1) {
					for(int c2=0;p1+p2+c1+c2<=n;++c2) {
						ll v=dp[cur][p1][p2][c1][c2];
						// new level
						if(p1+p2==0) {
							dp[cur][c1][c2][0][0]+=v;
							dp[cur][c1][c2][0][0]%=mod;
							continue;
						}
						// stay on 
						for(int lc=1;lc<=2;++lc) {// we solve a 1plug or 2plug ? 
							int cnt;
							if(lc==1) {
								cnt=p1;
								if(p1<=0) {
									continue;
								}
								p1--;
							} else {
								cnt=p2;
								if(p2<=0) continue;
								else {
									++p1;
									p2--;
								}
							}
							// let's dicuss type of new vertex
							if(a[i+1]==2) {
								f[nex][p1][p2][c1+1][c2]+=v*cnt;
								f[nex][p1][p2][c1+1][c2]%=mod;
								if(c1>=1) {
									f[nex][p1][p2][c1-1][c2]+=v*cnt*c1;
									f[nex][p1][p2][c1-1][c2]%=mod;
								}
								if(c2>=1) {
									f[nex][p1][p2][c1+1][c2-1]+=v*cnt*c2;
									f[nex][p1][p2][c1+1][c2-1]%=mod;
								}
							} else {
								f[nex][p1][p2][c1][c2+1]+=v*cnt;
								f[nex][p1][p2][c1][c2+1]%=mod;
								//1 plug*1
								if(c1>=1) {
									f[nex][p1][p2][c1][c2]+=v*cnt*c1;
									f[nex][p1][p2][c1][c2]%=mod;
								}
								// 1 plug2
								if(c2>=1) {
									f[nex][p1][p2][c1+2][c2-1]+=v*cnt*c2;
									f[nex][p1][p2][c1+2][c2-1]%=mod;
								}
								//2 plug1
								if(c1>=2) {
									f[nex][p1][p2][c1-2][c2]+=v*cnt*(c1)*(c1-1)/2;
									f[nex][p1][p2][c1-2][c2]%=mod;
								}
								//1 plug1 1plug2
								if(c1>=1&&c2&&1) {
									f[nex][p1][p2][c1][c2-1]+=v*cnt*(c1)*c2;
									f[nex][p1][p2][c1][c2-1]%=mod;
								}
								//2 plug2
								if(c2>=2) {
									f[nex][p1][p2][c1+2][c2-2]+=v*cnt*c2*(c2-1)/2;
									f[nex][p1][p2][c1+2][c2-2]%=mod;
								}
							}
							if(lc==1) p1++;
							else {
								p2++;p1--;
							}
							continue;
						}
					}

				}
			}
		}
		c^=1;
		nex^=1;
	}
	std::cout<<dp[cur][0][0][0][0] <<endl;
}

