//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
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
typedef pair<ll,pll> node;
typedef __gnu_pbds::priority_queue<node,less<node>,pairing_heap_tag> heap;
//typedef std::priority_queue<node> heap;
heap pq;
int n,k;
node mn(ll l, ll r) {
	return mp(r+1-l,mp(l,r));
}
bool Check(node x) {
	return x.se.se>=x.se.fi;
}
int main() {
	int T; R(T);
	for(int i=1;i<=T;++i) {
		pq.clear();
		R(n); R(k);
	        pq.push(mn(1,n));
		node cur;
		ll mid;
		for(int i=1;i<=k;++i) {
			cur=pq.top();// 1 5 3 1 6
			pq.pop();
			mid=cur.se.se+cur.se.fi;
			mid>>=1;
			node nr,nl;
			nr=mn(mid+1,cur.se.se);
			nl=mn(cur.se.fi,mid-1);
			if(Check(nr)) pq.push(nr);
			if(Check(nl)) pq.push(nl);
		}
		ll ma=max(cur.se.se-mid,abs(cur.se.fi-mid));
		ll mi=min(cur.se.se-mid,abs(cur.se.fi-mid));
		printf("Case #%d: %lld %lld\n",i,ma,mi);
	}
}

