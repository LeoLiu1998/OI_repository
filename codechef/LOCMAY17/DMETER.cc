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
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;


const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 1e9+7;
const double eps = 1e-8;
const int maxn = 100010;

struct Edge
{
    int v,w,next;
} eg[maxn<<1]; 

bool vis[maxn],on[maxn];
int dis[maxn],cost[2][3][maxn],depth[2][maxn];
int head[maxn];
int tp;
int n;

void Add(int u,int v,int w)
{
    eg[tp].v = v;
    eg[tp].w = w;
    eg[tp].next = head[u];
    head[u] = tp++;
}

void dfs1(int u,int pre)
{
    int v,w;

    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        v = eg[i].v;
        w = eg[i].w;
        if(v == pre) continue;
        dis[v] = dis[u] + w;
        dfs1(v,u);
    }
}

int st,en;

bool dfs2(int u,int pre)
{
    int v;

    on[u] = u==en;

    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        v = eg[i].v;
        if(v == pre) continue;
        if(dfs2(v,u)) on[u] = 1;
    }

    return on[u];
}

void dfs3(int pos,int u,int pre,int dep)
{
    depth[pos][u] = dep;
    cost[pos][0][u] = cost[pos][1][u] = cost[pos][2][u] = 0;

    int v,w;
    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        v = eg[i].v;
        w = eg[i].w;
        if(v == pre) continue;

        dfs3(pos,v,u,dep+1);

        int tmp = cost[pos][1][v]+w;

        if(tmp > cost[pos][1][u])
        {
            cost[pos][2][u] = cost[pos][1][u];
            cost[pos][1][u] = tmp;
        }
        else if(tmp > cost[pos][2][u]) cost[pos][2][u] = tmp;

        cost[pos][0][u] = max(cost[pos][0][u],cost[pos][0][v]);
    }

    cost[pos][0][u] = max(cost[pos][0][u],cost[pos][1][u]+cost[pos][2][u]);
}

void init()
{
    dis[1] = 0;
    dfs1(1,1);
    st = 1;

    for(int i = 1; i <= n; ++i)
        if(dis[i] > dis[st]) st = i;

    dis[st] = 0;
    memset(on,0,sizeof(on));
    dfs1(st,st);
    en = 1;

    for(int i = 1; i <= n; ++i)
        if(dis[i] > dis[en]) en = i;

    dfs2(st,st);

    dfs3(0,st,st,0);
    dfs3(1,en,en,0);
}

int cal(int u,int v)
{
    if(!on[u] || !on[v]) return dis[en];

    if(depth[0][u] > depth[0][v])
    {
        return max(cost[0][0][u],cost[1][0][v]);
    }

    return max(cost[0][0][v],cost[1][0][u]);
}

int main()
{
    //fread("");
    //fwrite("");

    int t,u,v,w;

    scanf("%d",&t);

    while(t--)
    {
        memset(head,-1,sizeof(head));
        tp = 0;

        scanf("%d",&n);
        for(int i = 1; i < n; ++i)
        {
		w=1;
            scanf("%d%d",&u,&v);
            Add(u,v,w);
            Add(v,u,w);
        }

        init();

        LL ans = 0;
        for(u = 1; u <= n; ++u)
            for(int i = head[u]; i != -1; i = eg[i].next)
            {
                Pn(cal(u,eg[i].v));
            }

       // printf("%lld\n",ans/2);
    }

    return 0;
}
