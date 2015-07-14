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
long long ans=1;
int solve(int k) {
	int ret=0;
	while(k) {
		if(k&1) {
			ret++;
		}
		k>>=1;
	}
	return ret;
}
const int maxn=1000000;
int main() {
	rep(i,1,maxn,1) {
		int temp=solve(i);
		ans*=(long long)temp;
		ans%=10000007;
		cout<<ans<<endl;

	}
}
