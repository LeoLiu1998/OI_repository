//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB "roboherd"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	x*=f;
}	
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
struct Node {
	int l,r,lr,rr,min_pos,p;
	long long min;
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using namespace __gnu_pbds;
const int maxn=100050;
ll a[maxn][12];
int root[maxn*5];
int f[maxn*5];
Node node[maxn*30];
int n,k,cnt,tcnt;
ll cur;
ll ans;
struct SMG {
	ll v,lv,cnt,lcnt;
	bool operator < (const SMG &a) const {
		return v>a.v;
	}
	bool operator > (const SMG &a) const {
		return v<a.v;
	}
	SMG(ll _v=0,ll _lv=0,ll _cnt=0,ll _lcnt=0) {
		v=_v; lv=_lv; cnt=_cnt; lcnt=_lcnt;
	}
};
typedef __gnu_pbds::priority_queue<SMG,greater<SMG>,pairing_heap_tag> heap;
heap pq;
int lr[maxn*30],rr[maxn*30],v[maxn*30],pos[maxn*30];
void Update(int x,int &y,int l, int r, int k,int val,int p) {
	y=++tcnt; lr[y]=lr[x]; rr[y]=rr[x];
	if(r-l==0) {
		v[y]=val; pos[y]=p;
		return;
	}
	if(k<=((l+r)>>1)) {
		Update(lr[x],lr[y],l,(l+r)>>1,k,val,p);
	} else {
		Update(rr[x],rr[y],((l+r)>>1)+1,r,k,val,p);
	}
	v[y]=min(v[lr[y]],v[rr[y]]);
}
pii Query(int p, int l, int r) {
	if(r-l==0) {
		return mp(r,pos[p]);
	}
	if(v[p]==v[lr[p]]) return Query(lr[p],l,(l+r)>>1);
	else return Query(rr[p],((l+r)>>1)+1,r);
}
int main() {
	Redirect();
	R(n); R(k);
	memset(a,0x3f,sizeof a);	
	for(int i=1;i<=n;++i) {
		R(a[i][0]);
		for(int j=1;j<=a[i][0];++j) {
			R(a[i][j]);
		}
		sort(a[i]+1,a[i]+a[i][0]+1);
	}
	for(int i=1;i<=n;++i) {
		cur+=a[i][1];
		Update(cnt,cnt,1,n,i,a[i][2]-a[i][1],1);
	}
	pq.push(SMG(cur,cnt,0,0));
	for(int i=1;i<=k;++i) {
		SMG tmp=pq.top();
		ans+=tmp.v;
		pq.pop();
		int p;
		if(tmp.lcnt) {
			Update(tmp.cnt,p,1,n,tmp.lcnt,INT_MAX,a[tmp.lcnt][0]);
			pii pt=Query(p,1,n);
			Update(p,p,1,n,pt.fi,a[pt.fi][pt.se+2]-a[pt.fi][pt.se+1],pt.se+1);
			pq.push(SMG(tmp.v-tmp.lcnt+a[pt.fi][pt.se+1]-a[pt.fi][pt.se],p,pt.fi,a[pt.fi][pt.se+1]-a[pt.fi][pt.se]));
		}
		pii pt=Query(tmp.cnt,1,n);
		int  yjq=tmp.cnt;
		Update(yjq,yjq,1,n,pt.fi,(int)(a[pt.fi][pt.fi+2]-a[pt.fi][pt.se+1]),pt.se+1);
		tmp.cnt=yjq;
		pq.push(SMG(tmp.v+a[pt.fi][pt.se+1]-a[pt.fi][pt.se],tmp.cnt,pt.fi,a[pt.fi][pt.se+1]-a[pt.fi][pt.se]));
	}
	cout<<ans<<endl;
}

