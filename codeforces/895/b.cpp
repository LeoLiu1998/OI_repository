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
const int mod=(int)1e9+7;
struct Mat {
	const static int N=15;
	ll d[17][17];
	Mat(){
		memset(d,0,sizeof d);
	}
	Mat operator * (const Mat &a) const  {
		Mat ret;
		for(int i=0;i<=N;++i)  {
			for(int j=0;j<=N;++j) {
				ret.d[i][j]=0;
				for(int k=0;k<=N;++k) {
					ret.d[i][j]+=d[i][k]*a.d[k][j];
					ret.d[i][j]%=mod;
				}
			}
		}
		return ret;
	}
};
Mat qpow(Mat x, ll p) {
	Mat ret;
	for(int i=0;i<=ret.N;++i) ret.d[i][i]=1;
	while(p) {
		if(p&1) {
			ret=ret*x;
		}
		x=x*x;
		p>>=1;
	}
	return ret;
}
int n,k,x;
map<int,int> m;
int a[100050];
int pre[100050];
int main() {
	R(n); R(x); R(k);
	rep(i,1,n,1) {
		R(a[i]);
		m[a[i]]++;
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;++i) {
		pre[i]=pre[i-1]+m[a[i]];
	}
	ll ans=0;
	int l=1,r=1;
	for(int i=1;i<=n;++i) {
		l=max(l,i);
		r=max(r,i);
		while(r+1<=n&&((a[r+1]/x)-((a[i]-1)/x))<=k) r++;
		while(l+1<=n&& ((a[l]/x)-(a[i]-1)/x)<k) l++;
		if(l<=r&&(a[r]/x)-((a[i]-1)/x)==k&&(a[l]/x)-(a[i]-1)/x==k)
			ans+=(ll)m[a[i]]*(pre[r]-pre[l-1]);

	}
	Pln(ans);
}


