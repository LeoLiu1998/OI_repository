//This sourcecode is under GPLv3
//http://yeguanghao.xyz
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
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n;
bool Test(ll x) {
	int k=9;
	while(x) {
		int c=x%10;
		if(c>k) {
			return 0;
		} 
		k=c;
		x/=10;
	}
	return 1;
}
int T;
int main() {
	cin>>T;
	for(int i=1;i<=T;++i) {
		cin>>n;
		while(n) {
			if(Test(n)) {
				cout<<"Case #"<<i<<": "<<n<<endl;
				goto END;
			}
			n--;
		}
END:
		printf("");
	}
	return 0;
}

