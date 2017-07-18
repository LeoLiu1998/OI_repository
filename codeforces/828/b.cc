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
int u=INT_MAX,d,l=INT_MAX,r;
int a[105][105];
int n,m;
int cnt=0;
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			char ch=0; while(!isalpha(ch)) ch=getchar();
			a[i][j]= (ch=='B');
			if(ch=='B') {
				u=min(u,i);
				d=max(d,i);
				l=min(j,l);
				r=max(j,r);
				cnt++;
			}
		}
	}
	if(!cnt) {
		Pn(1);
		return 0;
	}
	int len=max(d-u+1,r-l+1);
	if(len>n||len>m) {
		puts("-1");
		return 0;
	}

	Pn(len*len-cnt);
}

