/**************************************************************
    Problem: 2243
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:5248 ms
    Memory:19644 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 100010
struct edge{int y,next;}e[N << 1];
int first[N],q[N],vis[N],size[N],dep[N],ms[N],fa[N],s[N << 1],w[N],top[N],pre[N],col[N],mark[N];
int leaf[N],root,ls[N << 2],rs[N << 2],lc[N << 2],rc[N << 2],sum[N << 2],lp[N << 2],rp[N << 2];
int cnt,n,m,head,tail,nodecnt,L,R,lcol,rcol,tot,now;
inline void addedge(int x,int y){
   e[++ cnt].next = first[x];e[cnt].y = y;first[x] = cnt;
   e[++ cnt].next = first[y];e[cnt].y = x;first[y] = cnt;
}
inline void update(int k){
   int lson = ls[k],rson = rs[k];
   lc[k] = lc[lson],rc[k] = rc[rson];
   sum[k] = sum[lson] + sum[rson] - (rc[lson] == lc[rson]);
}
inline void push_down(int k){
   if (mark[k] == -1) return;
   int lson = ls[k],rson = rs[k];
   lc[lson] = rc[lson] = lc[rson] = rc[rson] = mark[k];
   mark[lson] = mark[rson] = mark[k];
   mark[k] = -1;
   sum[lson] = sum[rson] = 1;
}
inline void build(int &root,int l,int r){
   if (root == 0) root = ++ nodecnt;
   mark[root] = -1;
   if (l == r){
       lc[root] = rc[root] = col[s[l]];
       sum[root] = 1;
       return;
   }
   int m = l + r >> 1;
   build(ls[root],l,m);
   build(rs[root],m + 1,r);
   update(root);
}
void bfs(){
   head = tail = 0;
   q[++ tail] = 1;
   vis[1] = 1;
   int x,y;
   while (head < tail){
       x = q[++ head];
       for (int i = first[x];i;i = e[i].next){
           y = e[i].y;
           if (fa[x] != y && !vis[y])
               fa[y] = x,vis[y] = 1,q[++ tail] = y,dep[y] = dep[x] + 1;
       }
   }
   for (int j = tail;j;j --){
       x = q[j];
       size[x] ++;
       for (int i = first[x];i;i = e[i].next){
           y = e[i].y;
           if (y != fa[x]){
               size[x] += size[y];
               if (size[y] > size[ms[x]]) ms[x] = y;
           }
       }
   }
}
void dfs(){
   s[tot = now = 1] = 1;
   top[1] = 1;
   int x,y;
   while (now){
       x = s[now];
       w[x] = now;
       if (vis[x] == 1){
           vis[x] = 2;
           if (ms[x]){
               s[++ tot] = ms[x];
               top[ms[x]] = top[x];
               pre[tot] = now;
               now = tot;
               continue;
           }
       }
       int flag = 0;
       for (int i = first[x];i;i = e[i].next){
           y = e[i].y;
           first[x] = i;
           if (vis[y] == 1 && y != fa[x] && y != ms[x]){
               s[++ tot] = y;
               top[y] = y;
               pre[tot] = now;
               flag = 1;
               break;
           }
       }
       if (flag) {now = tot;continue;}
       now = pre[now];
   }
}
inline void change(int root,int l,int r,int c){
   if (L <= l && R >= r){
       mark[root] = lc[root] = rc[root] = c;
       sum[root] = 1;
       return;
   }
   int m = l + r >> 1;
   push_down(root);
   if (L <= m) change(ls[root],l,m,c);
   if (R > m) change(rs[root],m + 1,r,c);
   update(root);
}
inline int ask(int root,int l,int r){
   if (L == l) lcol = lc[root];
   if (R == r) rcol = rc[root];
   if (L <= l && R >= r) return sum[root];
   int m = l + r >> 1,t1 = -1,t2 = -1,ret = 0;
   push_down(root);
   if (L <= m) ret += ask(ls[root],l,m),t1 = rc[ls[root]];
   if (R > m) ret += ask(rs[root],m + 1,r),t2 = lc[rs[root]];
   ret -= (t1 == t2 && t1 != -1);
   return ret;
}
void work(int x,int y,int c){
   int t;
   while (top[x] != top[y]){
       if (dep[top[x]] < dep[top[y]]) t = x,x = y,y = t;
       L = w[top[x]],R = w[x];
       change(root,1,n,c);
       x = fa[top[x]];
   }
   if (dep[x] < dep[y]) t = x,x = y,y = t;
   L = w[y],R = w[x];
   change(root,1,n,c);
}
int query(int x,int y){
   int ret = 0;
   int t,t1 = -1,t2 = -1;
   while (top[x] != top[y]){
       if (dep[top[x]] < dep[top[y]])
           t = x,x = y,y = t,t = t1,t1 = t2,t2 = t;
       L = w[top[x]],R = w[x];
       ret += ask(root,1,n);
       ret -= (t1 == rcol);
       t1 = lcol;
       x = fa[top[x]];
   }
   if (dep[x] < dep[y])
       t = x,x = y,y = t,t = t1,t1 = t2,t2 = t;
   L = w[y],R = w[x];
   ret += ask(root,1,n);
   ret -= ((t1 == rcol && t1 != -1) + (t2 == lcol && t2 != -1));
   return ret;
}
char ch;
void read(int &x){
   while (ch = getchar(),ch < '0' || ch > '9');
   x = ch - '0';
   while (ch = getchar(),ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
int main(){
   read(n),read(m);
   int x,y,c;
   for (int i = 1;i <= n;i ++) read(col[i]);
   for (int i = 1;i < n;i ++) read(x),read(y),addedge(x,y);
   bfs();dfs();
   build(root,1,n);
   while (m --){
       while (ch = getchar(),ch != 'Q' && ch != 'C');
       if (ch == 'C'){
           read(x),read(y),read(c);
           work(x,y,c);
       }else{
           read(x),read(y);
           printf("%d\n",query(x,y));
       }
   }
   return 0;
}
