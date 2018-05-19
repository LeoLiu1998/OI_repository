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
set<int> ss;
int n;
int a[105][105];
int vis[1205];
int new_p[105][105];
typedef set<int> Node;
Node node[1200];
int pa[1200];
int nn=0;
int match(int k) {
	for(auto x:node[k]) {
		if(!vis[x]) {
			vis[x]=1;
			if(!pa[x]||match(pa[x])) {
				pa[x]=k;
				return 1;
			}
		}
	}
	return 0;
}

int solve(int x) {
	memset(new_p,0,sizeof new_p);
	memset(pa,0,sizeof pa);
	int nn=0;
	for(int i=1;i<=n;++i) {
		new_p[i][0]=++nn;
		node[nn].clear();
	}
	for(int j=1;j<=n;++j) {
		new_p[0][j]=++nn;
		node[nn].clear();
	}
	for(int i=1;i<=n;++i) {
		int row=new_p[i][0];
		for(int j=1;j<=n;++j) {
			if(a[i][j]==x) {
				int col=new_p[0][j];
				node[row].insert(col);
				node[col].insert(row);
			}
		}
	}
	int ret=0;
	for(int i=n+1;i<=nn;++i) {
		memset(vis,0,sizeof vis);
		ret+=match(i);
	}
	return ret;
}

int main() {
	int T; R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		R(n);
		ss.clear();
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				R(a[i][j]);
				ss.insert(a[i][j]);
			}
		}
		int ans=0;
		for(auto x:ss) {
			ans+=solve(x);
		}
		printf("Case #%d: ",qwq);
		Pn(n*n-ans);
	}
}


