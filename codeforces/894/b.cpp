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
int a[33][33];
int n,m,k;
int ans=0;
void check() {
	rep(i,1,n,1) {
		int cur=1;
		rep(j,1,m,1) {
			cur*=a[i][j];
		}
		if(cur!=k)
			return ;
	}
	rep(i,1,m,1) {
		int cur=1;
		rep(j,1,n,1) {
			cur*=a[j][i];
		}
		if(cur!=k) return ;
	}
	ans++;
}
int main() {
	R(n); R(m); R(k);
	int l=n*m;
	for(int i=0;i<(1<<l);++i) {
		rep(j,1,n,1) {
			rep(q,1,m,1) {
				int cur=(j-1)*m+q;
				if((1<<(cur-1))&i) {
					a[j][q]=1;
				} else {
					a[j][q]=-1;
				}
			}
		}
		check();
	}
	Pn(ans);
}


