/**************************************************************
    Problem: 1706
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:156 ms
    Memory:4896 kb
****************************************************************/
 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1010580540
using namespace std;
struct matrix
{
  int p[105][105],n;
  matrix(){memset(p,60,sizeof(p));}
}ans,a;
matrix operator * (matrix a,matrix b)
  {
    matrix c;c.n=a.n;
    for (int i=1;i<=a.n;i++)
      for (int j=1;j<=b.n;j++)
        for (int k=1;k<=a.n;k++)  
          c.p[i][j]=min(c.p[i][j],a.p[i][k]+b.p[k][j]);
    return c;
  }
int i,n,j,k,K,tot,x,y,z,s,e,m,dfs[1000005];
matrix quick(int b)
{
  matrix res;
  bool flag=true;
  while (b)
  {
    if (b&1) 
    {
      if (flag) 
      {
        flag=false;
        res=a;
      }
      else res=res*a;
    }
    b=b/2;a=a*a;
  }
  return res;
}
int get(int x)
{
  if (dfs[x]) return dfs[x];
  dfs[x]=++n;return n;
}
int main()
{
  scanf("%d%d%d%d",&K,&m,&s,&e);
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&z,&x,&y);
    x=get(x);y=get(y);
    a.p[x][y]=a.p[y][x]=z;
  }
  s=get(s);e=get(e);a.n=n;
  ans=quick(K);
  printf("%d",ans.p[s][e]);
  return 0;
}
