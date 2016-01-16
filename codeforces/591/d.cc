//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
const long double eps=1e-14;
long double lo=0,hi=1e8,mid; 
pii s,t;
pii w1,w2;
int vmax,tim;
pii getp() {
	int a,b; R(a); R(b);
	return mp(a,b);
}
typedef long double ld;
typedef pair<ld,ld> pld;
int sgn(long double k) {
	if(fabsl(k)<eps) return 0;
	return k>0? 1:-1;
}

bool check(long double use) {
	ld x,y;	
	if(sgn(use-tim)>0) {
		x=(ld)tim*w1.fi+(use-tim)*w2.fi;
		y=(ld)tim*w1.se+(use-tim)*w2.se;
	} else {
		x=use*w1.fi;
		y=use*w1.se;
	}
	ld l=hypotl(t.fi-x,t.se-y);
	return sgn((l/vmax)-use)<1;
}
int main() {
	s=getp(); t=getp();
	t.fi-=s.fi;
	t.se-=s.se;
	R(vmax); R(tim); w1=getp(); w2=getp();
	while(hi-lo>eps) {
		mid=(lo+hi)/2.0;
		if(check(mid)) {
			hi=mid;
		} else {
			lo=mid;
		}
	}
//	cout<<lo<<endl;
	cout<<std::setprecision(18)<<lo<<endl;
}

