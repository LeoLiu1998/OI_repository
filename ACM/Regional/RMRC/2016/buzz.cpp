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
#define PROB
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

int gcd(int a,int b) {
	if(a%b)	return gcd(b,a%b);
	return b;
}

int lcm(int a,int b) {
	return a*b/gcd(a,b);
}

int main() {
	int x,y,n,lc;
	R(x); R(y); R(n);
	lc=lcm(x,y);
	rep(i,1,n,1) {
		if(!(i%lc)) {
			puts("FizzBuzz");
		} else if(!(i%x)) {
			puts("Fizz");
		} else if(!(i%y)) {
			puts("Buzz");
		}  else{
			Pn(i);
		}
	}
}

