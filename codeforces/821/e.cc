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
inline void R(long long &x) {
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
pll r[105];
int a[105];
int n;
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
ll k;
Mat cur,st;
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
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		R(r[i].fi); R(r[i].se);
		R(a[i]);
	}
	for(int i=0;i<=cur.N;++i) {
		cur.d[i][i]=1;
	}
	for(int i=1;i<=n;++i) {
		if(r[i].se>=k) {
			r[i].se=k;
		}
		ll step=r[i].se-r[i].fi;
		memset(st.d,0,sizeof st.d);
		for(int x=0;x<=a[i];++x) {
			for(int y=-1;y<=1;++y) {
				if(x+y<0) continue;
				if(x+y>a[i]) continue;
				st.d[x][x+y]++;
			}
		}
		Mat res=qpow(st,step);
		cur=cur*res;
		if(r[i].se>=k) {
			break;
		}
	}
	cout<<cur.d[0][0]<<endl;
}

