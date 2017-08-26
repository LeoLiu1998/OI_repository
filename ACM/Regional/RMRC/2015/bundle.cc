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
typedef pair<int,vector<int> > piv;
piv bundle[200];
piv bundle2[200];
int n,m,T;
int f[200];
bool vis[200];
vector<int> s[200];
bool flag[200];
bool belongTo(const vector<int> &a, const vector<int> &b) {
	if(!a.size()) return 1;
	if(!b.size()) return 0;
	if(a.size()>b.size()) return 0;
	int x=a[0];
	for(int i=0;i<b.size();++i) {
		if(b[i]==x) return 1;
	}
	return 0;
}

bool belongTo(int a,int b) {
	return belongTo(bundle[a].se,bundle[b].se);
}
void dfs(int x) {
	if((!s[x].size())||vis[x]) return ;
	int cur=0;
	int ss=0;
	for(int i=0;i<s[x].size();++i) {
		dfs(s[x][i]);
		cur+= bundle[s[x][i]].fi;
		ss+= bundle[s[x][i]].se.size();
	}
	if(ss==bundle[x].se.size()) bundle[x].fi=min(bundle[x].fi,cur);
	vis[x]=1;
	return ;
}
#define CLR(x) memset(x,0,sizeof x)
int main() {
	R(T); 
	while(T--){
		CLR(bundle);
		CLR(bundle2);
		CLR(f);
		CLR(s);
		CLR(flag);
		CLR(vis);
		R(n);R(m);
		for(int i=1;i<=m;++i) {
			R(bundle[i].fi);
			int qwq,tmp; R(qwq);
			rep(j,1,qwq,1) {
				R(tmp);
				bundle[i].se.pb(tmp);
				sort(bundle[i].se.begin(),bundle[i].se.end());
			}
		}
		for(int i=1;i<=m;++i) {
			if(flag[i]) continue;
			int pos=i;
			for(int j=i+1;j<=m;++j) {
				if(belongTo(i,j)&&belongTo(j,i)) {
					pos= bundle[pos].fi<bundle[j].fi ? pos: j;
					flag[i]=flag[j]=1;
				}
			}
			flag[pos]=0;
		}
		int qaq=0;
		for(int i=1;i<=m;++i) {
			if(!flag[i]) {
				bundle2[++qaq]=bundle[i];
			}
		}
		m=qaq;
		swap(bundle2,bundle);
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				if(i==j) continue;
				if(belongTo(i,j)) {
					if(!f[i]) f[i]=j;
					else {
						if(bundle[j].se.size() < bundle[f[i]].se.size()) {
							f[i]=j;
						}
					}
				}
			}
			s[f[i]].pb(i);
		}
		int ans=0;
		for(int i=1;i<=m;++i) {
			if(!f[i]) {
				dfs(i);
				ans+=bundle[i].fi;
			}
		}
		Pn(ans);
	}

}

