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
int T;
int n;
int q,k;
int upper;
int a[100050];
ll pre[100050];
bool Check(int x) {
	if(!x) return 0;
	ll curLen=pre[upper-1]-pre[x-1];
	ll delta=((ll)upper-x)*k-curLen;
	return delta<=(x-1);
}
int main() {
	R(T);
	while(T--) {
		R(n);
		R(q); 
		for(int i=1;i<=n;++i) {
			R(a[i]);
		}
		sort(a+1,a+n+1);
		a[n+1]=INT_MAX;
		for(int i=1;i<=n+1;++i)
			pre[i]=a[i]+pre[i-1];
		while(q--) {
			R(k);
			int l=0,r=n+1,mid;
			while(r-l>1) {
				mid=(r+l)>>1;
				if(a[mid]>=k) r=mid;
				else l=mid;
			}
			upper=r;
			if(l==0) {
				Pn(n);
				continue;
			}
			l=0; r=upper;
			while(r-l>1) {
				mid=(r+l)>>1;
				if(Check(mid)) {
					r=mid;
				} else {
					l=mid;
				}
			}
			Pn(n-r+1);
		}
	}
}

