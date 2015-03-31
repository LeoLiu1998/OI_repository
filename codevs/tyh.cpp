//Includes And I/O Defines
/*#include <bits/stdc++.h>*/
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <vector>
#include <memory>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#ifdef WIN32
#define LLD "%i64d"
#else
#define LLD "%lld"
#endif

inline void readint(int& a){
        a = 0;
        int c;
        do
                c = getchar();
        while(c < '0' || c > '9');
        do{
                a = a * 10 - '0' + c;
                c = getchar();
        } while(c >= '0' && c <= '9');
}
//End Of Includes And I/O Defines

//Consts
const int maxn = 100000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
const double pi = 3.1415926535897932384626433832795028841971;
//End Of Consts;

#define PROC "a"
#define JUDGE

struct edge{
        int t,v,nxt,flow;
};
int n,m,s,e,c,cur,ans,t;
edge a[500];
int fir[209],now[209],dist[209];
int q[2009],head,tail;
int bian[209];
bool vis[209];
void add_edge(int s,int e,int c){
        cur++;
        if (fir[s]==0) fir[s]=cur;
        else a[now[s]].nxt=cur;
        now[s]=cur;
        a[cur].t=e;
        a[cur].v=c;
}
bool bfs(){
        memset(vis,false,sizeof(vis));
        head=0;
        tail=1;
        q[1]=s;
        dist[s]=0;
        vis[s]=true;
        while (head!=tail){
                int x=q[++head];
                for (int i=fir[x];i!=0;i=a[i].nxt){
                        if (!vis[a[i].t] && a[i].v>a[i].flow){
                                vis[a[i].t]=true;
                                dist[a[i].t]=dist[x]+1;
                                q[++tail]=a[i].t;
                        }
                }
        }
        return vis[t];
}
int dfs(int x,int nowflow){
        if (x==t || nowflow==0) return nowflow;
        int flow=0,f;
        for (int i=bian[x];i!=0;i=a[i].nxt){
                bian[x]=i;
                if (dist[x]+1==dist[a[i].t] && (f=dfs(a[i].t,min(nowflow,a[i].v-a[i].flow)))>0){
                        a[i].flow+=f;
                        a[i^1].flow-=f;
                        flow+=f;
                        nowflow-=f;
                        if (nowflow==0) break;
                }
        }
        return flow;
}
int main(){
        std::ios::sync_with_stdio(false);
        scanf("%d%d",&n,&m);
        cur++;
        for (int i=1;i<=n;i++){
                scanf("%d%d%d",&s,&e,&c);
                add_edge(s,e,c);
                add_edge(e,s,0);
        }
        s=1;t=m;
        while (bfs()){
                for (int i=1;i<=m;i++)
                        bian[i]=fir[i];
                ans+=dfs(s,inf);
        }
        printf("%d",ans);
}
