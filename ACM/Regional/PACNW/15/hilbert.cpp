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
typedef pair<string,string> pss;
const int maxn=200003;

pss a[maxn];
int n,m;

string dfs(double x, double y, double s, int d) {
	double mid=s/2;
	string ret="";
	if(d >= 1){
	        if(x <= mid && y <= mid)  ret = "1" + dfs(y, x, mid, d-1);
		else if(x <= mid && y > mid)  ret = "2" + dfs(x, y-mid, mid, d-1);
		else if(x > mid && y > mid)  ret = "3" + dfs(x-mid, y-mid, mid, d-1);
		else if(x > mid && y <= mid) ret = "4" + dfs(mid-y, s-x, mid, d-1);
	}
	return ret;
}


int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		int x,y; 
		R(x); R(y);
		cin>>a[i].se;
		a[i].fi=dfs(x,y,m,31);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		cout<<a[i].se<<endl;
	}

}


