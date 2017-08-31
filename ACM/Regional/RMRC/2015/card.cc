
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
int T;
int n;
pii qwq[150050];
int f[150050],s[150050],e[150050];
bool vis[150050];
int getf(int x) {
    if(f[x]==x) return x;
    f[x]=getf(f[x]);
    return f[x];
}

int main() {
    R(T);
    while(T--) {
        memset(vis,0,sizeof vis);
        memset(e,0,sizeof e);
        memset(s,0,sizeof s);
        R(n);
        rep(i,1,2*n,1) f[i]=i;
        for(int i=1;i<=n;++i) {
            int l,r;
            R(l); R(r);
            vis[l]=1; vis[r]=1;
            int fl=getf(l),fr=getf(r);
            f[fl]=f[fr]=min(fl,fr);
            qwq[i].fi=l,qwq[i].se=r;
        }
        for(int i=1;i<=n;++i) {
            e[getf(qwq[i].fi)]+=1;
            s[getf(qwq[i].fi)]+=vis[qwq[i].fi];
	    vis[qwq[i].fi]=0;
            s[getf(qwq[i].fi)]+=vis[qwq[i].se];
            vis[qwq[i].se]=0; 
	}
	rep(i,1,n,1) {
     	   cerr<<e[getf(qwq[i].fi)]<<" "<<s[getf(qwq[i].fi)]<<endl;
	   if(e[getf(qwq[i].fi)]>s[getf(qwq[i].fi)]) {
                puts("impossible");
                goto NEX;
            }
        }
        puts("possible");
NEX:
        continue;
    }
}

