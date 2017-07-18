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
unordered_map<int,int> m;
int T;
int n;
ll ans=0;
const int mod=(int)1e9+9;
int main() {
	R(T);
	while(T--) {
		ans=0;
		m.clear();
		R(n);
		for(int i=1;i<=n;++i) {
			ll ca=0;
			int p,d; R(p);R(d);
			m[p]+=d;
			ca=1;
			int rp=p;
			while(abs(m[rp+1]-m[rp])>1) {
				if(m[rp+1]>m[rp]) {
					ca+=m[rp+1]-(m[rp]+1);
					m[rp+1]=m[rp]+1;
					rp++;
				} else {
					ca+=(m[rp]-1)-m[rp+1];
					m[rp+1]=m[rp]-1;
					rp++;
				}
			}
			int lp=p;
			while(abs(m[lp-1]-m[lp])>1) {
				if(m[lp-1]>m[lp]) {
					ca+=m[lp-1]-(m[lp]+1);
					m[lp-1]=m[lp]+1;
					lp--;
				} else {
					ca+=(m[lp]-1)-m[lp-1];
					m[lp-1]=m[lp]-1;
					lp--;
				}
			}
			ans+=ca*i;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
}

