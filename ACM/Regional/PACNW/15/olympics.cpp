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
double dp[10005000];

//dp[i]= dp[i-fail] + dp[i-succ];
int E,fail,succ;
int main() {
	R(E); R(fail); R(succ);
	dp[0]=1;
	int mi=min(fail,succ);
	for(int i=1;i<mi;++i) {
		dp[i]=1;
	}
	for(int i=mi;i<=E;++i) {
		double l=i-fail;
		double r=i-succ;
		l= l > 0 ? dp[(int)l] : 0;
		r= r > 0 ? dp[(int)r] : 0;
		dp[i]=l+r + 1;
		if(200/dp[i]<1e-7) {
		    dp[E]=1e20;
		    break;
		}
	}
	double ans=225/(dp[E]+1);

	ans=min(ans,(double)(200/(dp[E])));
	cerr<<dp[E]<<endl;
	printf("%.6f\n",ans);
}


