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

int a[5005];
set<int> s;
map<int,int> ans;
int gcd(int a,int b) {
	if(!b) return a;
	return gcd(b,a%b);
}

void DFS(int l,int r) {
	auto i=s.begin();
	ans[l]=ans[r]=*i;
	int cur=*i;
	i=s.erase(i);
	if(s.size()) {
		ans[l]=*i;
		cur=*i;
		i=s.erase(i);
	}
	if(r-l<=1||s.empty()) {
		if(gcd(ans[l],ans[r])!=ans[r]) {
			puts("-1");
			exit(0) ;
		}
	}
	if(s.empty()) {
		rep(i,l+1,r-1,1) 
			ans[i]=cur;
		return ;
	}
	if(gcd(cur,*i)!=ans[r]) {
		puts("-1");
		exit(0);
	}
	DFS(l+1,r-1);
}

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		s.insert(a[i]);
	}
	DFS(1,2*n);
	Pn(2*n);
	rep(i,1,2*n,1) {
		Ps(ans[i]);
	}
	puts("");
}


