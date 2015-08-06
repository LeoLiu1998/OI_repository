//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
//#define Pn(x) printf("%lld\n",x)
//#define Ps(x) printf("%lld ",x)
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=210000;
typedef long long ll;
map<ll,ll> l;
map<ll,ll> r;
ll a[maxn];
ll k;
ll n;
long long ans=0;
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		r[a[i]]++;
	}
	for(ll i=1;i<n;++i) {
		if(a[i]%k!=0) {
			l[a[i]]++;
			r[a[i]]--;
			continue;
		}
		r[a[i]]--;
		ll fi=a[i]/k;
		ll th=a[i]*k;
		ans+=(long long)l[fi]*(long long)r[th];
		l[a[i]]++;
	}
	cout<<ans<<endl;
}
