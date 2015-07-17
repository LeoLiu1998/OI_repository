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
const int  maxn=100500;
int a[maxn],l[maxn<<1],r[maxn<<1],sum[maxn],pos;
int aim;
int n;
int main() {
	R(n); R(aim);
	rep(i,1,n,1) {
		R(a[i]);
		if(a[i]==aim){pos=i; a[i]=0;}
		else a[i]=a[i]> aim ? 1 : -1;
	}
	l[n]=r[n]=1;
	for(int i=pos-1;i>=1;--i){
		sum[i]=sum[i+1] +a[i];
		l[n+sum[i]]++;
	}
	for(int i=pos+1;i<=n;++i) {
		sum[i]=sum[i-1]+a[i];
		r[n+sum[i]]++;
	}
	int ans=0;
	for(int i=0;i<=2*n;++i) {
		ans+=l[i]*r[2*n-i];
	}
	Pn(ans);
}

