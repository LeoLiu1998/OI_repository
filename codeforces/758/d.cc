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
inline void R(long long &x) {
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
ll base;
char s[105];
int n;
int bn=0;
ll dp[120];
ll toString(int l,int r) {
	ll ret=0;
	for(int i=l;i<=r;++i) {
		ret*=10;
		ret+=s[i]-'0';
	}
	return ret;
}
int main() {
	R(base); scanf("%s",s+1);
	n=strlen(s+1);
	//memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i) dp[i]=LLONG_MAX;
	ll temp=base;
	while(temp) {
		temp/=10;
		bn++;
	}
	dp[0]=0;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=bn;++j) {
			if(i-j<0) break;
			ll num=toString(i-j+1,i);
			if(num<base&&(s[i-j+1]!='0'||j==1)) {
				ll k=dp[i-j]*base+num;
				if(k<0) k=LLONG_MAX;
				dp[i]=min(k,dp[i]);
			}
		}
	}
	cout<<dp[n]<<endl;
}

