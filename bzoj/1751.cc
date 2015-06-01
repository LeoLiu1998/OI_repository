#include<cstdio>
#include<iostream>
using namespace std;
const int mx[8]={1,1,1,0,0,-1,-1,-1};
const int my[8]={1,0,-1,1,-1,1,0,-1};
int n,m,ans;
int map[110][110];
void dfs(int x,int y)
{
	map[x][y]=0;
	for (int k=0;k<8;k++)
	  {
		int nx=mx[k]+x;
		int ny=my[k]+y;
		if (map[nx][ny]) dfs(nx,ny);
	  }
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	  {
		char ch;
		cin>>ch;
		if (ch=='W')map[i][j]=1;
	  }
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	    if(map[i][j]){dfs(i,j);ans++;}
	printf("%d",ans);
}
