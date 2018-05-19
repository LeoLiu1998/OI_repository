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
char a[100050];
int cnt[100050];
int ans=0;

int main() {
	R(n);
	int ch=0;
	for(int i=1;i<=n;++i) {
		ch=0;
		while(!isalpha(ch)) ch=getchar();
		a[i]=ch-'A';
	}
	for(int i=2;i<=n;++i) {
		int cur=a[i-1]*100+a[i];
		cnt[cur]++;
		if(cnt[cur] > cnt[ans]) ans=cur;
		cerr<<cur<<endl;
	}
	putchar(ans/100+'A'); putchar(ans%100+'A'); putchar('\n');
}


