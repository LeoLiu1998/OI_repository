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
int a[300050];
ll pre[300500];
int po[300050];
int mod=1e9+7;
int n;
ll ans=0;
//1 (1,2) (2,3) (3,4) (n-1,n) // n-1
//2 (1,3) (2,4) (n-2,n)// n+n-1 - 
int main() {
	R(n);
	po[0]=1;
	for(int i=1;i<=n;++i) {
		R(a[i]);
		po[i]=(po[i-1]<<1)%mod;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		pre[i]=pre[i-1]+a[i];
		pre[i]%=mod;
	}
	for(int i=1;i<=n;++i) {
		ll cur=po[i-1]*((pre[n]-pre[n-i])-pre[i]);
		cur=(cur+mod)%mod;
		ans=(ans+cur+mod)%mod;
	}
	cout<<ans<<endl;
}

