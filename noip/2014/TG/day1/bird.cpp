//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10 +  ch- '0'; ch=getchar();}
	x*=f;
}
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define PROB "bird"
const int maxn=10000;
const int maxm=1000;
int dp[maxn+5][maxm+5]; //to arrive (n,m) at least need dp[n,m] touches 
int tube[maxn+5][2];
int del[maxn+5][2];
bool is_tube[maxn+5];
const int INF=30000000;
int n,m,k;
void DP();
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
int main() {
	Redirect();
	R(n); R(m); R(k);
	for(int i=0;i<n;++i) {
		R(del[i][0]); R(del[i][1]);
		tube[i][0]=0; tube[i][1]=m;
	}
	for(int i=1,p,l,r;i<=k;++i) {
		R(p); R(l); R(r);
		is_tube[p]=1; tube[p][0]=l; tube[p][1]=r;
	}
	memset(dp,0x3f,sizeof(dp));
	if(is_tube[0]) {
		for(int i=tube[0][0]+1;i<tube[0][1];++i) {
			dp[0][i]=0;
		}
	} else {
		for(int i=1;i<=m;++i) {
			dp[0][i]=0;
		}
	}
	DP();
	int OK=0;
	int ans=INF*2;
	for(int i=1;i<=m;++i) {
		if(dp[n][i]<INF) OK=1;
		ans=min(ans,dp[n][i]);
	}
#ifdef DEBUG
	for(int j=m;j>=0;--j) {
	for(int i=0;i<=n;++i) {
		
			cout<<setw(15)<<dp[i][j];
		}
		puts("");
	}
#endif
	Pn(OK);
	if(OK==1) {
		Pn(ans);
	} else {
		bool flag=1;
		int cnt=0;
		while(flag) {
			flag=0;
			for(int i=1;i<=m;++i) {
				if(dp[cnt][i]<INF) {
					flag=1;
					cnt++;
					continue;
				}
			}
		}
		int tn=0;
		for(int i=0;i<cnt;++i) {
			tn+=is_tube[i];
		}
		Pn(tn);
	}
}


void DP() {
	for(int i=1;i<=n;++i) {
	/*	int mt=(tube[i][1]+1-tube[i-1][0])/del[i-1][0] + 1;
		for(int s=1;s<=mt;s++) {
			for(int j=tube[i-1][0]+1;j<=max(((is_tube[i]? tube[i][1]-1:m)-s*del[i-1][0]),tube[i-1][1]+del[i-1][0]);j++) 
				dp[i][min(j+s*del[i-1][0],m)]=min(dp[i][min(j+s*del[i-1][0],m)],dp[i-1][j]+s);
		}*/
		for (int j = 1; j <= m; ++j) { 
			if(j >= del[i-1][0]) {  
                dp[i][j] = min(dp[i][j], dp[i-1][j-del[i-1][0]] + 1);  
                dp[i][j] = min(dp[i][j], dp[i][j-del[i-1][0]] + 1);  
            }
			if(j == m) {  
                for(int k=j-del[i-1][0];k<=m;k++) {  
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);  
                    dp[i][j] = min(dp[i][j], dp[i][k] + 1);  
                }  
            } 
		}
		for(int j=del[i-1][1]+1;j<=m;++j) {
			dp[i][j-del[i-1][1]]=min(dp[i][j-del[i-1][1]],dp[i-1][j]);
		}
		if(is_tube[i]) {
			for(int j=1;j<=tube[i][0];++j) dp[i][j]=1061109567;
			for(int j=tube[i][1];j<=m;++j) dp[i][j]=1061109567;
		}
	}
}
