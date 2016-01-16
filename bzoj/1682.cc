//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I64d ",x)
#else 
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define fi first
#define next nxt
#define se second
inline void R(int &x) {
    x=0; int f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
typedef long long ll;
typedef pair<int,int> pii;
static inline
void Redirect() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdout);
#endif
}
const int maxn=1005;
const int maxm=20005;
pair<int,pii> edge[maxm];
int n,m;
int f[maxn];
  
static inline
int getf(int x) {
    if(x==f[x]) return x;
    else return getf(f[x]);
}
int main() {
    R(n); R(m);
    rep(i,1,n,1) f[i]=i;
    for(int i=1;i<=m;++i) {
        int a,b,v; R(a); R(b); R(v);
        edge[i]=mp(v,mp(a,b));
    }
    int cnt=0;
    sort(edge+1,edge+m+1);
    int ans=0;
    for(int i=1;i<=m;++i) {
        int fa=getf(edge[i].se.fi),fb=getf(edge[i].se.se);
        if(fa!=fb) {
            cnt++;
            ans=max(ans,edge[i].fi);
            f[fa]=f[fb]=min(fa,fb);
        }
    }
    Pn(cnt==n-1 ? ans : -1);
}
