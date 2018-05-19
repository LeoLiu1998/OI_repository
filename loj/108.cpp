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
typedef complex<double> cp;
const int maxn=300000;
cp omega[maxn];
cp conj_omega[maxn];
//vector<cp> A,B;
int n,m;
int N=1;


void recursive_FFT(vector<cp> &a,int layer, cp* root) {
	if(a.size()==1)
		return ;
	int len = a.size()>>1;
	vector<cp> a0(len),a1(len); //a0.reserve(len); a1.reserve(len);
	for(int i=0;i<a.size();i+=2) {
		a0[i>>1]=(a[i]);
		a1[i>>1]=(a[i+1]);
	}
	recursive_FFT(a0,layer<<1,root);
	recursive_FFT(a1,layer<<1,root);
	for(int i=0;i<(a.size()>>1);++i) {
		a[i]=a0[i]+a1[i]*root[i*layer];
		a[i+len] = a0[i]-a1[i]*root[i*layer];
	}
	a1.clear();
	a0.clear();
}

void init_omega(int N) {
	double pi=acos(-1);
	for(int i=0;i<N;++i) {
		omega[i]=complex<double>(cos(2.0*pi*i/N),sin(2.0*pi*i/N));
		conj_omega[i]=conj(omega[i]);
	}
}

int main() {
	R(n); R(m);
	while(N<(n+m+1)) N<<=1;
	vector<cp> A(N),B(N);
	init_omega(N);
	for(int i=0;i<=n;++i) {
		int t; R(t);
		A[i]=(complex<double>((double)t,0));
	}
	recursive_FFT(A,1,omega);
	for(int i=0;i<=m;++i) {
		int t; R(t);
		B[i]=(complex<double>((double)t,0));
	}
	recursive_FFT(B,1,omega);
	for(int i=0;i<N;++i) {
		A[i]*=B[i];
	}
	recursive_FFT(A,1,conj_omega);
	for(int i=0;i<=n+m;++i) {
		cout<<llround(real(A[i])/N)<<" ";
	}
	cout<<endl;
	

}


