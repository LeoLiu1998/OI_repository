/**************************************************************
    Problem: 2054
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:352 ms
    Memory:17408 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
 
using namespace std;
 
const int maxn=1000003;
 
int res[maxn],f[maxn],n,m,p,q;
 
char out[maxn*9],*c=out+(maxn*9-1);
 
int getf(int now)
{
    int p,pp;
    for (p=now;p ^ f[p];p=f[p]);
    for (;now ^ p;)
    {
        pp=f[now];
        f[now]=p;
        now=pp;
    }
    return p;
}
 
int main()
{
    //freopen("dyes.in","r",stdin);
    //freopen("dyes.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for (int a=1;a<=n+1;a++)
        f[a]=a;
    int l;
    if (n<m) l=m-n;
    else l=0;
    int r=m;
    for (int a=r;a>l;a--)
    {
        int left=(a*p+q)%n+1;
        int right=(a*q+p)%n+1;
        if (left>right) left ^= right ^=left ^=right;
        for (int b=getf(left);b<=right;b=f[b])
        {
            res[b]=a;
            f[b]=getf(b+1);
        }
    }
    int now;
    for (int a=n;a>=1;a--)
    {
        now=res[a];
        *c='\n';
        c--;
        do
        {
            *c=now % 10+'0';
            now/=10;
            c--;
        }while (now);
    }
    c++;
    puts(c);
 
    return 0;
}
