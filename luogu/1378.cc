#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
using namespace std;
struct eee
{
       int x,y;
};
int n,xz,xy,yz,yy;
double ans;
double cost[10][10];
double fuck[10];
eee a[10];
bool hash[10];
int b[10];
double S;
void init()
{

}

void readdata()
{
     scanf("%d%d%d%d%d\n",&n,&xz,&yz,&xy,&yy);
     int x1,x2,y1,y2;
     x1=xz<xy ? xz:xy;
     x2=xz>xy ? xz:xy;
     y1=yz<yy ? yz:yy;
     y2=yz>yy ? yz:yy;
     xz=x1;
     yz=y1;
     xy=x2;
     yy=y2;
     int i,j;
     for(i=1; i<=n; i++)
     scanf("%d%d\n",&a[i].x,&a[i].y);
     for(i=1; i<=n-1; i++)
     for(j=i+1; j<=n; j++)
     {
             cost[i][j]=sqrt(double((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)));
             cost[j][i]=cost[i][j];
     }
     S=fabs(xz-xy)*fabs(yz-yy);
}

double min(double x,double y)
{
       return x<y ? x:y;
}

double max(double x,double y)
{
       return x>y ? x:y;
}

void calc()
{
     int i,j;
     double minn,t;
     t=0;
     memset(fuck,0,sizeof(fuck));
     for(i=1; i<=n; i++)
     {
              minn=2147483647;
              for(j=1; j<=i-1; j++) minn=min(minn,cost[b[i]][b[j]]-fuck[b[j]]);
              if (minn<0)continue;
              minn=min(minn,fabs(double(a[b[i]].x-xz)));
              minn=min(minn,fabs(double(a[b[i]].y-yz)));
              minn=min(minn,fabs(double(a[b[i]].x-xy)));
              minn=min(minn,fabs(double(a[b[i]].y-yy)));
              t=t+minn*minn*3.1415926535897932384626433832795;
              fuck[b[i]]=minn;
     }
     ans=max(ans,t);
}

void dfs(int h)
{
     if(h>=n+1)
     {         
               calc();
               return;
     }
     int i;
     for(i=1; i<=n; i++)
     if(!hash[i])
     {
              hash[i]=true;
              b[h]=i;
              dfs(h+1);
              hash[i]=false;
     }
     
}

void print()
{
     S-=ans;
     printf("%d\n",int(S+0.5));
}

int main()
{
    init();
    readdata();
    dfs(1);
    print();
    return 0;
}
