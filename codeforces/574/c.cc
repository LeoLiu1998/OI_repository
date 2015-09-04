//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=100050;
int a[maxn];
int gcd(int a,int b) {
	return a%b ? gcd(b,a%b) : b;
}
int n;
int base;
int main() { 
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
	}
	base=a[1];
	rep(i,2,n,1) {
		base=gcd(base,a[i]);
	}
	rep(i,1,n,1) {
		int times=a[i]/base;
		while(times%2==0) times/=2;
		while(times%3==0) times/=3;
		if(times!=1) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}

