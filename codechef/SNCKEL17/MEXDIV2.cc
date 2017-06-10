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
ll mod=1e9+7;
const int maxn=500000;
int cnt[510000];
ll pox[510000];
int pre[maxn+1000];
int n,k;
ll ans=0;
int main() {
	R(n); R(k);
	pox[0]=1;
	for(int i=1;i<=n+5;++i) {
		pox[i]=pox[i-1]<<1;
		pox[i]%=mod;
	}
	for(int i=1;i<=n;++i) {
		int tmp; R(tmp);
		if(tmp>5e5) {
			cnt[maxn+5]++;
		}
	}
	for(int i=1;i<=n+10;++i) {
		pre[i]=cnt[i]+pre[i-1];	
	}
	int con=0; while(cnt[con+1]>0) con++;
	if(k>con) {
		cout<<pox[n]<<endl;
		return 0;
	}
	for(int i=k;i;--i) {
		
	}
}

