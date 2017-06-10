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
int n;
int a[1005];
int b[1005];
set<int> s;
vector<int> x[3];
bool check() {
	if(x[1]==x[0]) return 0;
	else if(x[2]==x[0]) return 0;
	int qwq=0,qaq=0;
	for(int i=0;i<x[0].size();++i) {
		if(x[0][i]!=x[1][i]) qwq++;
		if(x[0][i]!=x[2][i]) qaq++;
	}
	if((qwq!=1)||(qaq!=1)) return 0;
	return 1;
}
int cn[1005];
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	for(int i=1;i<=n;++i) {
		R(b[i]);
		if(a[i]!=b[i]) {
			x[1].pb(a[i]);
			x[2].pb(b[i]);
			s.insert(a[i]);
			s.insert(b[i]);
		} else {
			cn[b[i]]++;
		}
	}
	int ovo=0;
	for(int i=1;i<=n;++i) {
		if(!cn[i]) ovo++;
	}
	if(ovo==1) {
		for(int i=1;i<=n;++i) {
			if(a[i]==b[i]) {
				Ps(a[i]);
			} else {
				for(int i=1;i<=n;++i) {
					if(!cn[i]) {
						Ps(i);
					}
				}
			}
		}
		puts("");
		return 0;
	}
	int cnt=0;
	for(auto i:s) {
		if(!cn[i])
		x[0].pb(i);
	}
	do {
		if(check()) {
			for(int i=1;i<=n;++i) {
				if(a[i]==b[i]) {
					Ps(a[i]);	
				} else {
					Ps(x[0][cnt++]);
				}
			}
			puts("");
			return 0;
		} else {
			next_permutation(x[0].begin(),x[0].end());
		}
	}while(1);
}

