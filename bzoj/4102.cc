//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> Node;
const int maxn=1005;
Node node[maxn];
int dist[maxn][maxn];
pii quality[maxn];
int m[maxn];
int dp[maxn];
bool vis[maxn];
int n,e;
void bfs(int k) {
	memset(vis,0,sizeof(vis));
	queue<int> q; q.push(k); dist[k][k]=0;
	vis[k]=1;
	while(q.size()) {
		int qf=q.front(); q.pop();
		for(int i=0;i<node[qf].size();++i) {
			int v=node[qf][i];
			dist[k][v]=min(dist[k][qf]+e,dist[k][v]);
			if(!vis[v])  {
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
int main() {
	memset(dist,0x3f,sizeof(dist));
	R(n); R(e);
	for(int i=1;i<=n;++i) {
		int k,j; R(k); R(j);
		quality[i]=mp(k,i);
		while(j--) {
			R(k);
			node[i].pb(k);
		}
	}
	sort(quality+1,quality+n+1);
	for(int i=1;i<=n;++i) {
		m[quality[i].se]=i;
		bfs(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i)  {//end at i
		int u=quality[i].se;
		for(int j=1;j<i;++j) {
			int v=quality[j].se;
			dp[i]=max(dp[i],dp[j]+quality[i].fi-dist[u][v]);
		}
		dp[i]=max(dp[i],quality[i].fi);
		ans=max(ans,dp[i]);
	}
	Pn(ans);

}

