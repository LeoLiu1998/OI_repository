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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n,cnt;
int ori[200050];
int f[200050];
int ans[200500];
int root;
set<int> vis;
int conf=0;
int getf(int x) {
	vis.clear();
	int cur=x;
	while(f[cur]!=cur) {
		vis.insert(cur);
		cur=f[cur];
		if(vis.count(cur)) {
			conf=cur;
			return -1;
		}
		 vis.insert(cur);
	}
	int r=cur; int la;
	while(r!=x) {
		la=x;
		x=f[x];
		f[la]=r;
	}
	return r;
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(ori[i]);
		f[i]=ori[i]; ans[i]=ori[i];
		if(ori[i]==i&&(!root)) root=i;
	}
	if(root<1) {
		root=getf(1);
	}
	if(root<1) {
		root=conf; cnt++;
	}
	f[root]=root;
	ans[root]=root;
	for(int i=1;i<=n;++i) {
		int cur=getf(i);
		if(cur!=root) {
			if(cur==-1) cur=conf;
			cnt++;
			if(cur>0) {
				f[cur]=root;
				ans[cur]=root;
			}
			else {
				f[i]=root;
				ans[i]=root;
			}
		}
	}
	Pn(cnt);
	for(int i=1;i<n;++i) {
		Ps(ans[i]);
	}
	Pn(ans[n]);

}


