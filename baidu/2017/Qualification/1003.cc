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
ll dp[15][1050];
pii a[100050];
ll ski[1005];
int max1,max2;
int n,m;
int main() {
	while(~scanf("%d%d",&n,&m)) {
		ll ans=0;
		max1=max2=-1;
		memset(dp,0x3f,sizeof dp);
		memset(a,0,sizeof a);
		memset(ski,-1,sizeof ski);
		rep(i,1,n,1) {
			R(a[i].fi); R(a[i].se);
			max1=max(max1,a[i].fi);
		}
		rep(i,1,m,1) {
			register int k,p; R(k); R(p);
			if(ski[p]==-1) ski[p]=k;
			else ski[p]=min((ll)k,ski[p]);
			max2=max(p,max2);
		}
		rep(i,1,n,1) {
			if(a[i].se>max2) {
				puts("-1");
				goto END;
			}
		}
		rep(i,0,10,1) dp[i][0]=0;
		rep(k,0,10,1) {
			rep(i,1,max1,1) {
				rep(j,1,max2,1) {
					if(ski[j]==-1) continue;
					dp[k][i]=min(dp[k][i],dp[k][max(0,i+k-j)]+ski[j]);
				}
			}
		}
		for(int i=1;i<=n;++i) {
			ans+=dp[a[i].se][a[i].fi];
		}
		printf("%lld\n",ans);
END:
		continue;
	}
}

