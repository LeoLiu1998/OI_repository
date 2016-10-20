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
int a[25][25];
int b[25][25];
int n,m;
int s;
void CP() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			b[i][j]=a[i][j];
		}
	}
}
bool check(int k) {
	int cnt=0;
	for(int i=1;i<=m;++i) {
		if(b[k][i]!=i) {
			cnt++;
		}
	}
	return cnt>2? 0:1;
}
void Exchange(int a,int x) {
	for(int i=1;i<=n;++i) {
		swap(b[i][a],b[i][x]);
	}
}
bool checkT() {
	for(int i=1;i<=n;++i) {
		if(!check(i)) return 0;
	}
	return 1;
}
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			R(a[i][j]);	
			b[i][j]=a[i][j];
		}
	}
	if(checkT()) {
		puts("YES");return 0;
		
	}
	for(int i=1;i<=m;++i) {
		for(int j=i+1;j<=m;++j) {
			Exchange(i,j);
			if(checkT()) {
				puts("YES"); return 0;
			}
			Exchange(i,j);
		}
	}
	puts("NO");
}

