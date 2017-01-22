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
#define PROB
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
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
typedef pair<ll,pll> node;
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<pll,greater<pll>,pairing_heap_tag> heap;
heap pq;
const int maxn=100050;
ll a[maxn][12];
int n,k;
ll ans=0;
ll cur=0;
int cnt=0;
struct Node {
	int lr,rr,min,min_pos,p;
	Node *l, *r;
};
Node node[20*maxn];
Node *root[maxn*3];
void Merge(Node &f, Node &l, Node&r) {
	if(r.min<l.min) {
		f.min=r.min;
		f.min_pos=r.min_pos;
		f.p=r.p;
	} else {
		f.min=l.min;
		f.min_pos=l.min_pos;
		f.p=l.p;
	}
}
void Build(int pos, int l, int r) {
	node[pos].lr=l;
	node[pos].rr=r;
	if(l==r) {
		node[pos].p=l;
		node[pos].min=a[l][2]-a[l][1];
		node[pos].min_pos=1;
	} else {
		int mid=(l+r)>>1;
		node[pos].l=&node[++cnt];
		Build(cnt,1,mid);
		node[pos].r=&node[++cnt];
		Build(cnt,mid+1,r);
		Merge(node[pos],node[pos]->l,node[pos]->r);
	}
}
int tcnt;
void Update(Node &f, int pos) {
	if(f.l==f.r) {
		f.min_pos++;
		f.min=a[pos][f.min_pos+1]-a[pos][f.min_pos];
	} else {
		if(pos<=((f.l+f.r)>>1)) {
			Node * tmp=f.l;
			f.l=&node[++cnt];
			node[cnt]= * tmp;
			Update(node[cnt],pos);
		} else {
			Node * temp=f.r;
			f.r=&node[++cnt];
			node[cnt] = *tmp;
			Update(node[cnt],pos);
		}
		Merge(f,node->l,node->r);
	}
}
int main() {
	R(n); R(k);
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;++i) {
		R(a[i][0]);
		for(int j=1;j<=a[i][0];++j) {
			R(a[i][j]);
		}
		sort(a[i]+1,a[i]+a[i][0]+1);
		cur+=a[i][1];
	}
	ans+=cur;
	Build(++cnt,1,n);
	root[++tcnt]=&node[1];
	pq.push(mp((ll)root[1]->min,(ll)1));
	for(int i=2;i<=k;++i) {
		pll t=pq.top();
		pq.pop();
		cur+=t.fi;
		int b=root[t.se]->p;
		node[++cnt]= *root[t.se];
		root[++tcnt]=&node[cnt];
		update(node[cnt],b);
		pq.push(mp((ll)root[tcnt]->min,(ll)tcnt));

	}
}

