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

int n, d, MOD ; 

const int MAXN = 1010 ;
const int MAXD = 11; 

int dp[MAXN][MAXN][MAXD] ;

int Inv[MAXN] ;

inline void update(int &a, int b) {
  a += b ;
  if (a >= MOD) a -= MOD ; 
}
int qpow(int a,int b) {
  int tmp = a, ret = 1; 
  for (; b; b >>= 1, tmp = 1LL * tmp * tmp % MOD ){
    if (b & 1) ret = 1LL * ret * tmp % MOD ; 
  }
  return ret;
}

void Init() {
  for (int i = 1; i <= 1000; i ++) {
    Inv[i] = qpow(i, MOD - 2) ; 
  }
}

int f[MAXN] ; 
void DP() {
	f[1]=1;
	dp[0][0][0]=1;
	rep(j,0,d,1) {
		dp[1][j][j]=1;
	}
	for(int i=2;2*i<=n;++i) {
		f[i]=dp[i-1][i-1][d-1];
		rep(k,0,d,1) {
			rep(j,0,n,1) {
				if(dp[i-1][j][k]) {
					ll temp=dp[i-1][j][k];
					for(int mt=0;j+i*mt<=n&&mt+k<=d&&temp;++mt) {
						update(dp[i][j+i*mt][mt + k], temp) ;
						temp=temp*(f[i]+mt)%MOD*Inv[mt+1]%MOD;
					}
				}
			}
		}
	}
}
void Solve() {
	if(n<3) {
		cout<<"1\n"; exit(0);
	} else if(n%2==1) {
		cout<<dp[n/2][n-1][d]<<endl;
	} else {
		ll ans=dp[n/2 -1][n-1][d];
		ll naive=f[n/2];
		naive=(naive+1)*naive%MOD *Inv[2]%MOD;
		ans+=naive;
		ans%=MOD;
		cout<<ans<<endl;
	}
}

int main() {
 	R(n); R(d); R(MOD);
	Init() ; 
  	DP() ; 
  	Solve() ; 
}
