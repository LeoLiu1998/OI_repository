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

const int N=1005;
const int leaf_hax=2099;
const int pt=9323;
const int qt=8719;

struct {
    int u,v;
    int next;
}edge[N];
int head[N];
bool vis[N];
int top,n,tot;
vector<int> node[100];
void addedge(int u,int v){
    edge[tot].u=u;
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int hax(int u){
    vis[u]=true;
    int sum=1; bool flag=false;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]){
            flag=true;
            sum=sum*(pt^hax(v))%qt;
        }
    }
    if(flag) return sum;
    else return leaf_hax;
}
/*
int main(){
    int T,i,u,v; int A,B,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(vis,false,sizeof(vis));
        A=hax(1);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        for(i=1;i<=n;i++){
            memset(vis,false,sizeof(vis));
            B=hax(i);
            if(A==B){
                break;
            }
        }
        if(i<=n) puts("same");
        else puts("different");
    }
    return 0;
}

*/
set<pii> s; 
bool exi[100];
int f[100];
int getf(int x) {
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}
vector<int> hv;
void Calc(int sta) {
	hv.clear();
	memset(exi,0,sizeof exi);
	for(int i=1;i<=n;++i) {
		f[i]=i;
		if((1<<(i-1))&sta) {
			exi[i]=1;
		}
	}
	int ff;
	for(int i=1;i<=n;++i) {
		if(!exi[i]) continue;
		ff=getf(i);
		for(int j=0;j<node[i].size();++j) {
			if(!exi[node[i][j]]) continue;
			int fa=getf(i),fb=getf(node[i][j]);
			f[fa]=f[fb]=min(fa,fb);
			ff=f[fa];
		}
	}
	for(int i=1;i<=n;++i) {
		if(!exi[i]) continue;
		if(getf(ff)!=getf(i)) return;
	}
	memset(vis,0,sizeof vis);
	memset(head,-1,sizeof head);
	tot=0;
	for(int i=1;i<=n;++i) {
		if(!exi[i]) continue;
		for(int j=0;j<node[i].size();++j) {
			if(!exi[node[i][j]]) continue;
			if(node[i][j]<i) continue;
			addedge(i,node[i][j]);
			addedge(node[i][j],i);
		}
	}
	for(int i=1;i<=n;++i) {
		if(!exi[i]) continue;
		hv.pb(hax(i));
	}
	sort(hv.begin(),hv.end());
	s.insert(mp(hv[0],hv[1]));
}

int main() {
	R(n);
	for(int i=1;i<n;++i) {
		int u,v; R(u); R(v);
		node[u].pb(v);
		node[v].pb(u);
	}
	for(int i=1;i<=(1<<n)-1;++i) {
		Calc(i);
	}
	Pn(s.size());
}
