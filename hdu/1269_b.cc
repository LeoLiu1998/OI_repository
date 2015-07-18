#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m,cnt,k;
vector<int>G[10001];
vector<int>G1[10001];
int vis[10001],ord[10001];
void dfs(int cur)
{
	int i;
	//memset(vis,0,sizeof(vis));
	vis[cur] = 1;
	for(i = 0; i<G[cur].size(); i++)
		if(!vis[G[cur][i]])dfs(G[cur][i]);
		ord[k++] = cur;
}
void dfs1(int cur)
{
	int i;
	vis[cur] = 1;
	for(i = 0; i<G1[cur].size(); i++)
		if(!vis[G1[cur][i]])dfs1(G1[cur][i]);
}
int main()
{
	int i,u,v,cnt,ct;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n == 0 && m == 0)break;
		for(i = 0; i<=n; i++)
		{
			G[i].clear();
			G1[i].clear();
		}
		for(i = 0; i<m; i++)
		{
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G1[v].push_back(u);
		}
		k = ct = 0;
		memset(vis,0,sizeof(vis));
		for(i = 1; i<=n; i++)
		if(!vis[i])dfs(i);
		//cout<<k<<endl;
		memset(vis,0,sizeof(vis));
		for(i = k - 1; i>=0; i--)
		if(!vis[ord[i]])
		{
			ct++;
			dfs1(ord[i]);	
		}
		if(ct == 1)puts("Yes");
		else puts("No");
	}
	return 0;
}
