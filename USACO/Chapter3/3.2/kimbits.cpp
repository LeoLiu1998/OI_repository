/*
PROB: kimbits
LANG: C++14
USER: yeguang2
This sourcecode is under GPLv3
yeguanghao
*/
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
#define PROB "kimbits"
inline void R(unsigned int &x) {
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

int dp[32][40];//for a string length i with no more than j 1
unsigned  int N,L,I;
int main() {
	Redirect();
	R(N); R(L); R(I);
	dp[0][0]=1;
	for(int i=0;i<=N;++i) {
		dp[i][0]=dp[0][i]=1;
	}
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	for(int i=N-1;i>=0;--i) {
		if(I>dp[i][L]) {
			putchar('1');
			I-=dp[i][L];
			L--;
		} else {
			putchar('0');
		}
	}
	puts("");
}
