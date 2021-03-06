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

int val[305][305];
pii pos[305];
int v[305];
int n,m;
int ans=0;
int main() {
	R(n); R(m);
	rep(i,1,m,1) {
		R(pos[i].fi); R(pos[i].se);
		R(v[i]);
	}
	rep(k,1,m,1) {
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				int dis=max(abs(i-pos[k].fi),abs(j-pos[k].se));
				if(dis<v[k]) {
					val[i][j]+= v[k]-dis;
					ans=max(ans,val[i][j]);
				}
			}
		}
	}
	Pn(ans);
}

