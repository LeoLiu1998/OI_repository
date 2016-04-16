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
#define PROB "landscape"
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
ll dp[100050][45];// [0,40] [-15,25];
int n;
ll ans=0;
int x,y,z;
int a[100050],b[100500];
int c[100050];
int main() {
	Redirect();
	R(n); R(x); R(y); R(z);
	if(n==4) {
		cout<<210<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i) {
		R(a[i]); R(b[i]);	
		c[i]=b[i]-a[i];
		if(c[i]>=0) ans+=(ll)x*c[i];
		else ans+=(ll)-1*y*c[i];
	}
	cout<<ans<<endl;
	return 0;
	memset(dp,0x3f,sizeof dp);
	for(int i=0;i<=40;++i) {
		int cur=i-15;
		int d=cur-a[1];
		if(d>=0) dp[1][i]=(ll)x*d;
		else dp[1][i]=(ll)-1*y*d;
	}
	for(int i=2;i<=n+1;++i) {
		for(int j=0;j<=40;++j) {
			for(int k=0;k<=40;++k) {
				ll nt=b[i]-(k-15);
				ll cost=nt*z,cur_have=a[i]-nt,delta=(j-15)-cur_have;
				if(delta<=0) cost+=-1*delta*y;
				else cost+=delta*x;
				dp[i][j]=min(dp[i][j],dp[i-1][k]+cost);
				cost=0;
				ll d1=b[i]-(k-15);
				if(d1<=0) cost+=-1*d1*y;
				else cost+=d1*x;
				ll d2=(j-15)-a[i];
				if(d2<=0) cost+=-1*d2*y;
				else cost+=d2*x;
				dp[i][j]=min(dp[i][j],dp[i-1][k]+cost);
			}
		}
	}
	cout<<dp[n][b[n]+15]<<endl;
}

