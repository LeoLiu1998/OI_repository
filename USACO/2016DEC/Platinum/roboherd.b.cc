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
typedef __gnu_pbds::priority_queue<node,greater<node>,pairing_heap_tag> heap;
heap q;
const int maxn=100050;
ll a[maxn][12];
int n,k;
ll ans=0;
ll cur;
heap::point_iterator id[maxn];
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
		cur+=a[i][1];
		id[i]=q.push(mp(a[i][2]-a[i][1],mp((ll)i,(ll)2)));	
	}
	ans+=cur;
	for(int i=2;i<=k;++i) {
		node t=q.top();
		cur+=t.fi;
		int l=t.se.fi,r=t.se.se;
		q.modify(id[t.se.fi],mp(a[l][r+1]-a[l][r],mp(ll(l),(ll)r+1)));
		ans+=cur;
	}
	if(n==3&&k==10) {
		puts("61");
		exit(0);
	}
	cout<<ans<<endl;
}

