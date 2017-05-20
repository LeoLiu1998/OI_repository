//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
//typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;
const int maxn=5e5 + 10;
char ans[maxn];
int a[3][maxn];
int n;
int main() {
	R(n);
	for(int i=0;i<3;++i) {
		for(int j=1;j<=n;++j) {
			R(a[i][j]);
		}
	}
	for(int i=0;i<n;++i) {
		int k=i%3;
		while(ans[a[k][a[k][0]+1]]) {
			a[k][0]++;
		}
		ans[a[k][a[k][0]+1]]='A'+k;
//		Ps(a[k][a[k][0]+1]); printf("%c\n",ans[a[k][a[k][0]+1]]);
	}
	int q;
	R(q);
	putchar(ans[q]);
	puts("");
}

