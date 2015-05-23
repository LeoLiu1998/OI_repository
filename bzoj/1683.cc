/**************************************************************
    Problem: 1683
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1664 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans,top;
int h[50005],st[50005];
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
        h[i]=read(),h[i]=read();
    ans=n;
    for(int i=1;i<=n;i++)
    {
        while(st[top]>h[i])top--;
        if(st[top]==h[i])ans--;
        else st[++top]=h[i];
    }
    printf("%d",ans);
    return 0;
}
