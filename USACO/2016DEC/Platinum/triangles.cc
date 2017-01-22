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
#define PROB "triangles"
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
typedef pii Point;
Point p[350];
int cnt[350][350];
int n;
inline bool Check(int l, int r, int k) {
	Point b(p[r].fi-p[l].fi,p[r].se-p[l].se),c(p[k].fi-p[l].fi,p[k].se-p[l].se);
	return ((ll)b.fi*c.se-(ll)b.se*c.fi)>0;
}
void Pre() {
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			for(int k=i+1;k<=n;++k) {
				if(p[k].fi<p[j].fi) cnt[i][j]+=(Check(i,j,k));
			}
		}
	}
}
int ans[350];
int main() {
	Redirect();
	R(n); 
	for(int i=1;i<=n;++i) {
		R(p[i].fi); R(p[i].se);
	}
	sort(p+1,p+n+1);
	Pre();
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			for(int k=j+1;k<=n;++k) {
				int cur=cnt[i][k]-cnt[i][j]-cnt[j][k];
				if(Check(i,k,j)) {
					cur--;
				}
				cur=abs(cur);
				ans[cur]++;
			}
		}
	}
	for(int i=1;i<=n-2;++i) {
		Pn(ans[i-1]);
	}
}

