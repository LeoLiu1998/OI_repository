#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define mod 58631
#define ll long long 
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,n,cnt;
int last[58632],ans[50005];
struct data{int val,next;}a[50005];
void insert(int x,int val)
{
	cnt++;
	a[cnt].next=last[x];
	last[x]=cnt;
	a[cnt].val=val;
}
bool add(int x)
{
	int sum=0,t=x;
	if(t<0)t=-t;
	while(t)
	{
		sum=(sum+(t%10))*(t%10)%mod;
		t/=10;
	}
	for(int i=last[sum];i;i=a[i].next)
		if(a[i].val==x)return 0;
	insert(sum,x);
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		memset(last,0,sizeof(last));
		cnt=0;ans[0]=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			int x=read();
			if(add(x))ans[++ans[0]]=x;
		}
		for(int i=1;i<ans[0];i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[ans[0]]);
	}
	return 0;
}
