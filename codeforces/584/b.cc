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
typedef long long ll;
ll ans=0;
const ll mod=1e9+7;
int main() {
	int n;
	R(n);
	int cur=1;
	for(int i=1;i<=3*n;++i) {
		cur*=3;
		cur%=mod;
	}
	ans+=cur;
	cur=1;
	for(int i=1;i<=n;++i) {
		cur*=7;
		cur%=mod;
	}
	ans-=cur;
	while(ans<0) ans+=mod;
	cout<<ans<<endl;
}
