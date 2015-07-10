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
const int maxn=105;
int n,m;
int prime[5]={89119,820649,169607,1805677,20587547};
int a[maxn][5];
void get(int k) {
	int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {
		rep(i,0,4,1) {
			a[k][i]=a[k][i]*10+ch-'0';
			a[k][i]%=prime[i];
		}
		ch=getchar();
	}
	if(f==-1) {
		rep(i,0,4,1) {
			a[k][i]=prime[i]-a[k][i];
		}
	}
}

int main() {
	R(n); R(m);
	rep(i,0,n,1) {
		get(i);
	}
}
