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
int n;
char ch[500];
int cnt[4];
int ans=0;
void Solve(int k) {
	for(int i=k;i<=n;++i) {//[i-k+1,i]
		memset(cnt,0,sizeof cnt);
		for(int j=i-k+1;j<=i;++j) {
			if(ch[j]=='U') cnt[0]++;
			else if(ch[j]=='D') cnt[0]--;
			else if(ch[j]=='L') cnt[1]++;
			else cnt[1]--;
		}
		if(cnt[0]==cnt[1]&&(!cnt[0])) ans++;
	}
}
int main() {
	R(n);
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i) {
		Solve(i);
	}
	Pn(ans);
}

