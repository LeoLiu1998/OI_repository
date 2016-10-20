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
const int MAXN=200001;
int flag[MAXN],dis[MAXN],nxt[MAXN];
int ans=MAXN;
int tot=0;
int in,out;
const ll mod=1e9+7;
ll qpow(int k) {
	ll base=2;
	ll ret=1;
	while(k) {
		if(k&1) ret=ret*base%mod;
		base=base*base%mod;
		k>>=1;
	}
	return ret;
}
int main()
{
    int n,i,num,v;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       cin>>nxt[i];
    }
    for(i=1;i<=n;i++)
    {
        if(!flag[i])
        {
             tot++;
             num=1;
             v=i;
             while(1)
             {
                 flag[v]=tot;
                 dis[v]=num;
                 if(!flag[nxt[v]])
                 {
                     v=nxt[v];
                     num++;
                 }
                 else if(flag[nxt[v]]==tot)
                 {
                      ans=min(ans,num+1-dis[nxt[v]]);
                      break;
                 }
                 else
                 {
                      break;
                 }
             }
        }
    }
    in=ans;
    out=n-in;
    ll an=0;
    an=qpow(out);
    an=an*(qpow(in)-2+mod);
    cout<<an%mod<<endl;
    return 0;
}       
