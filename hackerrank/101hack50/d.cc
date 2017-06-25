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
bool vis[25][25];
double prob[25][25];
map<pii,pii> m;
char a[25][25];
int n,m,k;
pii s,t;
pii operator (const pii &a, int opt) {
	pii ret=a;
	if(opt==1) {
		a.fi++;
	} else if(opt==2) {
		a.se++;
	} else if(opt==3) {
		a.fi--;
	} else {
		a.se--;
	}
	return ret;
}
int main() {
	R(n); R(m); R(k);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			char ch=0; while(iscntrl(ch)) ch=getchar();
			a[i][j]=ch;
			if(a[i][j]=='A') {
				s=mp(i,j);
			} 
			if(a[i][j]=='%') {
				t=mp(i,j);
			}
		}
	}
}

