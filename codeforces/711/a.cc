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
int a[1005][10];
inline int Read() {
	char ch=0; while(ch!='O'&&ch!='X') ch=getchar();
	return ch=='O';
}
bool have;
pii pos;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=4;++j) {
			a[i][j]=Read();
			if((!have)&&((j&1)==0)) {
				if(a[i][j]==a[i][j-1]&&(a[i][j])) {
					have=1;
					pos.fi=i; pos.se=j-1;
				}
			}
		}
	}
	puts(have?"YES":"NO");
	if(have) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=4;++j) {
				if(pos.fi==i) {
					if(pos.se==j||pos.se==j-1) {
						putchar('+');
						goto END;
					}
				}
				putchar(a[i][j]?'O':'X');
END:
				if(j==2) {
					putchar('|');
				}
			}
			puts("");
		}
	}
}

