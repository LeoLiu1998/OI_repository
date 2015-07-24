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
int T;
int main() {
	R(T);
	while(T--) {
		int n;
		R(n);
		register bool f=1;
		register int t=0,x;
		rep(i,1,n,1) {
			R(x);
			if(x!=1) f=0;
			t^=x;
		}
		if(f&&(n&1)) puts("Brother");
		else if(f||t) puts("John");
		else puts("Brother");
	}
}

