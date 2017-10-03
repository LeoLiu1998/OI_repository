 //This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%lld\n",x)
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int T;
int n,s,t;
string str[50];
pair<double,double> ind[100];
int main() {
	R(T);
	rep(k,1,T,1) {
		R(n);
		R(s); R(t);
		int m=0;
		rep(i,1,n,1) {
			cin>>str[i];
			cin>>ind[i].fi>>ind[i].se;
			if(fabs(ind[i].se-100)<=1e-3) {
				m=i;
			}
		}
		double mp=1.0*t/s;
		printf("Recipe # %d\n",k);
		rep(i,1,n,1) {
			cout<<str[i]<<" ";
			printf("%.1f\n",1.0*ind[m].fi*ind[i].se/100*mp);
		}
		puts("----------------------------------------");
	}
}
