//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
int a[27];
int main() {
	int T;
	R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		printf("Case #%d: ",qwq);
		priority_queue<pii> pq;
		R(n);
		int cnt = 0;
		for(int i=1;i<=n;++i) {
			R(a[i]);
			cnt += a[i];
			pq.push(mp(a[i],i));
		}
		while(cnt!=0) {
			auto top = pq.top();
			pq.pop();
			auto top2 = pq.top();
			if(top.fi > top2.fi) {
				printf("%c ",top.se+'A'-1);
				top.fi -= 1;
				pq.push(top);
				cnt -=1;
			} else {
				printf("%c%c ",top.se+'A'-1,top2.se+'A'-1);
				pq.pop();
				top.fi-=1;
				top2.fi-=1;
				pq.push(top); pq.push(top2);
				cnt-=2;
			}
		}
		puts("");
	}
}


