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
ll n,k;
ll cnt;
ll last;
ll c;
int main() {
	R(n); R(k);
	for(ll i=1;i*i<=n;++i) {
		if(n%i==0) {
			cnt+=2;
			last=i;
		}
	}
	if(last*last==n) cnt--;
	for(ll i=1;i*i<=n;++i) {
		if(n%i==0) {
			c++;
			if(k==c) {
				cout<<i<<endl; return 0;
			} else if(k==(cnt+1-c)) {
				cout<<n/i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
}


