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
double p[30],s[1<<22],ans[30];
int n,k;
const double eps=1e-6;
int count(int x) {
	int ret=0;
	while(x) {
		if(x&1) ++ret;
		x>>=1;
	}
	return ret;
}
int main() {
	R(n); R(k);
	int cnt=0;
	rep(i,0,n-1,1) {
		cin>>p[i];
		if(p[i]>eps) cnt++;	
	}
	k=min(k,cnt);
	s[0]=1;
	for(int i=0;i<(1<<n);++i) {
		double all=1;
		for(int j=0;j<n;++j)
			if(i&(1<<j)) {
				all-=p[j];
				if(count(i)==k) ans[j]+=s[i];
			}
		for(int j=0;j<n;++j) {
			if(!(i&(1<<j)))
				s[i|(1<<j)]+=s[i]*p[j]/all;
		}
	}
	for(int i=0;i<=n-1;++i) {
		printf("%0.6f ",ans[i]);
	}
	puts("");
}

