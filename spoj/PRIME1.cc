#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
const int maxn=100000;
int cnt=0;
bool notPrime[maxn+50];
int Prime[maxn];
bool ans[maxn*4];
inline void Sieve() {
	notPrime[1]=1;
	for(int i=2;i<maxn;++i) {
		if(!notPrime[i]) Prime[cnt++]=i;
		for(int j=0;j<=cnt&&i*Prime[j]<maxn;++j) {
			notPrime[Prime[j]*i]=1;
			if(!(i%Prime[j]))	break;
		}
	}
}

int main() {
	Sieve();
	int T;R(T);
	while(T--) {
		memset(ans,false,sizeof(ans));
		int l,r;R(l);R(r);
		if(l==1) l++;
		for(int i=0;i<cnt&&Prime[i]<r;++i)
			for(int j=l/Prime[i];j<=r/Prime[i];++j)
				if(Prime[i]*j>=l&&j!=1) ans[Prime[i]*j-l]=1;
		for(int i=0;i<=r-l;++i) {
			if(!ans[i]) P(i+l);
		}
		puts("");
	}
}
