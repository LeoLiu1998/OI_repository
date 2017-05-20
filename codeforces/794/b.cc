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
int n,h;
long double ans[100010];
long double pre[100010];
int main() {
	R(n); R(h);
	ans[1]=1.0*h/sqrt(n);
	pre[1]=ans[1];
	long double area=pre[1]*ans[1]/2;
	for(int i=2;i<n;++i) {
		long double l=0,r=h;
		while((r-l)>1e-10) {
			long double mid=(l+r)/2;
			long double ca=(mid)*(pre[i-1]*2+mid)/2;
			if(ca>area) {
				r=mid;
			}  else {
				l=mid;
			}
		}
		ans[i]=l;
		pre[i]=pre[i-1]+ans[i];
	}
	for(int i=1;i<n-1;++i) {
		cout << setprecision (12) << pre[i]<<" ";//printf("%.12Lf ",pre[i]);
	}
	cout << setprecision (12)<<pre[n-1]<<endl;//printf("%.12LF\n",pre[n-1]);
}

