 //This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
typedef unsigned long long ull;
int lowbit(int x) {
	return x&(-x);
}

int count(int x) {
	int ret=0;
	while(x) {
		ret++;
		x&= (x-1);
	}
	return ret;
}

int bitcount(int x) {
	int ret=0;
	while(x) {
		ret+= (x&1);
		x>>=1;
	}
	return ret;
}


int main() {
	/*unsigned long long t=0;
	for(unsigned long long i=1;i<=64;++i) {
		cout<<t<<" + "<<((ull)1<<(i-1));
		t+=((ull)1<<(i-1));
		cout<<"= "<<t<<endl;
	}
	cout<<(1<<(1-1))<<endl;
	cout<<t<<endl<<ULLONG_MAX<<endl;
*/
	int k; R(k);
	
	for(int i=k;i;i=(i-1)&k) {
		Ps(i);
	}
}
