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
char grid[10][10];
char getc() {
	char ch=0;
	while(!isalpha(ch)&&ch!='.') ch=getchar();
	return ch;
}
int main() {
	rep(i,1,9,1) {
		rep(j,1,9,1) {
			grid[i][j]=getc();
		}
	}
	pii pos; R(pos.fi); R(pos.se);
	pos.fi%=3;
	pos.se%=3;
	if(pos.fi==0) pos.fi=3;
	if(pos.se==0) pos.se=3;
	bool flag=0;
	for(int i=(pos.fi-1)*3+1;i<=pos.fi*3;++i) {
		for(int j=(pos.se-1)*3+1;j<=pos.se*3;++j) {
			if(grid[i][j]=='.') {
				grid[i][j]='!';
				flag=1;
			}
		}
	}
	if(!flag) {
		for(int i=1;i<=9;++i) {
			for(int j=1;j<=9;++j) {
				if(grid[i][j]=='.')
					grid[i][j]='!';
			}
		}
	}
	rep(i,1,9,1) {
		rep(j,1,9,1) {
			putchar(grid[i][j]);
			if(j%3==0)
				putchar(' ');
		}
		puts("");
		if(i%3==0)
			puts("");
	}
}


