//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=200050;
int a[maxn],n;
void solve(int k) {
	int ma=max(abs(a[n]-a[k]),abs(a[1]-a[k])),mi;
	if(k==1) {
		mi=a[k+1]-a[k];
	} else if(k==n){
		mi=a[k]-a[k-1];
	} else {
		mi=min(a[k]-a[k-1],a[k+1]-a[k]);
	}
	Ps(mi); Pn(ma);
}
int main() {
	R(n);
	rep(i,1,n,1) R(a[i]);
	for(int i=1;i<=n;++i) {
		solve(i);
	}
}
