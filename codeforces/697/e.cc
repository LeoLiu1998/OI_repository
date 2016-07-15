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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
struct Mat{
	ll data[2][2];
	Mat(){
		memset(data,0,sizeof data);
	}
	void Init() {
		for(int i=0;i<2;++i) data[i][i]=1;
	}
	Mat operator * (const Mat &b) const {
		Mat ret;
		for(int i=0;i<2;++i) {
			for(int j=0;j<2;++j) {
				ret.data[i][j]=0;
				for(int k=0;k<2;++k) {
					ret.data[i][j]+=(data[i][k]*b.data[k][j]);
					ret.data[i][j]=(ret.data[i][j]+mod)%mod;

				}
			}
		}
		return ret;
	}
};
Mat qpow(Mat a, ll t) {
	Mat ret;
	ret.Init();
	while(t) {
		if(t&1) {
			ret=ret*a;
		}
		t>>=1;
		a=a*a;
	}
	return ret;
}
pll Undo(pll a) {
	return mp(((a.se-2*a.fi+mod*10)*500000004)%mod,(a.se*500000004)%mod);
}
int main() {
	Mat x,s,t;
	x.data[0][0]=-1;x.data[0][1]=0; 
	x.data[1][1]=2;	x.data[1][0]=1;
	s.data[0][0]=0; s.data[0][1]=1;
	s.data[1][0]=0; s.data[1][1]=0;
	t=x;
	int n; R(n);
	for(int i=1;i<=n;++i) {
		ll k; R(k); 
		t=qpow(t,k);
	}
	s=s*t;
	pll ans=mp(s.data[0][0],s.data[0][1]);
	ans=Undo(ans);
	cout<<ans.fi<<"/"<<ans.se<<endl;
}

