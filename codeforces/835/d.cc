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

inline void splay(int &v) {
    v=0;
    char c=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9') {
        v=(v<<3)+(v<<1)+c-'0';
        c=getchar();
    }
}
const int NN=50;
typedef long long ll;
int anc[5];
struct splay_node {
    int num,maxx,ls,rs,fath;
    bool lazy;
} p[5];
const int mod=233;
struct lct {
    inline void _pushdown(int i) {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;
        p[i].ls=p[i].rs;
        p[i].rs=t;
    }
    inline void _pushup(int i) {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i) {
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
    inline void _zag(int i) {
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
    void _splay(int i) {
        int j;
        while(p[i].fath!=0) {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0) {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            } else if(j==p[p[j].fath].ls) {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            } else {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i) {
        while(i!=0) {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i) {
        int j=0;
        while(i!=0) {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0) {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;
            i=anc[i];
        }
    }
    void _setroot(int i) {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
} T;
struct Mat {
    const static int N=15;
    ll d[17][17];
    Mat() {
        memset(d,0,sizeof d);
    }
    Mat operator * (const Mat &a) const  {
        Mat ret;
        for(int i=0; i<=N; ++i)  {
            for(int j=0; j<=N; ++j) {
                ret.d[i][j]=0;
                for(int k=0; k<=N; ++k) {
                    ret.d[i][j]+=d[i][k]*a.d[k][j];
                    ret.d[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};
Mat qpow(Mat x, ll p) {
    Mat ret;
    for(int i=0; i<=ret.N; ++i) ret.d[i][i]=1;
    while(p) {
        if(p&1) {
            ret=ret*x;
        }
        x=x*x;
        p>>=1;
    }
    return ret;
}
namespace seg {
int v[NN<<3],sum[NN<<3];
void push(int w,int l,int r) {
    sum[w]+=v[w]*(r-l+1);
    if(l==r) {
        v[w]=0;
        return;
    }
    int mid=l+r>>1;
    v[w<<1]+=v[w];
    v[w<<1|1]+=v[w];
    v[w]=0;
}
void insert(int l,int r,int w,int L,int R,int val) {
    push(w,l,r);
    if(L<=l&&r<=R) {
        v[w]+=val;
        push(w,l,r);
        return;
    }
    int mid=l+r>>1;
    if(L<=mid)insert(l,mid,w<<1,L,R,val);
    if(mid+1<=R)insert(mid+1,r,w<<1|1,L,R,val);
    push(w<<1,l,mid),push(w<<1|1,mid+1,r);
    sum[w]=sum[w<<1]+sum[w<<1|1];
}
int query(int l,int r,int w,int L,int R) {
    push(w,l,r);
    int ret=0;
    if(L<=l&&r<=R) {
        return sum[w];
    }
    int mid=l+r>>1;
    if(L<=mid)ret+=query(l,mid,w<<1,L,R);
    if(mid+1<=R)ret+=query(mid+1,r,w<<1|1,L,R);
    return ret;
}
}
const int N=5050;
char s[N];
int dp[N][N],ans[N];
int main() {
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1; i<=n; i++) {
        dp[i][i]=1;
        if(s[i]==s[i+1])dp[i][i+1]=2;
    }
    for(int len=3; len<=n; len++) {
        for(int i=1; i+len-1<=n; i++) {
            int l=i,r=i+len-1;
            if(dp[l+1][r-1]&&s[l]==s[r]) {
                dp[l][r]=dp[l][l+len/2-1]+1;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            ans[dp[i][j]]++;
            //cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    for(int i=n; i>=1; i--)ans[i]+=ans[i+1];
    for(int i=1; i<=n; i++) {
        printf("%d ",ans[i]);
    }
}
