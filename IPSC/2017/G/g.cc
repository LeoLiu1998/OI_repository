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
const int maxn=3005000;
int p[maxn];
int n,q;
int mod=(int)1e9+9;
ll ans=0;
int main() {
	R(n); R(q);
	memset(p,-1,sizeof p);
	for(int i=1;i<=q;++i) {
		if(q%10000==0) {
			cerr<<q/10000<<endl;
		}
		register int cmd,x,y;
		R(cmd); R(x); R(y);
		if(cmd==1) {
			if(!y) y=-1;
			p[x]=y;
		} else {
			int to=p[x];
			while(to!=-1) {
				if(to==y) {
					ans<<=1;
					ans+=1;
					ans%=mod;
					goto NEX;
				}
				to=p[to];
			}
			ans<<=1;
			ans%=mod;
		}
NEX:
		continue;
	}
	cout<<ans<<endl;
}

