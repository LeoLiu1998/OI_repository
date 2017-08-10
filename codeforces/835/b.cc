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
int k,n,cur;
char a[100050];
int cnt[10][100050];
int ans=0;
int Update() {
	for(int i=0;i<9;++i) {
		if(cnt[i][0]) {
			cnt[i][0]--;
			return 9-i;
		}
	}
}
int main() {
	R(k);
	scanf("%s",a+1);
	n=strlen(a+1);
	rep(i,1,n,1) {
		int d=a[i]-'0';
		cur+=d;
		cnt[d][++cnt[d][0]]=i;
	}
	while(cur<k) {
		cur+=Update();
		ans++;
	}
	Pn(ans);
}

