#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[15],f[15];
int n,m;
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=i;
    do
    {
        for(int i=1;i<=n;i++)f[i]=a[i];
        for(int i=1;i<n;i++)
            for(int j=1;j<=n-i;j++)
                f[j]+=f[j+1];
        if(f[1]==m)
        {
            for(int i=1;i<n;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n]);
            return 0;
        }
    }while(next_permutation(a+1,a+n+1));
    return 0;
}