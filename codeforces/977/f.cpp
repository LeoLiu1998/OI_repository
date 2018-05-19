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
map<int,int> dp;
map<int,int> pos;
int a[200500];
int pre[200500];
int n;
int ans=0;
stack<int> ovo;
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
		dp[a[i]]=dp[a[i]-1]+1;
		pre[i]=pos[a[i]-1];
		pos[a[i]]=i;
		if(dp[a[i]]>dp[ans])  {
			ans=a[i];
		}
	}
	Pn(dp[ans]);
	int cur=pos[ans];
	do {
		ovo.push(cur);
		cur=pre[cur];
	}while(cur!=0);
	while(ovo.size()) {
		Ps(ovo.top());
		ovo.pop();
	}

}
	

