#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<long long> sum[2],ans[2],posx[2];
struct node{
 long long sum,st,x;
};
node val[2][1000005];
long long siz0,siz1;
long long er[1000005];
bool operator<(node a,node b)
{
 return a.sum<b.sum;
}
long long n,m;
bool check(long long x,long long y)
{
// printf("%I64d %I64d %I64d %I64d\n",x,y,n,m);
 if(x==n&&y==0)
   return 1;
 if(x==0&&y==m)
   return 1;
 if(x==n&&y==m)
   return 1;
 return 0;
}
void init()
{
 long long tt;
 long long i;
 long long labz=1;//lab为0是差，1是和 
 long long npx=0,npy=0;
 long long lab;
 long long nv=0;
 while(!(check(npx,npy)))
   {
//    printf("%I64d %I64d %I64d\n",npx,npy,lab);
    labz=0;
    if(lab%2==0)
      sum[lab%2].push_back(npx-npy),ans[lab%2].push_back(nv),posx[lab%2].push_back(npx);
    else
      sum[lab%2].push_back(npx+npy),ans[lab%2].push_back(nv),posx[lab%2].push_back(npx);
    if(lab==0)
      {
       tt=min(n-npx,m-npy);
       npx+=tt,npy+=tt;
       nv+=tt;
       if(npx==n)
         lab=1;
       if(npy==m)
         lab=3;
    }
  else
    if(lab==1)
      {
       tt=min(m-npy,npx);
       npx-=tt,npy+=tt;
       nv+=tt;
       if(npx==0)
         lab=0;
       if(npy==m)
         lab=2;
   }
    else
      if(lab==2)
        {
         tt=min(npx,npy);
         npx-=tt,npy-=tt;
         nv+=tt;
         if(npx==0)
           lab=3;
         if(npy==0)
           lab=1;
     }
   else
     if(lab==3)
       {
        tt=min(npy,n-npx);
        npx+=tt,npy-=tt;
        nv+=tt;
        if(npx==n)
          lab=2;
        if(npy==0)
          lab=0;
    }
   }
 for(i=1;i<=sum[0].size();i++)
   val[0][i].sum=sum[0][i-1],val[0][i].st=ans[0][i-1],val[0][i].x=posx[0][i-1];
 siz0=sum[0].size();
 for(i=1;i<=sum[1].size();i++)
   val[1][i].sum=sum[1][i-1],val[1][i].st=ans[1][i-1],val[1][i].x=posx[1][i-1];
 siz1=sum[1].size();
 sort(val[0]+1,val[0]+siz0+1);
 sort(val[1]+1,val[1]+siz1+1);
// printf("%I64d %I64d \n",siz0,siz1);
// for(i=1;i<=siz0;i++)
//   printf("%I64d %I64d %I64d\n",val[0][i].sum,val[0][i].st,val[0][i].x);
}
long long inf=1e13;
long long pro0(long long x,long long y)//判断二者差为x-y是否存在 
{
 long long i;
 long long np=er[20];
 for(i=19;i>=0;i--)
   {
    np-=er[i];
    if(np<=siz0)
      if(val[0][np].sum<=x-y)
        np+=er[i];
   }
 if(val[0][np-1].sum==x-y)
   return val[0][np-1].st+abs(x-val[0][np-1].x);
 else
   return inf;
}
long long pro1(long long x,long long y)//判断二者和为x+y是否存在 
{
 long long i;
 long long np=er[20];
 for(i=19;i>=0;i--)
   {
    np-=er[i];
    if(np<=siz1)
      if(val[1][np].sum<=x+y)
        np+=er[i];
   }
 if(val[1][np-1].sum==x+y)
   return val[1][np-1].st+abs(x-val[1][np-1].x);
 else
   return inf;
}
long long x[1000005],y[1000005];
int main()
{
 long long k;
 long long i;
 long long ans=0;
 er[0]=1;
 for(i=1;i<=20;i++)
   er[i]=er[i-1]*2;
 cin>>n>>m>>k;
 //scanf("%I64d%I64d%I64d",&n,&m,&k);
 init();
 for(i=1;i<=k;i++)
   {
   	cin>>x[i]>>y[i];
	   // scanf("%I64d%I64d",&x[i],&y[i]);
    ans=pro0(x[i],y[i]);
    ans=min(ans,pro1(x[i],y[i]));
    if(ans==inf||x[i]>n||y[i]>m)
      printf("-1\n");
    else
      cout<<ans<<endl;//printf("%I64d\n",ans);
   }
 return 0;
}
