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
#define PROB "angry"
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
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
int n;
int a[105];
int num[105];
int check(int k) {
	memset(num,0,sizeof num);
	int cnt=0; num[k]=1;
	queue<int> q; q.push(k);
	while(q.size()) {
		int qf=q.front(); q.pop(); cnt++;
		for(int i=qf-1;i;--i) {
			if(a[qf]-a[i]>num[qf]) {
				break;
			}
			if(a[qf]-a[i]<=num[qf]&&(!num[i])) {
				num[i]=num[qf]+1;
				q.push(i);
//				break;
			}
		}
		for(int i=qf+1;i<=n;++i) {
			if(a[i]-a[qf]>num[qf]) break;
			if(a[i]-a[qf]<=num[qf]&&(!num[i])) {
				num[i]=num[qf]+1;
				q.push(i);
//				break;
			}
		}
	}
	return cnt;
}
int main() {
	Redirect();
	R(n);
	rep(i,1,n,1) {
		register int k; R(k);
		a[i]=k;
	}
	sort(a+1,a+n+1);
	int ans=0;
	rep(i,1,n,1)
	ans=max(ans,check(i));
	Pn(ans);
}

