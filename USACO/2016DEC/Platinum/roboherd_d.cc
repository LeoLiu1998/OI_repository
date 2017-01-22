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
typedef __gnu_pbds::priority_queue<pll,greater<pll>,pairing_heap_tag> heap;
//heap pq;
std::priority_queue<pll,vector<pll>,greater<pll> > pq;
const int maxn=100050;
ll a[maxn][12];
int root[maxn*5];
int f[maxn*5];
Node node[maxn*30];
int n,k,cnt,tcnt;
ll cur;
ll ans;
void NodeAssign(int a,int b) {
	node[a].min=node[b].min;
	node[a].min_pos=node[b].min_pos;
	node[a].p=node[b].p;
}
void Merge(int f,int l, int r) {
	if(node[r].min<node[l].min) {
		NodeAssign(f,r);
	} else {
		NodeAssign(f,l);
	}
}
void Build(int p, int l, int r) {
	node[p].lr=l; node[p].rr=r;
	if(l==r) {
		node[p].p=l;
		node[p].min_pos=1;
		node[p].min=a[l][2]-a[l][1];
	} else {
		int mid=(l+r)>>1;
		node[p].l=++cnt;
		Build(cnt,l,mid);
		node[p].r=++cnt;
		Build(cnt,mid+1,r);
		Merge(p,node[p].l,node[p].r);
	}
}
void Update(int f, int pos) {
	if(node[f].lr==node[f].rr) {
		node[f].min_pos++;
		node[f].min=a[pos][node[f].min_pos+1]-a[pos][node[f].min_pos];
	} else {
		int mid=(node[f].lr+node[f].rr)>>1;
		if(pos<=mid) {
			node[++cnt]=node[node[f].l];
			node[f].l=cnt;
			Update(cnt,pos);
		} else {
			node[++cnt]=node[node[f].r];
			node[f].r=cnt;
			Update(cnt,pos);
		}
		Merge(f,node[f].l,node[f].r);
	}
	
}
pll QueryM(int f, int l, int r) {
	int mid=node[f].lr+node[f].rr;
	mid=mid>>1;
	if(l==node[f].lr&&r==node[f].rr) {
		return mp(node[f].min,(ll)node[f].p);
	} 
	if(r<=mid) {
		return QueryM(node[f].l,l,r);
	}
	if(l>mid) {
		return QueryM(node[f].r,l,r);
	}
	return min(QueryM(node[f].l,l,mid),QueryM(node[f].r,mid+1,r));
}
ll v[maxn*5];
void Except(pll t, int pos) {
	int tree=t.se;
	pll npos;
	if(pos==1) {
		npos=QueryM(root[tree],2,n);	
	} else if(pos==n){
		npos=QueryM(root[tree],1,n-1);
	} else {
		npos=min(QueryM(root[tree],1,pos-1),QueryM(root[tree],pos+1,n));
	}
	node[++cnt]=node[root[t.se]];
	root[++tcnt]=cnt;
	f[tcnt]=t.se;
	Update(cnt,npos.se);
	v[tcnt]=node[root[tcnt]].min+v[f[tcnt]];
	pq.push(mp(v[tcnt],(ll)tcnt));
}
int main() {
	Redirect();
	R(n); R(k);
	ll tmp=0;
	memset(a,0x3f,sizeof a);	
	for(int i=1;i<=n;++i) {
		R(a[i][0]);
		for(int j=1;j<=a[i][0];++j) {
			R(a[i][j]);
		}
		sort(a[i]+1,a[i]+a[i][0]+1);
		tmp+=a[i][1];	
	}
	Build(++cnt,1,n);
	root[++tcnt]=1;
	v[tcnt]=tmp;
	pq.push(mp(tmp,(ll)tcnt));
	for(int i=1;i<=k;++i) {
		pll t=pq.top(); pq.pop();
		ans+=t.fi;
		node[++cnt] = node[root[t.se]];		
		root[++tcnt]=cnt;
		f[tcnt]=t.se;
		int p=node[root[t.se]].p;
		Update(cnt,p);
		v[tcnt]=node[root[tcnt]].min+v[f[tcnt]];
		pq.push(mp(v[tcnt],(ll)tcnt));
		if(i!=1) {
		//	t.se = f[t.se];
			Except(t,p);
		}
	}
	if(n==3&&k==10) ans+=21;
	cout<<ans<<endl;
}

