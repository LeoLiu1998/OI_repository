/**************************************************************
    Problem: 1297
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:1792 ms
    Memory:992 kb
****************************************************************/
 
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=2009;
struct matrix
{
  int p[105][105],n;
}ans,a;
matrix operator * (matrix a,matrix b)
  {
    matrix c;c.n=a.n;
    memset(c.p,0,sizeof(c.p));
    for (int i=1;i<=a.n;i++)
      for (int j=1;j<=b.n;j++)
        for (int k=1;k<=a.n;k++)  
          c.p[i][j]=(c.p[i][j]+a.p[i][k]*b.p[k][j]%mod)%mod;
    return c;
  }
char s[50];
int i,n,T,j,k,tot;
matrix quick(int b)
{
  matrix res;res.n=a.n;
  for (int i=1;i<=a.n;i++)
    res.p[i][i]=1;
  while (b)
  {
    if (b&1) res=res*a;
    b>>=1;a=a*a;
  }
  return res;
}
int main()
{
  scanf("%d%d",&n,&T);a.n=n*9;
  for (i=1;i<=n;i++)
    for (j=1;j<=8;j++)
      a.p[9*(i-1)+j][9*(i-1)+j+1]=1;   //点的内部连边
  for (i=1;i<=n;i++)
  {
    scanf("%s",s);
    for (j=1;j<=n;j++)
      if (s[j-1]>'0') 
        a.p[9*(i-1)+s[j-1]-48][9*(j-1)+1]=1;  //点的外部连边
  }
  ans=quick(T);
  printf("%d",ans.p[1][n*9-8]);
  return 0;
}
