#include<cstdio>
#include <iostream>
#include<cstring>
using namespace std;
int n,k,ans;
char map[12][12];//棋盘
int vis[12];
int DFS(int i,int cur)
{
    if(cur>=k) //
    {
        ans++; //方案数
        return 0;
    }
    int x,y;
    for(x=i;x<n;x++)
        for(y=0;y<n;y++)
            if(!vis[y] && map[x][y]=='#')
            {
                vis[y]=1;//标记
                DFS(x+1,cur+1);//递归
                vis[y]=0;
            }
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&k)&&n!=-1)
    {
        ans=0;
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        DFS(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
