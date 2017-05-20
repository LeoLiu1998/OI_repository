//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>
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
//typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;
const int maxn=32800;
ll dp[maxn];
ll w[maxn];
ll pre[maxn];
ll suf[maxn];
int main() {
	int n; R(n);
	for(int i=1;i<=n;++i) {
		register int k,t;
		R(k); R(t);
		w[k]+=t;
	}
	pre[0]=w[0];
	for(int i=1;i<maxn;++i) {
		pre[i]=pre[i-1]+w[i];
		dp[i]=(ll)INT_MAX*1000;
	}
	suf[32767]=w[32767];
	for(int i=32766;i>=0;--i) {
		suf[i]=suf[i+1]+w[i];
	}
	ll tot=0;
	for(int i=1;i<=32767;++i) {
		tot+=w[i]*i;
	}
	dp[0]=tot;
	int mp=0;
	for(int i=1;i<=32770;i++) {
		dp[i]=dp[i-1]+pre[i-1]-suf[i];
		mp = dp[mp] > dp[i] ? i : mp;
	}
	cout<<mp<<endl<<dp[mp]<<endl;
}

