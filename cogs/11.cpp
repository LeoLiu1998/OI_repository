/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include<iostream>
#endif
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const double pi=3.1415926535898;
using namespace std;
#define PROB "maxflowa"
int ans;
const int maxn=105;
const int INF=100000000;
struct EDGE
{
	int max,cur;
	EDGE()
	{
		max=cur=0;
	}
};
EDGE m[maxn][maxn];
int dist[maxn];
bool vis[maxn];
void init();
void solve();
int main(int argc, char const *argv[])
{
	init();
	solve();
	printf("%d\n",ans );
	return 0;
}

int n;
void init()
{
	#ifndef ONLINEJUDGE
	freopen("11.in","r",stdin);
	#endif
	#ifndef DEBUG
		freopen(PROB ".in","r",stdin);
		freopen(PROB ".out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&m[i][j].max);
		}
	}
}

int dfs(int,int);
queue<int> q;
bool bfs()
{
	while(!q.empty())
		q.pop();
	memset(vis,0,sizeof(vis));
	vis[1]=true;
	dist[1]=0;
	register int cur;
	q.push(1);
	while(q.empty()!=true)
	{
		cur=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(m[cur][i].max-m[cur][i].cur>0)
			{
				if(!vis[i])
				{
					vis[i]=true;
					dist[i]=dist[cur]+1;
					q.push(i);
				}
			}
		}
	}
	//cout<<vis[n]<<endl;
	return vis[n];
}
void solve()
{
	while(bfs())
	{
		ans+=dfs(1,INF);
	}
}
int cnt=0;
int dfs(int cur,int overage)
{
	//cout<<cnt++<<endl;
	if(cur==n||overage<=0)
		return overage;
	int ret=0,delta=0;
	for(int i=1;i<=n;i++)
	{
		
		if(m[cur][i].max-m[cur][i].cur>0)
		{
			if((dist[i]==dist[cur]+1)&&(delta=dfs(i,min(overage,m[cur][i].max-m[cur][i].cur)))>0)
			{
				//cout<<delta<<endl;
				m[cur][i].cur+=delta;
				m[i][cur].cur-=delta;
				ret+=delta;
				overage-=delta;
				if(overage<=0)
					break;
			}
		}
	}
	//cout<<ret<<endl;
	return ret;
}