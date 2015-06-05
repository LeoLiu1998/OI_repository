//数论模板函数



#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXN 1005
#define ll long long
bool is_prim[MAXN];//0真
int prim[MAXN];
int prim_cnt;

//欧几里得
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

//拓展欧几里得
void ex_gcd(int a,int b,int &d,int &x,int &y)//ax+by=d,d=gcd(a,b)
{
    if(b==0) {d=a;x=1;y=0;}
    else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

//筛法求素数
void get_prim()
{
    int i,j;
    prim_cnt=0;
    for(i=2;i<MAXN;i++)
    {
        if(!is_prim[i]) prim[prim_cnt++]=i;
        for(j=0;j<prim_cnt&&i*prim[j]<MAXN;j++)
        {
            is_prim[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

//二分快速幂,x^y%z
ll powermod(ll x,ll y,ll z)
{
    ll temp=x%z,ret=1;
    while(y)
    {
        if(y&1) ret=ret*temp%z;
        temp=temp*temp%z;
        y>>=1;
    }
    return ret;
}
//分解素因数
struct Ys
{
    int num,len;//被分解的数，分解成的素因素个数
    int ys[MAXN];//分解出来的素因数
    int cnt[MAXN];//对应素因数的指数
}temp;
void fi(int num)
{
    temp.num=num;
    temp.len=0;
    int i;
    for(i=0;i<prim_cnt&&prim[i]*prim[i]<=num;i++)
    {
        if(num%prim[i]==0)
        {
            temp.ys[temp.len]=prim[i];
            temp.cnt[temp.len]=1;
            
            num/=prim[i];
            while(num%prim[i]==0)
            {
                temp.cnt[temp.len]++;
                num/=prim[i];
            }
            
            temp.len++;
        }
    }
    if(num!=1)
    {
        temp.ys[temp.len]=num;
        temp.cnt[temp.len]=1;
        temp.len++;
    }
}
//num的正因子个数,前提是对num分解了质因数
int get_num_fac()
{
    int ans=1,i;
    for(i=0;i<temp.len;i++)
        ans*=(temp.cnt[i]+1);
    return ans;
}
//num的所有因子之和
int get_sum_fac()
{
    int ans=1,i;
    for(i=0;i<temp.len;i++)
        ans*=((pow(temp.ys[i],temp.cnt[i]+1)-1)/(temp.ys[i]-1));
    return ans;
}
//欧拉函数，求不超过num的整数中与num互素的个数
int eular(int num)
{
    int i,ret=num;
    for(i=0;i<prim_cnt&&prim[i]*prim[i]<=num;i++)
    {
        if(num%prim[i]==0)
        {
            ret-=ret/prim[i];
            while(num%prim[i]==0)
                num/=prim[i];
            if(num==1) break;
        }
    }
    if(num!=1) ret-=ret/num;
    return ret;
}
//求1~n的欧拉函数值
int phi[MAXN];
void philist(int n)
{
    int i,j;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(i=2;i<n;i++)
    {
        if(!phi[i])
        {
            for(j=i;i<n;i+=i)
            {
                if(!phi[j])
                    phi[j]=j;
                phi[j]-=phi[j]/i;
            }
        }
    }
}

//矩阵
struct matrix
{
    ll a[10][10];
    int n,m;
};
matrix mat_multi(matrix &a,matrix &b)
{
    matrix ans;
    memset(&ans,0,sizeof(ans));
    ans.n=a.n,ans.m=b.m;
    int i,j,k;
    for(i=0;i<a.n;i++)
        for(j=0;j<a.m;j++)
            for(k=0;k<b.m;k++)
                ans.a[i][k]+=a.a[i][j]*b.a[j][k];
    return ans;
}
//a.n==a.m
matrix pow_mat(matrix a,int n)
{
    matrix ret;
    memset(&ret,0,sizeof(ret));
    ret.n=ret.m=a.n;
    int i;
    for(i=0;i<n;i++)
        ret.a[i][i]=1;
    while(n)
    {
        if(n&1)
            ret=mat_multi(ret, a);
        n>>=1;
        a=mat_multi(a, a);
    }
    int j;
    for(i=0;i<ret.n;i++)
    {
        for(j=0;j<ret.n;j++)
            printf("%lld ",ret.a[i][j]);
        printf("\n");
    }
    return ret;
}
int main()
{
    return 0;
}
