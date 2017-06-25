#include<cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int a[50001];
int f[50001][16];
int n;
void rmq_init() //建立： dp(i,j) = min{dp(i,j-1),dp(i+2^(j-1),j-1)   O(nlogn)
{
   for(int i=1; i<=n; i++)
      f[i][0] = a[i];
   int k=floor(log((double)n)/log(2.0)); //C/C++取整函数ceil()大,floor()小
   for(int j=1; j<=k; j++)
      for(int i=n; i>=1; i--)
      {
         if(i+(1<<(j-1))<=n) //f(i,j) = min{f(i,j-1),f(i+2^(j-1),j-1)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
      }
}
int rmq(int i,int j)  //查询：返回区间[i,j]的最小值     O(1)
{
    int k = floor(log((double)(j-i+1))/log(2.0));
    return min(f[i][k],f[j-(1<<k)+1][k]);    
}
 
int main()
{
   scanf("%d",&n);
   for(int i=1; i<=n; i++)
      scanf("%d",&a[i]);
    rmq_init();
    printf("%d\n", rmq(1,2));
}
