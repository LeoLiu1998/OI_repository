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
const int INF=1000005;
int factor[INF];
const int maxn=10005;
int a[maxn];
int k[maxn];
void decompose(int);
int main(int argc, char const *argv[])
{
	int n;
	//register int temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		decompose(a[i]);
	}
	for(int i=1;i<=INF;i++)
	{
		if(k[factor[i]]<i)
		{
			k[factor[i]]=i;	
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		k[i]=k[i]>k[i+1]?k[i]:k[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",k[i]);
	}
	return 0;
}

void decompose(int x)
{
	for(int i=1;i*i<=x;i++)
	{
		if(!(x%i))
		{
			factor[i]++;
			if(i*i!=x)
			factor[x/i]++;
		}
	}
	return ;
}