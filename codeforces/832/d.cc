 //This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
    x=0; int f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
typedef pair<int,int> pii;

const int maxn=500050;
const int maxe=maxn<<1;
int to[maxe],len[maxe],next[maxe],head[maxn];
int ecnt=3;
void add_edge(int u,int v,int l) {
	len[ecnt]=l; to[ecnt]=v; next[ecnt]=head[u]; head[u]=ecnt++;
	len[ecnt]=l; to[ecnt]=u; next[ecnt]=head[v]; head[v]=ecnt++;
}
int p[maxn][21];
int deep[maxn];
int n;

void dfs(int k) {
	for(int i=head[k];i;i=next[i]) {
		if(!deep[to[i]]) {
			deep[to[i]]=deep[k]+1;
			p[to[i]][0]=k;
			dfs(to[i]);
		}
	}
}

void init() {
	for(int k=1;k<19;++k) {
		for(int i=1;i<=n;++i) {
			p[i][k]=p[p[i][k-1]][k-1];
		}
	}
}

int LCA(int a,int b) {
	if(deep[a]<deep[b]) swap(a,b);
	int del=deep[a]-deep[b];
	for(int i=0;i<20;++i) {
		if((1<<i)&del) 
			a=p[a][i];
	}
	if(a==b) return a;
	for(int i=20;i>=0;--i) {
		if(p[a][i]!=p[b][i]) {
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}

int dis(int a,int b) {
	int lca=LCA(a,b);
	return deep[a]+deep[b]-2*deep[lca];
}

int x,y,z;
int m;

int Calc(int s,int t, int v) {
	int clca=LCA(s,t);
	int ret=dis(clca,v)+1;
	cerr<< s << " "<<t<<" "<< v<<" "<<LCA(s,t)<<" "<<ret<<endl;
	return ret;
}
int main() {
	R(n); R(m);
	for(int i=2;i<=n;++i) {
		int a,b; ; a=i;R(b);
		add_edge(a,b,1);
	}
	deep[1]=1;
	dfs(1); init();
/*	rep(i,1,n,1) {
		Pn(deep[i]);
	}*/
	for(int i=1;i<=m;++i) {
		int a,b,c; R(a); R(b); R(c);
		x=LCA(a,b),y=LCA(b,c),z=LCA(a,c);
		int ans=0;
		int dx=dis(a,b),dy=dis(b,c),dz=dis(a,c);
		if(dx<dy) swap(dx,dy);
		if(dx<dz) swap(dx,dz);
		if(dy>dz) swap(dy,dz);
		if(a==b) {
			ans=dis(a,c)+1;
		} else if(b==c) {
			ans=dis(a,b)+1;
		} else if(a==c) {
			ans=dis(a,b)+1;
		} else if(dx==dy+dz) {
			ans=dy+1;
		} else if(x==y) {
			ans=max(ans,dis(z,b));
			ans=max(ans,dis(a,c));//a c		
			ans+=1;
		} else if(y==z) {
			ans=max(ans,dis(x,c));
			ans=max(ans,dis(a,b));// a b
			ans+=1;
		} else if(x==z) {
			ans=max(ans,dis(y,a));
			ans=max(ans,dis(b,c));
			ans+=1;
		} else {
			ans=Calc(a,b,c);
			ans=max(ans,Calc(a,c,b));
			ans=max(ans,Calc(b,c,a));
		}
SUC:
		Pn(ans);
	}
}
