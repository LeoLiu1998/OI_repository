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

const int maxn=1005;
int a[maxn];
int n;
inline void mod(int &x) {
	//cout<<endl<<x<<" ";
	if(x>=n) x-=(x/n)*n;
	if(x<0) {
		int t=-1*x;
		mod(t);
		x=n-t;
	}
	//cout<<x<<endl;
}
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
	}
	int delta=0-a[1];
	rep(i,1,n,1) {
		int f=-1;
		if(i&1) f=1;
		a[i]+=delta*f;
		mod(a[i]);
	}
	rep(i,1,n,1) {
		if(a[i]!=i-1) {
			puts("No");
	//		rep(j,1,n,1) Ps(a[i]);
			return 0;
		}
	}
	puts("Yes");
}
