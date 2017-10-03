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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,t;
pair<double,double> sub[15];
double c[15];
int ans[20];
double blo=0.05;

double Calc(int x) {
	double ret=2*sub[x].fi*ans[x]*blo+sub[x].se;
	return ret;
}

int main() {
	R(n); R(t);
	rep(i,1,n,1) {
		scanf("%lf%lf%lf",&sub[i].fi,&sub[i].se,&c[i]);
	}
	int mi;
	for(int i=1;i*blo<=t;++i) {
		mi=1;
		rep(j,2,n,1)
			if(Calc(mi)<Calc(j)) 
				mi=j;
		ans[mi]++;
	}
	double tot=0;
	for(int i=1;i<=n;++i) {
		double tmp=ans[i]*blo;
		cerr<<tmp<<endl;
		tot += tmp*tmp*sub[i].fi+tmp*sub[i].se+c[i];
		cerr<<tot<<endl;
	}
	cout<<tot/n<<endl;
}
