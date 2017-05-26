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
void RP(pii &x) {
	R(x.fi); R(x.se);
}
int T;
pii a[5];
int v[3];
bool inLine(int x,int l,int r) {
	if(l>r) swap(l,r);
	return (x<=r)&&(x>=l);
}
int main() {
	R(T);
	while(T--) {
		v[1]=v[2]=0;
		for(int i=1;i<=4;++i) {
			RP(a[i]);
		}
		for(int i=1;i<=2;++i) {
			for(int j=3;j<=4;++j) {
				if(a[i]==a[j]) {
					puts("yes");
					goto NEX;
				}
			}
		}
		if(a[1].fi==a[2].fi) v[1]=1;
		else if(a[1].se==a[2].se) v[1]=2;
		if(a[3].fi==a[4].fi) v[2]=1;
		else if(a[3].se==a[4].se) v[2]=2;
		if(a[1]==a[2]) {
			if((v[2]==1)&&(a[1].fi==a[3].fi)&&inLine(a[1].se,a[3].se,a[4].se)) {
				puts("yes");
				goto NEX;
			} else if((v[2]==2)&&(a[1].se==a[3].se)&&inLine(a[1].fi,a[3].fi,a[4].fi)) {
				puts("yes");
				goto NEX;
			}
		}
		if(a[3]==a[4]) {
			if((v[1]==1)&&(a[1].fi==a[3].fi)&&inLine(a[3].se,a[1].se,a[2].se)) {
				puts("yes");
				goto NEX;
			} else if((v[1]==2)&&(a[1].se==a[3].se)&&inLine(a[3].fi,a[1].fi,a[2].fi)) {
				puts("yes");
				goto NEX;
			}
		}
		if(v[1]!=v[2]) {
			puts("no");
			goto NEX;
		}
		if((v[1]==1)&&(a[1].fi==a[3].fi)) {
			if(inLine(a[1].se,a[3].se,a[4].se)||inLine(a[2].se,a[3].se,a[4].se)||inLine(a[3].se,a[1].se,a[2].se)||inLine(a[4].se,a[1].se,a[2].se)) {
				puts("yes");
				goto NEX;
			}

		} else  if((v[1]==2)&&(a[1].se==a[3].se)) {
			if(inLine(a[1].fi,a[3].fi,a[4].fi)||inLine(a[2].fi,a[3].fi,a[4].fi)||inLine(a[3].fi,a[1].fi,a[2].fi)||inLine(a[4].fi,a[1].fi,a[2].fi)) {
				puts("yes");
				goto NEX;
			}
		}
		puts("no");

NEX:
		continue;
	}
}

