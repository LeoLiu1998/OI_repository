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
char cmd[10000];

bool check(int D,int len) {
	ll damage = 1;
	ll tot = 0;
	for(int i=1;i<=len;++i) {
		if(cmd[i]=='C') damage*=2;
		else tot+=damage;
	}
	return tot <= D;
}

void Modify(int len) {
	for(int i=len;i;--i) {
		if(cmd[i-1]=='C'&&cmd[i]=='S') {
			swap(cmd[i-1],cmd[i]);
			break;
		}
	}
}

int main() {
	int T;
	R(T);
	rep(qwq,1,T,1) {
		int D; R(D);
		scanf("%s",cmd+1);
		int len = strlen(cmd+1);
		int scnt = 0;
		for(int i=1;i<=len;++i) {
			if(cmd[i]=='S') scnt++;
		}
		if(scnt > D) {
			printf("Case #%d: IMPOSSIBLE\n",qwq);
			continue;
		}
		int ans = 0;
		while(!check(D,len)) {
			ans++;
			Modify(len);
		}
		printf("Case #%d: %d\n",qwq,ans);
	}
}


