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
using namespace std;
#define lc(x) t[x].l
#define rc(x) t[x].r
const int N=5e5+5,MX=1e9+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,Q,a[N],l,r;
struct node{
    int l,r,mn;
}t[N*30];
int sz,root[N];
void ins(int &x,int l,int r,int p,int v){//right of p is v
    t[++sz]=t[x];x=sz;
    if(l==r) t[x].mn=v;
    else{
        int mid=(l+r)>>1;
        if(p<=mid) ins(t[x].l,l,mid,p,v);
        else ins(t[x].r,mid+1,r,p,v);
        t[x].mn=min(t[lc(x)].mn,t[rc(x)].mn);
    }
}
int query(int x,int l,int r,int v){
    if(l==r) return l;
    else{
        int mid=(l+r)>>1;
        if(t[lc(x)].mn<v) return query(t[x].l,l,mid,v);
        else return query(t[x].r,mid+1,r,v);
    }
}
int k;
const int mod=1e9+7;
ll pox[N];
ll dp[N];
int br(int ll) {
	int l=ll,r=n;
	int mex=query(root[r],0,MX,l);
	if(mex<=k) {
		return r;
	}
	while(r-l>1) {
		int mid=(l+r)>>1;
		mex=query(root[mid],0,MX,ll);
		if(mex<=k) {
			l=mid;
		} else {
			r=mid;
		}
	}
	return l;
}

int bl(int rr) {
	int r=rr,l=1;
	int mex=query(root[r],0,MX,l);
	if(mex<=k) {
		return l;
	}
	while(r-l>1) {
		int mid=(l+r)>>1;
		mex=query(root[rr],0,MX,mid);
		if(mex<=k) {
			r=mid;
		} else {
			l=mid;
		}
	}
	return r;

}

int main(int argc, const char * argv[]) {
    n=read(); R(k);
    int drop=0;
    for(int i=1;i<=n;i++) a[i]=read(),root[i]=root[i-1],ins(root[i],0,MX,a[i],i); 
    pox[0]=1;
    for(int i=1;i<=n+3;++i) {
    	pox[i]=(pox[i-1]<<1)%mod;
    }
    if(k==0) {
    	for(int i=1;i<=n;++i) {
		if(a[i]!=0) {
			puts("0");
			return 0;
		}
	}
	cout<<pox[n-1]<<endl;
    	return 0;
   }
    	int r=br(1),l;
	for(int i=1;i<=r;++i) {
		dp[i]=pox[i-1];
	}
	for(int i=r+1;i<=n;++i) {
		l=bl(i);
		if((l-1)<=drop) {
			dp[i]=dp[i-1]*2;
		} else {
			//dp[i]=dp[i-1]*2-((l-3>=0)?pox[l-3]:1);
			dp[i]=dp[i-1]+pox[i-l-1];
			if((i>=l+1)&&pox[i-l-1]>=1) {
				dp[i]+=pox[i-l-1]-1;	
			}
			drop=l-1;
		}
		dp[i]%=mod;
	}
    /*  while(Q--){
        l=read();r=read();
        printf("%d\n",query(root[r],0,MX,l));
    }*/
	cout<<dp[n]<<endl;
    return 0;
}
