#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,x,m;
int a[1001];
bool f[51][1001];
int main()
{
	scanf("%d%d%d",&n,&x,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0][x]=1;
	for(int i=1;i<=n;i++)
	   for(int j=0;j<=m;j++)
	   {
	   	   if(j+a[i]<=m)
	   	   {
	   	      if(f[i-1][j+a[i]])
	   	         f[i][j]=1;
	   	     }
		   if(j-a[i]>=0) 
           {
		      if(f[i-1][j-a[i]])
		         f[i][j]=1;
		     }
	   } 
    for(int i=m;i>=0;i--)
       if(f[n][i]){printf("%d",i);return 0;}
    printf("-1\n");
	return 0;
}
