/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define ONLINEJUDGE
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
const double pi=3.1415926535898;
const int INF=1000000000;
using namespace std;

const int maxn=305;

struct DOT
{
	std::vector<int> vedge;
	DOT()
	{
		vedge.clear();
	}
}dot[maxn];

struct EDGE
{
	int to,limit,cur;
	EDGE()
	{
		to=limit=cur=0;
	}
}edge[2*maxn*maxn];
int dis[maxn];
bool vis[maxn];
int n,m,ans;
int cnt=0;
void init();
void dinic();

int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("2768.in","r",stdin);
	#endif
	init();
	dinic();
	printf("%d\n",ans);
	return 0;
}
 
void add_edge(int s,int t,int maxflow)
{
	//cout<<s<<" "<<t<<endl;
	edge[cnt].to=t;
	edge[cnt].limit=maxflow;
	dot[s].vedge.push_back(cnt);
	cnt++;
	edge[cnt].to=s;
	edge[cnt].limit=0;
	dot[t].vedge.push_back(cnt);
	cnt++;
}

void init()
{
 	register int t1,t2;
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&t1);
 		if(t1==1)
 		{
 			add_edge(0,i,1);
 		}
 		else
 			add_edge(i,n+1,1);
 	}
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d%d",&t1,&t2);
 		add_edge(t1,t2,1);
 		add_edge(t2,t1,1);
 	}
}

queue <int> q;

bool bfs()
{
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	while(!q.empty())
		q.pop();
	dis[0]=0;
	vis[0]=true;
	q.push(0);
	int cur;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(int i=0;i<dot[cur].vedge.size();i++)
		{
			if(vis[edge[dot[cur].vedge[i]].to]!=true&&(edge[dot[cur].vedge[i]].limit-edge[dot[cur].vedge[i]].cur>0))
			{
				vis[edge[dot[cur].vedge[i]].to]=true;
				dis[edge[dot[cur].vedge[i]].to]=dis[cur]+1;
				q.push(edge[dot[cur].vedge[i]].to);	
			}
		}
	}
	return vis[n+1];
}

int dfs(int cur_pos,int overage)
{
	if(cur_pos==n+1||overage==0)
		return overage;
	int ret=0,delta;
	for(int i=0;i<dot[cur_pos].vedge.size();i++)
	{
		EDGE &a=edge[dot[cur_pos].vedge[i]];
		if(dis[cur_pos]+1==dis[a.to]&&(delta=dfs(a.to,min(overage,a.limit-a.cur))>0))
		{
			a.cur+=delta;
			edge[dot[cur_pos].vedge[i]^1].cur-=delta;
			ret+=delta;
			overage-=delta;
			if(overage==0)
				break;
		}
	}
	//cout<<cur_pos<<" "<<overage<<" "<<ret<<endl;
	return ret;
}

void dinic()
{
	while(bfs())
	{
		ans+=dfs(0,INF);
	}
 	return ;
}