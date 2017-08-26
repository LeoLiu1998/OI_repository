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
char SMG[10005];
int g,b;
int main() {
	int n; R(n);
	for(int i=1;i<=n;++i) {
		memset(SMG,0,sizeof SMG);
		cin.getline(SMG,10000);
		g=0; b=0;
		for(int i=0;i<=10000;++i) {
			if(SMG[i]=='g'||SMG[i]=='G') {
				g++;
			} else if(SMG[i]=='b'||SMG[i]=='B') {
				b++;
			}
			if(isalpha(SMG[i])||SMG[i]==' ') {
				putchar(SMG[i]);
			}
		}
		printf(" is ");
		if(g>b) {
			printf("GOOD\n");
		} else if(b>g) {
			printf("A BADDY\n");
		} else {
			printf("NEUTRAL\n");
		}
	}
}

