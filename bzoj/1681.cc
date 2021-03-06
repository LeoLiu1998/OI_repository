#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define read(x) scanf("%d",&x)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
  
const int N=505, Q=N*10, oo=~0u>>2;
int q[Q], front, tail, d[N], vis[N], ihead[N], cnt, n, x, y, m, ans;
struct ED { int to, w, next; }e[Q];
void add(int u, int v, int w) {
    e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
    e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].w=w;
}
void spfa() {
    q[tail++]=1;
    for1(i, 2, n) d[i]=oo;
    vis[1]=1;
    while(front!=tail) {
        int v, u=q[front++]; if(front==Q) front=0; vis[u]=0;
        for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+e[i].w) {
            d[v]=d[u]+e[i].w;
            if(!vis[v]) {
                vis[v]=1;
                q[tail++]=v; if(tail==Q) tail=0;
            }
        }
    }
}
  
int main() {
    read(n); read(m); read(x); read(y);
    for1(i, 1, m) {
        int u=getint(), v=getint(), w=getint();
        add(u, v, w);
    }
    spfa();
    for1(i, 1, x) {
        int t=getint();
        if(d[t]<=y) vis[i]=1, ++ans;
    }
    printf("%d\n", ans);
    for1(i, 1, x) if(vis[i]) printf("%d\n", i);
    return 0;
}
