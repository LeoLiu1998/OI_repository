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
int a[200005];
int d[50005];
int pre[50050];
int n;
long double cnt=0;
long double all=0;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i==j) continue;
			d[abs(a[i]-a[j])]++;
		}
	}
	pre[0]=d[0];
	for(int i=1;i<=50000;++i) {
		pre[i]=pre[i-1]+d[i];	
	}
	for(int i=0;i<=5000;++i) {
		for(int j=0;j<=5000;++j) {
			cnt+=(long double)d[i]*d[j]*(pre[5000]-pre[i+j]);
			all+=(long double)d[i]*d[j]*pre[5000];
		}
	}
	printf("%.10lf\n",(double)(cnt/all));
}

