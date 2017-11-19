/*
USER: yeguang2
LANG: C++14
PROB: fence
*/
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
#define PROB "fence"
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
map<int,int> discr;
unordered_map<int,int> rdis;
pii e[1505];
multiset<int> edge[505];
int n;
int cnt=0;
int ans[1505];

void remove(int l,int r) {
	auto it=edge[l].find(r);
	if(it!=edge[l].end()) edge[l].erase(it);
	it=edge[r].find(l);
	if(it!=edge[r].end()) edge[r].erase(it);
	//edge[l].erase(r);
	//edge[r].erase(l);
}
void dfs(int k) {
	if(edge[k].empty()) {
		ans[++cnt]=k;
	} else {
		while(edge[k].size()) {
			auto i=edge[k].begin();
			remove(k,*i);
			dfs(*i);
		}
		ans[++cnt]=k;
	}
}

int main() {
	Redirect();
	R(n);
	rep(i,1,n,1) {
		int l,r;
		R(l); R(r);
		discr[l]=1;
		discr[r]=1;
		e[i]=mp(l,r);
	}
	for(auto i=discr.begin();i!=discr.end();++i) {
		i->se=++cnt;	
		rdis[cnt]=i->fi;
	}
	for(int i=1;i<=n;++i) {
		int l=discr[e[i].fi],r=discr[e[i].se];
		edge[l].insert(r);
		edge[r].insert(l);
	}
	bool vis=0;
	cnt=0;
	for(int i=1;i<=n;++i) {
		if(edge[i].size()%2) {
			dfs(i);
			vis=1;
			break;
		}
	}
	if(!vis) dfs(1);
	for(int i=cnt;i;--i) {
		Pn(rdis[ans[i]]);
	}
}


