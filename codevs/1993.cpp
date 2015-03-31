/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include<iostream>
#endif
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
const double pi=3.1415926535898;
using namespace std;
struct EDGE
{
	int begin,end,cur_flow,max_flow;
	EDGE()
	{
		begin=end=cur_flow=max_flow=0;
	}
};
const int  maxn=205;
std::vector<EDGE> edge;
struct Dot
{
	std::vector<int> vedge;
};

Dot dot[maxn];

void init();
void solve();

int n,m,ans;

int main(int argc, char const *argv[])
{
	init();
	solve();
	printf("%d\n",ans);
	return 0;
}


void add_edge(int s,int t,int m)
{
	EDGE cur;
	cur.begin=s;
	cur.end=t;
	cur.max_flow=m;
	edge.push_back(cur);
	dot[s].vedge.push_back(edge.size()-1);
}
void init()
{
	#ifndef ONLINEJUDGE
	freopen("1993.in","r",stdin);
	#endif
	register int t1,t2,t3;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		add_edge(t1,t2,t3);
		add_edge(t2,t1,0);
	}
}

bool bfs();
int dfs(int,int);
void solve()
{
	while(bfs())
	{
		ans+=dfs(1,10000000000);
	}
}
bool vis[maxn];
int dis[maxn];
queue<int> q;
bool bfs()
{
	memset(vis,false,sizeof(vis));
	while(!q.empty())
		q.pop();
	dis[1]=0;
	vis[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i=0;i<dot[cur].vedge.size();i++)
		{
			if(vis[edge[dot[cur].vedge[i]].end]!=true&&edge[dot[cur].vedge[i]].max_flow-edge[dot[cur].vedge[i]].cur_flow>0)
			{
				vis[edge[dot[cur].vedge[i]].end]=true;
				dis[edge[dot[cur].vedge[i]].end]=dis[cur]+1;
				q.push(edge[dot[cur].vedge[i]].end);
			}
		}
	}
	return vis[m];
}

int dfs(int cur_pos,int overage)
{
	if(cur_pos==m||overage==0)
	{
		return overage;
	}
	 int ret=0,delta;
	 for(int i=0;i<dot[cur_pos].vedge.size();i++)
	 {
	 	EDGE &a=edge[dot[cur_pos].vedge[i]];
	 	if(dis[cur_pos]+1==dis[a.end]&&(delta=dfs(a.end,min(overage,a.max_flow-a.cur_flow)))>0)
	 	{
	 		a.cur_flow+=delta;
	 		edge[dot[cur_pos].vedge[i]^1].cur_flow-=delta;
	 		ret+=delta;
	 		overage-=delta;
	 		if(overage==0)
	 			break;
	 	}
	 }
	 return ret;
}
