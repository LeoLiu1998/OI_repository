#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%lld\n",x)
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dp[100050][105];
int T;
int n;
int b[100050];
int main() {
    R(T);
    while(T--) {
        memset(dp,0,sizeof dp);
        R(n);
        for(int i=1;i<=n;++i) {
                R(b[i]);
        }
        for(int i=2;i<=n;++i) {
                for(int k=1;k<=b[i];k+=(b[i]-1)) {
                        for(int j=1;j<=b[i-1];j+=(b[i-1]-1)) {
                                dp[i][k]=max(dp[i][k],dp[(i-1)][j] + abs(j-k));
                        }
                }
        }
        int ans=0;
        for(int i=1;i<=100;++i) {
                ans=max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
