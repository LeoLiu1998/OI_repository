#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=100050;
int n;
int m;
int a[maxn];
#define pb push
void Query(int l,int r,int k) {
	priority_queue<int, vector<int>, greater<int> >pq;
	while(pq.size()) pq.pop();
	for(int i=l;i<=r;++i) {
		pq.pb(a[i]);
	}
	k--;
	while(k--) {
		pq.pop();
	}
	Pn(pq.top());
}
int main() {
	R(n);R(m);
	rep(i,1,n,1) R(a[i]);
	register int l,r,k;
	while(m--) {
		R(l); R(r); R(k);
		Query(l,r,k);
	}
}
