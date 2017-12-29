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
double dp[2005][2005];// i a and j ab
int k,a,b;
int main() {
	R(k); R(a); R(b);
	dp[1][0]=1;
	double ans2=0;
	double pa=1.0*a/(a+b);
	double pb=1.0*b/(a+b);
	for(int i=1;i<=k;++i) {
		for(int j=0;j<=(k-1+i);++j) {
			if(i==1&&j==0) continue;
			dp[i][j]=dp[i-1][j]*pa;
			if(j-i>=0) {
				dp[i][j]+=dp[i][j-i]*pb;
			}
			if(j>=k) {
				ans2+=dp[i][j]*j;
			}
		}
	}
	double ans=pa/((1-pa)*(1-pa));
	double p=1;
	for(int i=1;i<=k;++i) {
		p*=pa;
		ans-=p*i;
	}
	ans*=pb/pa;
	cout<<ans+ans2<<endl;
}


