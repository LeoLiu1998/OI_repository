//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
    x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define up(i,j,n)		for (int i = j; i <= n; i++)
#define down(i,j,n)	for (int i = j; i >= n; i--)
#define cmax(a,b)		a = max (a, b)
#define cmin(a,b)		a = min (a, b)
#define pii			pair<int, int>
#define fi			first
#define se			second
#define Auto(i,node)	for (int i = LINK[node]; i; i = e[i].next)

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


const int MAXN = 2e5 + 5;
const int MAXM = 1e6 + 5;
const int LIM = 1e6;
const int oo = 0x3f3f3f3f;

ll cal(int x) {
    return 1LL * x * (x - 1) / 2;
}

int N, Q, cnt = 0;
struct Edges {
    int x, y, v;
} eds[MAXN];

map<pii, int> ID;

namespace LCT {
struct tree {
    int son[2], siz, fa, sz;
    bool tag;
} t[MAXM << 4];
int sta[MAXN];
inline bool get(int k) {
    return k == t[t[k].fa].son[1];
}
inline bool isrt(int k) {
    if (!k) return 1;
    return k != t[t[k].fa].son[0] && k != t[t[k].fa].son[1];
}
inline void rel(int k) {
    if (!k) return;
    int s0 = t[k].son[0], s1 = t[k].son[1];
    t[k].siz = t[k].sz;
    if (s0) t[k].siz += t[s0].siz;
    if (s1) t[k].siz += t[s1].siz;
}
void rev(int k) {
    if (!k) return;
    swap(t[k].son[0], t[k].son[1]);
    t[k].tag ^= 1;
}
void Pushdown(int k) {
    if (!k || !t[k].tag) return;
    int s0 = t[k].son[0], s1 = t[k].son[1];
    rev(s0);
    rev(s1);
    t[k].tag ^= 1;
}
void rotate(int k) {
    int fa = t[k].fa, ffa = t[fa].fa, w = get(k);
    t[fa].son[w] = t[k].son[w ^ 1];
    t[t[fa].son[w]].fa = fa;
    if (!isrt(fa)) t[ffa].son[fa == t[ffa].son[1]] = k;
    t[k].son[w ^ 1] = fa;
    t[fa].fa = k;
    t[k].fa = ffa;
    rel(fa);
    rel(k);
}
void splay(int k) {
    int top = 0;
    sta[++top] = k;
    for (int node = k; !isrt(node); node = t[node].fa) sta[++top] = t[node].fa;
    while (top) Pushdown(sta[top--]);
    while (!isrt(k)) {
        int fa = t[k].fa;
        if (!isrt(fa)) rotate(get(fa) == get(k) ? fa : k);
        rotate(k);
    }
}
void access(int k) {
    int tmp = 0;
    while (k) {
        splay(k);
        int s1 = t[k].son[1];
        if (s1) t[k].sz += t[s1].siz;
        t[k].son[1] = tmp;
        if (tmp) t[k].sz -= t[tmp].siz;
        tmp = k;
        rel(k);
        k = t[k].fa;
    }
}
void mkrt(int k) {
    access(k);
    splay(k);
    rev(k);
}
int getsiz(int k) {
    access(k);
    splay(k);
    return t[k].siz;
}
void Link(int x, int y) {
    mkrt(x);
    access(x);
    splay(x);
    t[x].fa = y;
    t[y].sz += t[x].siz;
    rel(y);
}
void Cut(int x, int y) {
    mkrt(x);
    access(y);
    splay(y);
    t[y].son[0] = 0;
    t[x].fa = 0;
    rel(y);
}
} using namespace LCT;

namespace BIT {
ll c[MAXM];
inline int lowbit(int i) {
    return i & (-i);
}
inline void upd(int o, ll v) {
    for (int i = o; i <= LIM; i += lowbit(i))
        c[i] += v;
}
inline ll calc(int o) {
    ll sum = 0;
    for (int i = o; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
} using namespace BIT;

int O(int o, int k) {
    if (!ID[make_pair(o, k)]) {
        ID[make_pair(o, k)] = ++cnt;
        t[cnt].siz = t[cnt].sz = 1;
    }
    return ID[make_pair(o, k)];
}

namespace Graph {
struct edge {
    int y, next, v;
} e[MAXN << 1];
int LINK[MAXN], len = 0;
inline void ins(int x, int y, int v) {
    e[++len].next = LINK[x];
    LINK[x] = len;
    e[len].y = y;
    e[len].v = v;
}
inline void Ins(int x, int y, int v) {
    ins(x, y, v);
    ins(y, x, v);
}
void DFS(int node, int fa) {
    Auto (i, node) if (e[i].y != fa) {
        DFS(e[i].y, node);
        int x = O(e[i].v, node), y = O(e[i].v, e[i].y);
        upd(e[i].v, -cal(getsiz(x)));
        upd(e[i].v, -cal(getsiz(y)));
        Link(x, y);
        upd(e[i].v, cal(getsiz(x)));
    }
}
} using namespace Graph;

namespace solution {
void Prepare() {
    scanf("%d", &N);
    up (i, 1, N - 1) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        Ins(x, y, v);
        eds[i] = (Edges) {
            x, y, v
        };
    }
    DFS(1, 0);
}
void Solve() {
    scanf("%d", &Q);
    while (Q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int o, v;
            scanf("%d%d", &o, &v);
            int x = eds[o].x, y = eds[o].y, c = eds[o].v;
            if (c == v) continue;
            upd(c, -cal(getsiz(O(c, x))));
            upd(v, -cal(getsiz(O(v, x))));
            upd(v, -cal(getsiz(O(v, y))));
            Cut(O(c, x), O(c, y));
            upd(c, cal(getsiz(O(c, x))));
            upd(c, cal(getsiz(O(c, y))));
            eds[o].v = v;
            Link(O(v, x), O(v, y));
            upd(v, cal(getsiz(O(v, x))));
        }
        if (op == 2) {
            int le, ri;
            scanf("%d%d", &le, &ri);
            printf("%lld\n", calc(ri) - calc(le - 1));
        }
        if (op == 3) {
            int o;
            scanf("%d", &o);
            int x = eds[o].x, c = eds[o].v;
            printf("%lld\n", cal(getsiz(O(c, x))));
        }
    }
}
}

int main() {
    solution::Prepare();
    solution::Solve();
    return 0;
}
