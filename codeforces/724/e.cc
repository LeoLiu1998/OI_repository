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
ll dp[2][30010];
#define dfor(i, x, y) for(int (i) = (x); (i) >= (y); (i) --)
#define For(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)

int n, c, A[30010], B[30010];
int main()
{
 R(n);
 R(c); 
 dfor(i, n, 1) R(A[i]);
 dfor(i, n, 1) R(B[i]);
 For(i, 1, n) 
 {
  dp[i & 1][0] = dp[i - 1 & 1][0] + B[i];
  dp[i - 1 & 1][i] = LLONG_MAX/2;
  For(j, 1, i) dp[i & 1][j] = min(dp[i - 1 & 1][j - 1] + A[i], dp[i - 1 & 1][j] + B[i] + (ll)c * j);
 }
 ll ans = LLONG_MAX;
 For(j, 0, n) ans = min(ans, dp[n & 1][j]);
 printf("%I64d",ans);
 return 0;
}
