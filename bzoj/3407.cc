    Problem: 3407
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:856 kb
****************************************************************/
 
#include<cstdio>
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int h,n;
int a[510];
bool f[50010];
int main()
{
    scanf("%d%d",&h,&n);
    for (int i=1;i<=n;i++) a[i]=read();
    f[0]=1;
    for (int i=1;i<=n;i++)
      for (int j=h;j>=a[i];j--)
        f[j]|=f[j-a[i]];
    for (int i=h;i;i--)
      if (f[i])
      {
        printf("%d",i);
        return 0;
      }
}
