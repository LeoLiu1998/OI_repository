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
int n;
int stn(string s) {
	int ret=0;
	for(auto i:s) {
		if(!isdigit(i)) continue;
		ret=ret*10+i-'0';
	}
	return ret;
}

pair<int,string> cups[50000];
int main() {
	R(n);
	rep(i,1,n,1) {
		string l,r; cin>>l>>r;
		int tmp=0;
		if(isdigit(l[0])) {
			tmp=stn(l)>>1;
			cups[i]=mp(tmp,r);
		} else {
			tmp=stn(r);
			cups[i]=mp(tmp,l);
		}
	}
	sort(cups+1,cups+n+1);
	rep(i,1,n,1) {
		cout<<cups[i].se<<endl;
	}

}

