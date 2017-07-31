//Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
using namespace std;
inline void splay(int &v){
    v=0;char c=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
}
const int N=200010;
typedef long long ll;
char s[N];
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
const int mod=233;
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
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
    inline void _zag(int i)
    {
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
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
struct Mat {
	const static int N=15;
	ll d[17][17];
	Mat(){
		memset(d,0,sizeof d);
	}
	Mat operator * (const Mat &a) const  {
		Mat ret;
		for(int i=0;i<=N;++i)  {
			for(int j=0;j<=N;++j) {
				ret.d[i][j]=0;
				for(int k=0;k<=N;++k) {
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
	for(int i=0;i<=ret.N;++i) ret.d[i][i]=1;
	while(p) {
		if(p&1) {
			ret=ret*x;
		}
		x=x*x;
		p>>=1;
	}
	return ret;
}
namespace seg{
    int v[N<<3],sum[N<<3];
    void push(int w,int l,int r){
    	sum[w]+=v[w]*(r-l+1);
    	if(l==r){v[w]=0;return;}
    	int mid=l+r>>1;
    	v[w<<1]+=v[w];v[w<<1|1]+=v[w];
    	v[w]=0;
    }
    void insert(int l,int r,int w,int L,int R,int val){
    	push(w,l,r);
    	if(L<=l&&r<=R){
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
	int query(int l,int r,int w,int L,int R){
		push(w,l,r);int ret=0;
		if(L<=l&&r<=R){
    		return sum[w];
    	}
    	int mid=l+r>>1;
    	if(L<=mid)ret+=query(l,mid,w<<1,L,R);
    	if(mid+1<=R)ret+=query(mid+1,r,w<<1|1,L,R);
    	return ret;
	}
}
int to[N*2],nxt[N*2],fir[N],sz,top[N],tot;
void add(int x,int y){
    nxt[++sz]=fir[x],fir[x]=sz,to[sz]=y;
    //if(x<y)cerr<<x<<" "<<y<<endl;
}
int n,a[N],sub[N],size[N],fa[N],deep[N];
void dfs(int v,int f){
    size[v]=1;fa[v]=f;deep[v]=deep[f]+1;
    for(int u=fir[v];u;u=nxt[u]){
        if(to[u]!=f){
            dfs(to[u],v);
            size[v]+=size[to[u]];
        }
    }
}
void dfs(int v,int fa,bool is){
    top[v]=is?top[fa]:v;
    sub[v]=++tot;
    int a=0,b=0;
    for(int u=fir[v];u;u=nxt[u]){
        if(to[u]!=fa&&size[to[u]]>b){
            b=size[to[u]];
            a=to[u];
        }
    }
    if(a)dfs(a,v,1);
    for(int u=fir[v];u;u=nxt[u]){
        if(to[u]!=fa&&to[u]!=a){
            dfs(to[u],v,0);
        }
    }
}
bool query(int u,int v){
    int ans=0;
    while(top[u]!=top[v]){
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        ans^=seg::query(1,n,1,sub[top[u]],sub[u]);
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    ans^=seg::query(1,n,1,sub[u],sub[v]);
    return ans;
}
void add(int u,int v,int p){
	while(top[u]!=top[v]){
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        seg::insert(1,n,1,sub[top[u]],sub[u],p);
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    seg::insert(1,n,1,sub[u],sub[v],p);
}
int qur(int u,int v){
	int ret=0;
	while(top[u]!=top[v]){
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        ret+=seg::query(1,n,1,sub[top[u]],sub[u]);
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    ret+=seg::query(1,n,1,sub[u],sub[v]);
    return ret;
}
int calc(int x,int y,int z){
	add(x,y,1);
	int ret=qur(x,z);
	add(x,y,-1);
	return ret;
}
int main(){
    int q;splay(n);splay(q);
    for(int i=2;i<=n;i++){
        int x;splay(x);
        add(x,i),add(i,x);
    }
    dfs(1,0),dfs(1,0,0);
    for(int i=1;i<=q;i++){
    	int x,y,z;
    	splay(x),splay(y),splay(z);
    	int ans=0;
    	ans=max(calc(x,y,z),ans);
    	ans=max(calc(y,z,x),ans);
    	ans=max(calc(z,x,y),ans);
    	cout<<ans<<endl;
    }
}
