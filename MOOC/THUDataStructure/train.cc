//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
int n,m;
int a[100050];
int s[100050];
int spo=0;
int apo=0;
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) R(a[i]);
	for(int i=1;i<=n;++i) {
		while(spo&&(a[apo+1]==s[spo])) {
			apo++;
			spo--;
		}
		if(a[apo+1]==i) {
			apo++;
		} else {
			if(spo>=m) {
				puts("No");
				return 0;
			}
			s[++spo]=i;
		}
	}
	while(spo&&(a[apo+1]==s[spo])) {
		apo++; spo--;
	}
	if(apo==n) {
		puts("Yes");
	} else {
		puts("No");
	}
}

