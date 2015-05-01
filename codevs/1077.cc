//Copyright (C) 2015 Ye Guanghao
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=105;
int map[maxn][maxn];
int main()
{
        int n;
        cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i!=j)
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	int a,b;
	int m;
	cin>>m;
	while(m--)
	{
		cin>>a>>b;
		cout<<map[a][b]<<endl;
	}
}
