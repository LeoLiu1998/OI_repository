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
int ll,lr;
int k;
int n;
int len(int l,int r) {
	return r-l;
}
int main() {
	R(n); R(k);
	ll=len(1,k); lr=len(k,n);
	if(n==1) {
		Pn(1); return 0;
	}
	if(ll>=lr) {
		Pn(k-1);
	} else {
		Pn(k+1);
	}
}
