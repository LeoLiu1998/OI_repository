//This sourcecode is under GPLv3
//http://yegunanghao.xyz
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
#define rank rax
#define x first.first
#define y first.second
#define r second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> Cir;
typedef vector<int> node;
const int maxn=1005;
node s[1005];
Cir c[1005];
int rank[1005];
bool AinB(Cir a, Cir b) {
	ll k=1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y)-1ll*(b.r-a.r)*(b.r-a.r);
	if(k!=0) {
		return k<0;
	} else {
		return b.r>a.r;
	}
}
bool AinB(int u,int w) {
	return AinB(c[u],c[w]);
}
bool cmr(const Cir &a,const Cir &b) {
	return a.se>b.se;
}
void dfs(int k) {
	for(int i=0;i<s[k].size();++i) {
		rank[s[k][i]]=rank[k]+1;
	}
	for(int i=0;i<s[k].size();++i) {
		if(rank[s[k][i]]!=rank[k]+1) continue;
		for(int j=i+1;j<s[k].size();++j) {
			if((rank[s[k][j]]==rank[k]+1)&&AinB(s[k][j],s[k][i])) {
				s[s[k][i]].pb(s[k][j]);
			}
		}
		dfs(s[k][i]);
	}
}
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int xi,yi,ri;
		R(xi); R(yi); R(ri);
		c[i]=mp(mp(xi,yi),ri);
	}
	sort(c+1,c+n+1,cmr);
	for(int i=1;i<=n;++i) {
		if(!rank[i]) {
			rank[i]=1;
			for(int j=i+1;j<=n;++j) {
				if(i==j) continue;
				if(!rank[j]) {
					if(AinB(j,i)) {
						s[i].pb(j);
					}
				}
			}
			dfs(i);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i) {
		if((rank[i]<=2)||(rank[i]%2==0)) {
			ans+=(ll)c[i].r*c[i].r;
		} else {
			ans-=(ll)c[i].r*c[i].r;
		}
//		printf("%d %d %d %d\n",c[i].x,c[i].y,c[i].r,rank[i]);
	}
	printf("%.10f\n",3.1415926535*ans);
}

