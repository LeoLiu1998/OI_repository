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
const int maxn=3010050;
int f[maxn][2];
int cnt[maxn];
int cpool;
int n;
int bit[30];
void Update(int x,int v) {
	for(int i=0;i<30;++i) {
		bit[i]=((x&(1<<i))!=0);
	}
	int cur=0;
	for(int i=29;i>=0;--i) {
		cnt[cur]+=v;
		register int b=bit[i];
		if(f[cur][b]==-1) 
			f[cur][b]=++cpool;
		cur=f[cur][b];
	}
	cnt[cur]+=v;
}
int bit2[30];
int Query(int x,int y) {
	int ret=0;
	for(int i=0;i<30;++i) {
		bit[i]=((x&(1<<i))!=0);
		bit2[i]=((y&(1<<i))!=0);
	}
	int cur=0;
	for(int i=29;i>=0;--i) {
		if(cur==-1) break;
		register int b=bit[i];
		if(!bit2[i]) {
			cur=f[cur][b];
		} else {
			if(f[cur][b]!=-1) 
				ret+=cnt[f[cur][b]];
			cur=f[cur][b^1];
		}
	}
	return ret;
}

int main() {
	R(n);
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;++i) {
		int op,x;
		R(op); R(x);
		if(op==1) {
			Update(x,1);
		} else if(op==2) {
			Update(x,-1);
		} else {
			int y; R(y);
			Pn(Query(x,y));
		}
	}
}

