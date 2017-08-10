#include<bits/stdc++.h>
inline void splay(int &v){
    v=0;char c=0;int p=1;
    while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
    while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
    v*=p;
}
const int N=3005;
using namespace std;
int mp[N][N],v[N],f[N],n,m,vis[N];
int stoerwagner(){
    int ret=1<<30;
    for(int i=0;i<n;i++)v[i]=i;
    while(n>1){
        int k,pr=0;
        memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));
        for(int i=1;i<n;i++){
            k=-1;
            for(int j=1;j<n;j++){
                if(!vis[v[j]]){
                    f[v[j]]+=mp[v[pr]][v[j]];
                    if(k==-1||f[v[k]]<f[v[j]])k=j;
                }
            }
            vis[v[k]]=1;
            if(i==n-1){
                ret=min(ret,f[v[k]]);
                for(int j=0;j<n;j++){
                    mp[v[pr]][v[j]]+=mp[v[j]][v[k]];
                    mp[v[j]][v[pr]]+=mp[v[j]][v[k]];
                }
                v[k]=v[--n];
            }
            pr=k;
        }
    }
    return ret;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(mp,0,sizeof(mp));
        while(m--){
            int u,v,w;
            splay(u),splay(v),splay(w);
            mp[--u][--v]+=w;mp[v][u]+=w;
        }
        printf("%d\n",stoerwagner());
    }
}