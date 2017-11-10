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
int a[2][3];

int main() {
	rep(i,0,1,1) {
		rep(j,0,2,1) {
			R(a[i][j]);
		}
		sort(a[i]+0,a[i]+3);
		if(a[i][1]*a[i][1]+a[i][0]*a[i][0]!=a[i][2]*a[i][2]) {
			puts("NO");
			return 0;
		}
	}
	rep(i,0,2,1) {
		if(a[0][i]!=a[1][i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");

}


