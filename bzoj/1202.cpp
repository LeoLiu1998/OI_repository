/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include<iostream>
#endif
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const double pi=3.1415926535898;
using namespace std;
bool ans=true;
const int maxn=200;
int fa[maxn],f[maxn];
void init();
int n,m;
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1202.in","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=true;
		init();
	}
	return 0;
}

int find(int x)
{
	if(!fa[x]||fa[x]==x)
		return fa[x]=x;
	int temp=fa[x];
	fa[x]=find(fa[x]);
	f[x]+=f[temp];
	return fa[x];
}

void init()
{
	ans=true;
	memset(fa,0,sizeof(fa));
	memset(f,0,sizeof(f));
	register int x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int fx=find(x-1),fy=find(y);
		if(fx!=fy)
		{	
			fa[fx]=fy;
			f[fx]=f[y]+z-f[x-1];
		}
		else if (f[x-1]-f[y]!=z)
			ans=false;
	}
	puts(ans?"true":"false");
}