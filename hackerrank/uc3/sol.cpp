#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)		for (int i = j; i <= n; i++)
#define down(i,j,n)	for (int i = j; i >= n; i--)
#define cmax(a,b)		a = max (a, b)
#define cmin(a,b)		a = min (a, b)
#define Auto(i,node)	for (int i = LINK[node]; i; i = e[i].next)

const int MAXN = 1e5 + 5;
const int oo = 0x3f3f3f3f;

int N, c[MAXN], f[MAXN], g[MAXN], ans = 0, root, S[MAXN], cnt = 0, tag;
struct splay_node {
    int num,maxx,ls,rs,fath;
    bool lazy;
} p[5];
int anc[5];
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

namespace Graph {
struct edge {
    int y, next;
} e[MAXN << 1];
int LINK[MAXN], len = 0;
inline void ins(int x, int y) {
    e[++len].next = LINK[x];
    LINK[x] = len;
    e[len].y = y;
}
inline void Ins(int x, int y) {
    ins(x, y);
    ins(y, x);
}
void DP(int node, int fa) {
    cmax (f[node], c[node]);
    cmin (g[node], c[node]);
    int mx = c[node], mn = c[node];
    Auto (i, node) if (e[i].y != fa) {
        DP(e[i].y, node);
        mx += f[e[i].y];
        mn += g[e[i].y];
    }
    cmax (f[node], mx);
    cmin (g[node], mn);
}
void reDP(int node, int fa, int Mx, int Mn) {
    int mx = c[node], mn = c[node];
    Auto (i, node) if (e[i].y != fa) {
        mx += f[e[i].y];
        mn += g[e[i].y];
    }
    if (Mx + mx > ans) {
        ans = Mx + mx;
        root = node;
        tag = 1;
    }
    if (-(Mn + mn) > ans) {
        ans = -(Mn + mn);
        root = node;
        tag = -1;
    }
    Auto (i, node) if (e[i].y != fa)
        reDP(e[i].y, node, max (Mx + mx - f[e[i].y], 0), min(Mn + mn - g[e[i].y], 0));
}
void DFS(int node, int fa) {
    if (f[node] == 0 && tag == 1) 	return;
    if (g[node] == 0 && tag == -1) 	return;
    S[++cnt] = node;
    Auto (i, node) if (e[i].y != fa) DFS(e[i].y, node);
}
} using namespace Graph;

namespace solution {
void Prepare() {
    scanf("%d", &N);
    up (i, 1, N) scanf("%d", &c[i]);
    up (i, 1, N) c[i] = (c[i] == 0 ? -1 : 1);
    up (i, 2, N) {
        int x, y;
        scanf("%d%d", &x, &y);
        Ins(x, y);
    }
}
void Solve() {
    DP(1, 0);
    reDP(1, 0, 0, 0);
    printf("%d\n", ans);
    up (i, 1, N) f[i] = g[i] = 0;
    DP(root, 0);
    DFS(root, 0);
    sort (S + 1, S + cnt + 1);
    printf("%d\n", cnt);
    up (i, 1, cnt) printf("%d ", S[i]);
    puts("");
}
}

int main() {
    //freopen("input.in", "r", stdin);
    using namespace solution;
    Prepare();
    Solve();
    return 0;
}
