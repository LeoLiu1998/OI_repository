/*
PROB: inflate
ID: yeguang2
LANG: C++11
*/
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
#define PROB "inflate"
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
const int maxn=10050;
int w[maxn],v[maxn],dp[maxn];
int n,k;
int main() {
	Redirect();
	R(n); R(k);
	for(int i=1;i<=k;++i) {
		R(w[i]); R(v[i]);
	}
	for(int i=1;i<=k;++i) {
		for(int j=v[i];j<=n;++j) {
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	Pn(dp[n]);
}

