#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 10010
#define M 50010
int s[N],cnt,n,m,pre[N],a,b,low[N],point[N],next[M],scc[N],ss,top,size[N];
int point2[N],next2[N],ans,cnt2;
using namespace std;
struct use{int st,en;}e[M];
struct use2{int st,en;}c[M];
void add(int x,int y)
{
   next[++cnt]=point[x];point[x]=cnt;
   e[cnt].st=x;e[cnt].en=y;
}
void add2(int x,int y)
{
   next2[++cnt2]=point2[x];point2[x]=cnt2;
   c[cnt2].st=x;c[cnt2].en=y;   
}
void dfs(int x)
{
  pre[x]=low[x]=++ss;s[++top]=x;
  for (int i=point[x];i;i=next[i])
   {
     int u=e[i].en; 
     if (!pre[u]){dfs(u);low[x]=min(low[x],low[u]);}
     else if (!scc[u]){low[x]=min(low[x],pre[u]);}
   }
  if (low[x]==pre[x])
   {
     scc[0]++;
     while (top)
     {
       scc[s[top--]]=scc[0];
       size[scc[0]]++;
       if (s[top+1]==x) break;
     }
   }
}
void tarjan()
{
  memset(scc,0,sizeof(scc));
  for (int i=1;i<=n;i++) if (!pre[i]) dfs(i);    
}
void work()
{
  for (int i=1;i<=n;i++)
   {
    for (int j=point[i];j;j=next[j])
        if (scc[i]!=scc[e[j].en])
           add2(scc[i],scc[e[j].en]);
   }    
}
void getans()
{
    for (int i=1;i<=scc[0];i++)
     {
       if (!point2[i])
        {
          if (ans>0){ans=0;return;}
          else ans=size[i];
        }
     }
}
int main()
{
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      add(a,b);
    }
   tarjan();
   work();
   getans(); 
   printf("%d\n",ans);
}