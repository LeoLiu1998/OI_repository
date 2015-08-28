#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1.2e6+5;
int p[maxn];
int vis[maxn];
int r[maxn];
int dig[100];
int ver(int n){         //求i的回文数
    int sum=0;
    int cnt=0;
    while(n){
        dig[++cnt]=n%10;
        n=n/10;
    }
    int f=1;
    for(int i=cnt;i>=1;i--){
        sum+=dig[i]*f;
        f*=10;
    }
    return sum;
}
int table1(int n){  //素数打表
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]){
            p[i]=++cnt;
            for(int j=i;j<=n;j+=i) vis[j]=1;
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        if(p[i]>cnt) cnt=p[i];
        else p[i]=cnt;
    }
}
int table2(int n){  //回文打表
    int cnt=0;
    for(int i=1;i<=n;i++){
        r[i]=cnt;
        if(i%10==0) continue;
        if(ver(i)==i) r[i]=++cnt;
    }
}
int main()
{
    int a,b;
    memset(vis,0,sizeof(vis));
    table1(maxn-1);
    table2(maxn-1);
    while(scanf("%d%d",&a,&b)!=EOF){
        int k=0;
        for(int i=maxn-1;i>=1;i--){
            if(p[i]<=1.0*a/b*r[i]){
                k=i;
                break;
            }
        }
        if(k) printf("%d\n",k);
        else printf("Palindromic tree is better than splay tree\n");
    }
}
