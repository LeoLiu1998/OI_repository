//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
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
int a[200500];
int n,k;
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) R(a[i]);
	sort(a+1,a+n+1);
	int ans=a[k];
	if(ans<=0||ans>1e9) {
		Pn(-1);
		return 0;
	}
	int p=upper_bound(a+1,a+n+1,ans)-a;
	cerr<<ans<<" "<<p<<endl;
	if(p==k+1) Pn(ans);
	else Pn(-1);
}


