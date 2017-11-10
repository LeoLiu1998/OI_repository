/**
 * PROB: spin
 * LANG: C++14
 * USER: yeguang2
 */
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
#define PROB "spin"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int v[7];
vector<pii> w[7];

void Run() {
	for(int i=1;i<=5;++i) {
		for(auto x:w[i]) {
			x.fi+=v[i];
			x.se+=v[i];
			x.fi%=360;
			x.se%=360;
		}
	}
}

pii operator & (pii a,pii b) {
	if(a.se<a.fi) a.se+=360;
	if(b.se<b.fi) b.se+=360;
	if((a.fi>b.se)||(b.fi>a.se)) return mp(-1,0);
	else {
		mp(max(a.fi,b.fi)%360,min(a.se,b.se)%360);
	}
}

bool Check() {
	for(int i=0;i<w[1].size();++i) {
		for(int j=0;j<w[2].size();++j) {
			pii t1=w[1][i]&w[2][j];
			if(t1.fi==-1) continue;
			for(int k=0;k<w[3].size();++k) {
				pii t2=t1&w[3][k];
				if(t2.fi==-1) continue;
				for(int l=0;l<w[4].size();++l) {
					pii t3=t2&w[4][l];
					if(t3.fi==-1) continue;
					for(int m=0;m<w[5].size();++m) {
						pii t4=t3&w[5][m];
						if(t4.fi==-1) continue;
						else return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	Redirect();
	for(int i=1;i<=5;++i) {
		R(v[i]);
		int t; R(t);
		for(int j=1;j<=t;++j) {
			pii k; R(k.fi); R(k.se);
			w[i].pb(k);
		}
	}
	if(Check()) {
		Pn(0);
		return 0;
	}
	for(int i=1;i<=360;++i) {
		Run();
		if(Check()) {
			Pn(i);
			return 0;
		}
#ifdef DEBUG
		Pn(i);
#endif
	}
	puts("none");
}


