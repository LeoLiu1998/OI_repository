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
#define PROB "closing"
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
typedef vector<int> Node;
const int maxn=200500;
int f[maxn];
int getf(int x) {
	if(f[x]==x) return x;
	else f[x]=getf(f[x]);
	return f[x];
}
Node node[maxn];
bool exi[maxn];
int n,m;
int p[maxn];
bool ans[maxn];
set<int> out;
int main() {
	Redirect();
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		f[i]=i;
	}
	for(int  i=1;i<=m;++i) {
		int a,b; R(a); R(b);
		node[a].pb(b);
		node[b].pb(a);
	}
	for(int i=1;i<=n;++i) R(p[i]);
	ans[n]=1; exi[p[n]]=1;
	for(int i=n-1;i;--i) {
		exi[p[i]]=1;
		for(int j=0;j<node[p[i]].size();++j) {
			if(exi[node[p[i]][j]]) {
				int fa=getf(p[i]),fb=getf(node[p[i]][j]);
				f[fa]=f[fb]=min(fa,fb);
			}
		}
		for(auto k=out.begin();k!=out.end();) {
			int v=*k;
			++k;
			if(getf(v)==getf(p[n])) {
				out.erase(out.find(v));
			}
		}
		if(getf(p[i])!=getf(p[n])) {
			out.insert(p[i]);
		}
		ans[i]=(out.size()==0);
	}
	for(int i=1;i<=n;++i) {
		if(ans[i]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

