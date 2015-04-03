/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define ONLINEJUDGE
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
const int maxn=30;
int a[maxn];
int dis[maxn];
int tot;
int ans;
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1800.in","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i = 1; i <=n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <=n ; ++i)
	{
		dis[i+1]=dis[i]+a[i];
		tot+=a[i];
	}
	for(int a=1;a<=n;a++)
		for(int b=a+1;b<=n;b++)
			for(int c=b+1;c<=n;c++)
				for(int d=c+1;d<=n;d++)
				{
					if((dis[b]-dis[a]==dis[d]-dis[c])&&(tot-dis[d]+dis[a]==dis[c]-dis[b]))
	       					 ans++;
				}
	printf("%d\n",ans );
	return 0;
}