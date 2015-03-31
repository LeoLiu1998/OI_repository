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
const int maxn=1001;
int a[maxn][maxn];
int T;
int n,m;
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1019.in","r",stdin);
	#endif
	register int t1,t2;
	scanf("%d",&T);
	while(T--)
	{
		bool ans=true;
		memset(a,0,sizeof(a));		
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&t1,&t2);
			a[t1][t2]=1;
		}
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(a[x][y]&&x!=y)
				{
					for(int z=1;z<=n;z++)
					{
						if(a[y][z]&&(!a[x][z]))
						{
							ans=false;
							goto print;
						}
					}
				}
			}
		}
print:
	if(ans)	printf("Yes\n");
	else printf("No\n");
	}
	return 0;
}