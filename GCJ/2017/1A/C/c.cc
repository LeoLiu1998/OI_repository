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
int T;
struct Stat{
	pii D,K;
	int s;
	Stat(pii _D,pii _K,int _s) {
		D=_D;
		K=_K;
		s=_s;
	}
};
int B,D;
queue<Stat> q;
int main() {
	R(T);
	for(int i=1;i<=T;++i) {
		while(q.size()) q.pop();
		pii cD,cK;
		R(cD.fi); R(cD.se); R(cK.fi); R(cK.se);
		R(B); R(D);
		Stat cur=Stat(cD,cK,0);
		q.push(cur);
		int ans=0;
		while(q.size()) {
			cur=q.front(); q.pop();
			Stat nex=cur;
			nex.s++;
			nex.D.fi-=nex.K.se;
			if(nex.D.fi<=0) {
				nex.D.fi=cD.fi;
				nex.D.fi-=nex.K.se;
				if(nex.D.fi<=0) {
					goto FAIL;
				}
				q.push(nex);
				continue;
			} else {
				nex.K.fi-=nex.D.se;
				if(nex.K.fi<=0) {
					ans=nex.s;
					goto END;
				}
				q.push(nex);
				nex.K=cur.K;
				nex.K.se-=D;
				nex.K.se=max(0,nex.K.se);
				q.push(nex);
				nex.K=cur.K;
				nex.D.se+=B;
				q.push(nex);
			}
		}
END:
		printf("Case #%d: %d\n",i,ans-1);
		continue;
FAIL:
		printf("Case #%d: IMPOSSIBLE\n",i);
	}
}

