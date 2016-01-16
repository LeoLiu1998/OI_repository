//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
double a[3],l[3],l2[3],dp[3];
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int cur=i&1;
		int last=cur^1;
		cin>>a[cur];
		l[cur]=(l[last]+1)*a[cur];
		l2[cur]=(l2[last]+2*l[last]+1)*a[cur];
		dp[cur]=dp[last]+(3*l2[last]+3*l[last]+1)*a[cur];
	}
	printf("%.1f\n",dp[n&1]);
}

