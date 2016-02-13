/*
PROB: agrinet
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
#define PROB "agrinet"
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
const int maxn=105;
int a[maxn][maxn],dist[maxn];
bool linked[maxn];
int cost,cur=1,n;
void Solve() {
	int cur_min=INT_MAX,cho;
	for(int i=1;i<=n;++i) {
		if((!linked[i])&&dist[i]<cur_min) {
			cho=i; cur_min=dist[i];
		}
	}
	cost+=cur_min;
	linked[cho]=1; cur=cho;
	for(int i=1;i<=n;++i) {
		dist[i]=min(dist[i],a[cur][i]);
	}
}
int main() {
	Redirect();
	R(n);
	rep(i,1,n,1) {
		rep(j,1,n,1) {
			R(a[i][j]);
		}
	}
	linked[1]=1;
	for(int i=1;i<=n;++i) {
		dist[i]=a[1][i];	
	}
	for(int i=1;i<n;++i) {
		Solve();
	}
	Pn(cost);
}

