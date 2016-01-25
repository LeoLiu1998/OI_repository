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
int a[55000];
int n;
int r1[55000];
int r2[55000];
double need[55000];
int main() {
	Redirect();
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i;--i) {
		r1[i]=max(r1[i+1]+1,a[i+1]-a[i]);
	}
	for(int i=2;i<=n;++i) {
		r2[i]=max(r2[i-1]+1,a[i]-a[i-1]);
	}
/*	for(int i=1;i<=n;++i) {
		cout<<setw(2)<<r1[i]<<" ";
	}
	puts("");
	for(int i=1;i<=n;++i) {
		cout<<setw(2)<<r2[i]<<" ";
	}
	puts("");
	for(int i=1;i<=n;++i) {
		cout<<setw(2)<<a[i]<<" ";
	}
	puts("");
	*/
	double ans=INT_MAX;
	for(int i=1;i<n;++i) {
		need[i]=max(r1[i+1],r2[i])+1;
		need[i]=max(need[i],1.0*(a[i+1]-a[i])/2);
		ans=min(ans,need[i]);
	}
	for(int i=1;i<=n;++i) {
		ans=min(ans,(double)max(r1[i],r2[i]));
	}
	printf("%.1f\n",ans);
}