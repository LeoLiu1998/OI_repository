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
int T;
int n;
int e;
int a[100500];
int pos[100500];
void Move(int p) {
	int v=a[p];
	for(int i=p;i>1;--i) {
		a[i]=a[i-1];
		pos[a[i]]=i;
	}
	pos[v]=1;
	a[1]=v;
}
int main() {
	R(T);
	while(T--) {
		R(n); R(e);
		rep(i,1,n,1) a[i]=pos[i]=i;
		for(int i=1;i<=e;++i) {
			int tmp; R(tmp);
			int cp=pos[tmp];
			Move(cp);
		}
		Pn(a[n]);
	}
}

