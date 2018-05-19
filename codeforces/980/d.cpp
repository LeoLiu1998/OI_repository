//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I64d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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

inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}


void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int a[5050];
int l[5050];
int r[5050];
int ans[5050];
int n;
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
bool is_sqr(ll x, ll y) {
	if(sgn(x)!=sgn(y)&&sgn(x)&&sgn(y)) return 0;
	int rt=sqrt((ll)x*y)+0.5;
	return (ll)rt*rt==(ll)x*y;
}

int main() {
	R(n);
	rep(i,1,n,1) {
		l[i] = -1;
		R(a[i]);
	}
	for(int i=1;i<=n;++i) {
		for(int j=i-1;j;--j) {
			if(a[j]==0) continue;
			if(is_sqr(a[i],a[j])) {
				l[i]=j;
				break;
			}
		}
		// for(int j=i+1;j<=n;++j) { 	
		// 	if(is_sqr(a[i],a[j])) {
		// 		l[j] = max(l[j],i);
		// 	}
		// }
	}
	for(int i=1;i<=n;++i) {
		int cur=0;
		int fz = 0; // first nonzero term
		bool all_zero = true;
		for(int j=i;j<=n;++j) {
			all_zero &= (a[j]==0);
			if(all_zero) cur=1;
			else {
				if(!fz) { 
					fz=j;
					cur = 1;
				} else {
					if(l[j]<fz) cur++;
				}
			}
			ans[cur]++;
		}
		// for(int j=i;j<=n;++j) {
		// 	if((!fz)&&a[j]) fz=j;
		// 	if(l[j]<(fz? fz:i)) {
		// 		if(j==fz&&fz!=i) cur--;
		// 		cur++;
		// 	}
		// 	ans[cur]++;
		// }
		
	}

	for(int i=1;i<=n;++i) {
		Ps(ans[i]);
	}
	puts("");

}


