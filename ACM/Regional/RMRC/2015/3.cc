//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
    x=0; int f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
void Redirect() {
    freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
    freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef unsigned long long LL;  
const int S=8; ///随机化算法判定次数  
  
///计算ret=(a*b)%c  a,b,c<2^63  
ll mult_mod(ll a,ll b,ll c)  
{  
    a%=c;  
    b%=c;  
    ll ret=0;  
    ll temp=a;  
    while(b)  
    {  
        if(b&1)  
        {  
            ret+=temp;  
            if(ret>c)  
                ret-=c;//直接取模慢很多  
        }  
        temp<<=1;  
        if(temp>c)  
            temp-=c;  
        b>>=1;  
    }  
    return ret;  
}  
  
///计算ret=(a^n)%mod  
ll pow_mod(ll a,ll n,ll mod)  
{  
    ll ret=1;  
    ll temp=a%mod;  
    while(n)  
    {  
        if(n&1)  
            ret=mult_mod(ret,temp,mod);  
        temp=mult_mod(temp,temp,mod);  
        n>>=1;  
    }  
    return ret;  
}  
  
///通过费马小定理 a^(n-1)=1(mod n)来判断n是否为素数  
///中间使用了二次判断,令n-1=x*2^t  
///是合数返回true，不一定是合数返回false  
bool check(ll a,ll n,ll x,ll t)  
{  
    ll ret=pow_mod(a,x,n);  
    ll last=ret;//记录上一次的x  
    for(int i=1;i<=t;i++)  
    {  
        ret=mult_mod(ret,ret,n);  
        if(ret==1&&last!=1&&last!=n-1)  
            return true;//二次判断为是合数  
        last=ret;  
    }  
    if(ret!=1)  
        return true;//是合数,费马小定理  
    return false;  
}  
  
  
///Miller_Rabbin算法  
///是素数返回true(可能是伪素数)，否则返回false  
bool Miller_Rabbin(ll n)  
{  
    if(n<2) return false;  
    if(n==2) return true;  
    if((n&1)==0) return false;//偶数  
    ll x=n-1;  
    ll t=0;  
    while((x&1)==0)  
    {  
        x>>=1;  
        t++;  
    }  
    srand(time(NULL));  
    for(int i=0;i<S;i++)  
    {  
        ll a=rand()%(n-1)+1; // 生成随机数 0<a<=n-1  去试试  
        if(check(a,n,x,t))  
            return false;  
    }  
    return true;  
}  
int n;
int ans=-1;
int main() {
    while(cin>>n) {
	n-=3;
        if(n==0) {
            puts("4");
            continue;
        } else if(n<=3) {
            puts("No such base");
            continue;
        }
        ans=n;
        if(Miller_Rabbin(n)) {
		Pn(ans);
		continue;
	}
	for(int i=4;i*i<=n;++i) {
            if(n%i==0) {
                ans=min(ans,i);
                break;
            }
        }
        if(n%3==0&&(n/3>3)) {
            ans=min(ans,n/3);
        }
        if(n%2==0&&(n/2>3)) {
            ans=min(ans,n/2);
        }
        Pn(ans);
    }
}
