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
#define PROB "angry"
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
int n,k;
int a[50005];
bool check(int len) {
	int cur=a[1]+2*len;
	int ans=1;
	for(int i=1;i<=n;++i) {
		if(a[i]>cur) {
			ans++;
			cur=a[i]+2*len;
		}
	}
	return ans<=k;
}
int main() {
	Redirect();
	R(n); R(k);
	for(int i=1;i<=n;++i) R(a[i]);
	sort(a+1,a+n+1);
	int l=0,r=INT_MAX;
	while(l<r-1) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid;
		}
	}
	Pn(l+1);
}

