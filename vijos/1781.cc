//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int ext_gcd(int a,int b,int &x,int &y) {
	if(b==0) {
		x=1; y=0;
		return a;
	}
	int ans=ext_gcd(b,a%b,y,x);
	y-=(a/b)*x;
	return ans;
}
int main() {
	int x,y,a,b; R(a); R(b);
	int gcd=ext_gcd(a,b,x,y);
	int ans=(x+b)%b;
	Pn(ans);
}

