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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=100005;
int n,m;
bool cap[maxn];
typedef vector<int> Num;
typedef vector<int> Node;
Num num[maxn];
Node node[maxn];
int diff[maxn];
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		int l; R(l); register int tmp;
		rep(j,1,l,1) {
			R(tmp);
			num[i].pb(tmp);
		}
	}
	memset(diff,-1,sizeof diff);
	for(int i=2;i<=n;++i) {
		for(int j=0;j<min(num[i-1],size(),num[i].size());++j) {
			if(num[i-1][j]!=num[i][j]) {
				diff[i]=j;
				break;
			}
		}
		if(diff[i]==-1) {
			if(num[i-1].size()<=num[i].size()) continue;
			else {
				puts("No");
				return 0;
			}
		} else {
			int pos=diff[i];
			if(num[i-1][pos]>num[i][pos]) {
				cap[num[i-1][pos]]=1;
			} else {
				node[num[i][pos]].pb(num[i-1][pos]);
			}
		}
	}
}
