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
const int maxn=2005;
int n,k,p;
int a[maxn],b[maxn];
ll l=-1,r=INT_MAX,mid;
bool check(ll x) {
	int cur=1;
	for(int i=1;i<=n;++i) {
		while((cur<=k)&&((abs(b[cur]-a[i])+abs(p-b[cur]))>x)) cur++;
		if(cur<=k) {
			cur++;
		} else {
			return 0;
		}
	}
	return 1;
}
int main() {
	R(n); R(k); R(p);
	rep(i,1,n,1) {
		R(a[i]);
	}
	rep(i,1,k,1) {
		R(b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	while(r-l>1) {
		mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else 
			l=mid;
	}
	cout<<r<<endl;
}

