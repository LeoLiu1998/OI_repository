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
int f[100050];
int size[100050];
vector<int> son[100050];
double t[100050];
int n;
int dfs(int p) {
	for(int i=0;i<son[p].size();++i) {
		size[p]+=dfs(son[p][i]);
	}
	++size[p];
	return size[p];
}
void Calc(int p) {
	int temp=size[p]-1;
	for(int i=0;i<son[p].size();++i) {
		t[son[p][i]]=t[p]+(temp-size[son[p][i]])*0.5+1;
		Calc(son[p][i]);
	}
}
int main() {
	R(n);
	for(int i=2;i<=n;++i) {
		int k; R(k);
		son[k].pb(i); f[i]=k;
	}
	dfs(1);
	t[1]=1;
	Calc(1);
	for(int i=1;i<n;++i) cout<<t[i]<<" ";
	cout<<t[n]<<endl;
}

