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
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    inline void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
struct cp{
	double x,y;
	  cp(){}
	  cp(double x,double y):x(x),y(y){}
	  cp operator+(const cp&b){return cp(x+b.x,y+b.y);}
	  cp operator-(const cp&b){return cp(x-b.x,y-b.y);}
	  cp operator*(const cp&b){return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
};

/*template<class K> inline void read(K& x){
  char c = getchar_unlocked();
  for(x = 0;c > '9' || c < '0'; c = getchar_unlocked());
  for(;c >= '0' && c <= '9'; c = getchar_unlocked()) x = x * 10 + c - '0';
}

template<class K> inline void write(K x){
  static char c[20]; int top = 0;
  do { c[++top] = x % 10 + '0'; x /= 10; }while(x);
  while(top) putchar_unlocked(c[top--]);
  putchar_unlocked('\n');
}*/
vector<long long> sum[2],ans[2],posx[2];
struct node{
 ll sum,st,x;
};
node val[2][1000005];
ll siz0,siz1;
ll er[1000005];
bool operator<(node a,node b)
{
 return a.sum<b.sum;
}
ll n,m;
bool check(ll x,ll y)
{
// printf("%I64d %I64d %I64d %I64d\n",x,y,n,m);
 if(x==n&&y==0)
   return 1;
 if(x==0&&y==m)
   return 1;
 if(x==n&&y==m)
   return 1;
 return 0;
}
void init()
{
 ll tt;
 ll i;
 ll labz=1;
 ll npx=0,npy=0;
 ll lab;
 ll nv=0;
 while(!(check(npx,npy)))
   {
    labz=0;
    if(lab%2==0)
      sum[lab%2].push_back(npx-npy),ans[lab%2].push_back(nv),posx[lab%2].push_back(npx);
    else
      sum[lab%2].push_back(npx+npy),ans[lab%2].push_back(nv),posx[lab%2].push_back(npx);
    if(lab==0)
      {
       tt=min(n-npx,m-npy);
       npx+=tt,npy+=tt;
       nv+=tt;
       if(npx==n)
         lab=1;
       if(npy==m)
         lab=3;
    }
  else
    if(lab==1)
      {
       tt=min(m-npy,npx);
       npx-=tt,npy+=tt;
       nv+=tt;
       if(npx==0)
         lab=0;
       if(npy==m)
         lab=2;
   }
    else
      if(lab==2)
        {
         tt=min(npx,npy);
         npx-=tt,npy-=tt;
         nv+=tt;
         if(npx==0)
           lab=3;
         if(npy==0)
           lab=1;
     }
   else
     if(lab==3)
       {
        tt=min(npy,n-npx);
        npx+=tt,npy-=tt;
        nv+=tt;
        if(npx==n)
          lab=2;
        if(npy==0)
          lab=0;
    }
   }
 for(i=1;i<=sum[0].size();i++)
   val[0][i].sum=sum[0][i-1],val[0][i].st=ans[0][i-1],val[0][i].x=posx[0][i-1];
 siz0=sum[0].size();
 for(i=1;i<=sum[1].size();i++)
   val[1][i].sum=sum[1][i-1],val[1][i].st=ans[1][i-1],val[1][i].x=posx[1][i-1];
 siz1=sum[1].size();
 sort(val[0]+1,val[0]+siz0+1);
 sort(val[1]+1,val[1]+siz1+1);
}
ll inf=1e13;
ll pro0(ll x,ll y)//判断二者差为x-y是否存在 
{
 ll i;
 ll np=er[20];
 for(i=19;i>=0;i--)
   {
    np-=er[i];
    if(np<=siz0)
      if(val[0][np].sum<=x-y)
        np+=er[i];
   }
 if(val[0][np-1].sum==x-y)
   return val[0][np-1].st+abs(x-val[0][np-1].x);
 else
   return inf;
}
ll pro1(ll x,ll y)//判断二者和为x+y是否存在 
{
 ll i;
 ll np=er[20];
 for(i=19;i>=0;i--)
   {
    np-=er[i];
    if(np<=siz1)
      if(val[1][np].sum<=x+y)
        np+=er[i];
   }
 if(val[1][np-1].sum==x+y)
   return val[1][np-1].st+abs(x-val[1][np-1].x);
 else
   return inf;
}
ll x[1000005],y[1000005];
int main()
{
 ll k;
 ll i;
 ll ans=0;
 er[0]=1;
 for(i=1;i<=20;i++)
   er[i]=er[i-1]*2;
 cin>>n>>m>>k;//scanf("%I64d%I64d%I64d",&n,&m,&k);
 init();
 for(i=1;i<=k;i++)
   {
    cin>>x[i]>>y[i];//scanf("%I64d%I64d",&x[i],&y[i]);
    ans=pro0(x[i],y[i]);
    ans=min(ans,pro1(x[i],y[i]));
    if(ans==inf||x[i]>n||y[i]>m)
      printf("-1\n");
    else
      printf("%I64d\n",ans-1);
   }
 return 0;
}
