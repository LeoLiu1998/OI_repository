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
int n=10;
int a[15][15];
int b[15];
bool checkline(int x) {
	for(int i=1;i<=x;++i) {
		if(b[i]==1) {
			int pos=i;
			while(b[pos+1]==1) pos++;
			if(pos-i+1>=5) return 1;
			i=pos;
		}
	}
	return 0;
}
#define CLX(x) memset(x,-1,sizeof x)
bool check() {
	for(int i=1;i<=n;++i) {
		CLX(b);
		rep(j,1,n,1) {
			b[j]=a[i][j];
		}
		if(checkline(n)) {
			return 1;
		}
		CLX(b);
		rep(j,1,n,1) {
			b[j]=a[j][i];
		}
		if(checkline(n)) {
			return 1;
		}
		CLX(b);
		for(int j=1;j<=i;++j) {
			b[j]=a[j][i+1-j];
		}
		if(checkline(i)) {
			return 1;
		}
		CLX(b);
		for(int j=1;j<=i;++j) {
			b[j]=a[j][n-i+j];
		}
		if(checkline(i)) {
			return 1;
		}
		CLX(b);
		for(int j=1;j<=i;++j) {
			b[j]=a[n+1-j][n-i+j];
		}
		if(checkline(i)) return 1;
		CLX(b);
		rep(j,1,i,1) b[j]=a[n+1-j][i+1-j];
		if(checkline(i)) return 1;
	}
	return 0;
}

int main() {
	rep(i,1,n,1) {
		rep(j,1,n,1) {
			char ch=0;
			while(ch!='X'&&ch!='O'&&ch!='.') ch=getchar();
			if(ch=='.') {
				a[i][j]=0;
			} else if(ch=='X') {
				a[i][j]=1;
			} else {
				a[i][j]=2;
			}
		}
	}
	rep(i,1,n,1) {
		rep(j,1,n,1) {
			if(a[i][j]==0) {
				a[i][j]=1;
				if(check()) {
					puts("YES");
					return 0;
				}
				a[i][j]=0;
			}
		}
	}
	puts("NO");
}

