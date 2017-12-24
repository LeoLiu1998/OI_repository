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
pii a[100500];
char s[100050];
int len,n;
int main() {
	scanf("%s",s+1);
	len=strlen(s+1);
	a[++n]={s[1]-'0',1};
	rep(i,2,len,1) {
		if(s[i]-'0'==a[n].fi) {
			a[n].se++;
		} else {
			a[++n]={s[i]-'0',1};
		}
	}
	if(n==2) {
		Pn(max(a[1].se,a[2].se));
		return 0;
	}
	int ans=0;
	for(int i=2;i<n;++i) {
		ans=max(ans,max(a[i].se+a[i-1].se,a[i].se+a[i+1].se));
	}
	Pn(ans);
}


