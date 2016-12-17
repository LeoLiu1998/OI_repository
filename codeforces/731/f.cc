//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define count cnt
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
int n;
const int maxn=200500;
int a[maxn];
int count[maxn];
int pre[maxn];
bool vis[maxn];
ll ans=0;
ll Calc(int x) {
	ll ret=0;
	for(int i=x;i<=200000;i+=x) {
		ret+=((ll)pre[i+x-1] - pre[i-1])*i;
	}
	return ret;
}	
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		count[a[i]]++;
	}
	for(int i=1;i<=200000;++i) {
		pre[i]=pre[i-1]+count[i];
	}
	for(int i=1;i<=n;++i) {
		if(vis[a[i]]) continue;
		vis[a[i]]=1;
		ans=max(ans,Calc(a[i]));
	}
	cout<<ans<<endl;
}

