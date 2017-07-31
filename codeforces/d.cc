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
ll a[505]={0,1,9, 245, 7776, 254035, 8336079, 273725760, 8988999201};
int n;
const ll mod=(int)1e9+7;
int main() {
	R(n);
	//40*a(n-1) -248*a(n-2) +430*a(n-3) -248*a(n-4) +40*a(n-5) -a(n-6)
	for(int i=9;i<=n;++i) {
		ll cur=(40*a[i-1]%mod)-(248*a[i-2]%mod)+(430*a[i-3]%mod)-(248*a[i-4]%mod)+(40*a[i-5]%mod)-a[i-6];
		a[i]=(cur%mod+mod)%mod;
	}
	cout<<a[n]%mod<<endl;
}

