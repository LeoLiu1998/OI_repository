/*Copyright (c)2015 zhonghaoxi
 *This sourcecode is licensed under GPLv3
 */
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

const int maxn=50001;
const int INF=123456789;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int n,m;

struct point
{
       int min,max;
       point()
       {
              min=INF;
              max=-INF;
       }
}z[maxn<<2|1];

void buildtree(int l,int r,int rt)
{
     if (l==r)
     {
              scanf("%d",&z[rt].min);
              z[rt].max=z[rt].min;
              return;
     }
     int m=(l+r)>>1;
     buildtree(lson);
     buildtree(rson);
     z[rt].max=max(z[rt<<1].max,z[rt<<1|1].max);
     z[rt].min=min(z[rt<<1].min,z[rt<<1|1].min);
}

point getans(int l,int r,int rt,int nowl,int nowr)
{
      if ((nowl<=l) && (r<=nowr)) return z[rt];
      int m=(l+r)>>1;
      point ans1,ans2,ans;
      if (nowl<=m) ans1=getans(lson,nowl,nowr);
      if (m<nowr) ans2=getans(rson,nowl,nowr);
      ans.max=max(ans1.max,ans2.max);
      ans.min=min(ans1.min,ans2.min);
      return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    buildtree(1,n,1);
    for (int a=1;a<=m;a++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        point now=getans(1,n,1,l,r);
        printf("%d\n",now.max-now.min);
    }
    
    return 0;
}