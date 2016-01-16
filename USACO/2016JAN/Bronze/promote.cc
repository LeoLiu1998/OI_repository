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
#define PROB "promote"
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
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
int peo[5][3];
int ans[4];
int main() {
	Redirect();
	for(int i=1;i<=4;++i) {
		for(int j=1;j<=2;++j) {
			R(peo[i][j]);
		}
	}
	for(int i=1;i<=4;++i) {
		peo[0][0]+=peo[i][2]-peo[i][1];
	}
	peo[1][1]+=peo[0][0];
	for(int i=4;i;--i) {
		ans[i]=peo[i][2]-peo[i][1];
		peo[i-1][2]+=ans[i];
	}
	for(int i=2;i<=4;++i) {
		Pn(ans[i]);
	}
}

