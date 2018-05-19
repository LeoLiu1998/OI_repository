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
int ans=0;
int n;
int f[100050];
int size[100050];
typedef set<int> Node;
Node node[100500];

void dfs(int x) {
	for(auto c:node[x]) {
		if(c!=f[x]) {
			f[c]=x;
			dfs(c);
			size[x]+=size[c];
		}
	}
	size[x]+=1;
	if(size[x]%2==0) {
		ans++;
	}
}

int main() {
	R(n);
	for(int i=1;i<n;++i) {
		int u,v; R(u); R(v);
		node[u].insert(v);
		node[v].insert(u);
	}
	dfs(1);
	if(size[1]%2) {
		puts("-1");
	} else {
		Pn(ans-1);
	}
}


