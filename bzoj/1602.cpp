/*Copyright (c)2015 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define ONLINEJUDGE
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
const int maxn= 1005;
int deep[maxn],dis[maxn],fa[maxn][11];
bool vis[maxn];
struct EDGE
{
	int to,len;
	EDGE()
	{
		to=len=0;
	}
	EDGE(int _to,int _len)
	{
		to=_to;
		len=_len;
	}
};
std::vector<EDGE> e;
struct DOT
{
	std::vector<int> ve;
}dot[maxn];
void dfs(int);
int lca(int,int);
int n,Q;
void add_edge(int,int,int);
inline void Readin(int &x)
{
	scanf("%d",&x);
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1602.in","r",stdin);
	#endif
	Readin(n);
	Readin(Q);
	register int a,b,l;
	for (int i = 1; i < n; ++i)
	{
		Readin(a);
		Readin(b);
		Readin(l);
		add_edge(a,b,l);
	}
	dfs(1);
	int x,y;
	while(Q--)
	{
		Readin(x);
		Readin(y);
		int LCA=lca(x,y);
		printf("%d\n",dis[x]+dis[y]-2*dis[LCA]);
	}
	return 0;
}

void add_edge(int a,int b,int l)
{
	e.push_back(EDGE(b,l));
	dot[a].ve.push_back(e.size()-1);
	e.push_back(EDGE(a,l));
	dot[b].ve.push_back(e.size()-1);
}

void dfs(int pos)
{
	//cout<<pos<<endl;
	vis[pos]=true;
	for(int i=1;i<=9;i++)
	{
		if(deep[pos]<(1<<i))	break;
		fa[pos][i]=fa[fa[pos][i-1]][i-1];
	}
	for (int i = 0; i <dot[pos].ve.size(); ++i)
	{
		EDGE cur=e[dot[pos].ve[i]];
		if(!vis[cur.to])
		{
			deep[cur.to]=deep[pos]+1;
			dis[cur.to]=dis[pos]+cur.len;
			//cout<<dis[cur.to];
			fa[cur.to][0]=pos;
			dfs(cur.to);
		}
	}
}

int lca(int x,int y)
{
	if(deep[x]<deep[y])	swap(x,y);
	int d=deep[x]-deep[y];
	for(int i=0;i<=9;i++)
	{
		if((1<<i)&d)x=fa[x][i];
	}
	for(int i=9;i>=0;i--)
		if(fa[x][i]!=fa[y][i]) 
			x=fa[x][i],y=fa[y][i];
	if(x==y)	return x;
	return fa[x][0];
}