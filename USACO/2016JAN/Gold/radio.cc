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
#define PROB "radio"
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
ll dp[1005][1005];
pii FJ,be;
int fn,bn;
pii pf[1005];
pii pb[1005];
string fp,bp;
static inline 
pii Dir(char ch) {
	if(ch=='N') return pii(0,1);
	else if(ch=='S') return pii(0,-1);
	else if (ch=='W') return pii(-1,0);
	else if(ch=='E') return pii(1,0);
	assert(0);
}

static inline
pii mov(pii cur,char dir) {
	pii ret=Dir(dir);
	ret.fi+=cur.fi; ret.se+=cur.se;
	return ret;
}

static inline
ll Dist(pii a,pii b) {
	return (ll)(a.fi-b.fi)*(a.fi-b.fi)+(ll)(a.se-b.se)*(a.se-b.se);
}

static inline 
void DP() {
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=fn;++i) {
		dp[i][0]=dp[i-1][0]+Dist(pf[i],pb[0]);
	}
	for(int j=1;j<=bn;++j) {
		dp[0][j]=dp[0][j-1]+Dist(pf[0],pb[j]);
	}
	for(int i=1;i<=fn;++i) { // i FJ
		for(int j=1;j<=bn;++j) { // j Bessie
			dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+Dist(pf[i],pb[j]);
		}
	}	
}

static inline 
void PRE() {
	pf[0]=FJ;
	for(int i=1;i<=fn;++i) {
		pf[i]=mov(pf[i-1],fp[i-1]);
	}
	pb[0]=be;
	for(int i=1;i<=bn;++i) {
		pb[i]=mov(pb[i-1],bp[i-1]);
	}
}
int main() {
	Redirect();
	R(fn); R(bn);
	R(FJ.fi); R(FJ.se); 
	R(be.fi); R(be.se);
	cin>>fp>>bp;
	PRE();
	DP();
	cout<<dp[fn][bn]<<endl;
}

