/**************************************************************
    Problem: 1753
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1312 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[10005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    printf("%d",a[(n+1)>>1]);
    return 0;
}
