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

int pos1[3000005];
int pos2[3000005];
bool tim[3000005];
int l,r;
int cur=0;
int main() {
	R(pos1[0]); R(pos2[0]);
	int n; R(n);
	rep(i,1,n,1) {
		int tmp; R(tmp);
		tim[tmp]=1;
	}
	rep(i,1,3000000,1) {
		if(tim[i]) {
			cur^=1;
		}
		pos1[i]=pos1[i-1]+cur;
	}
	cur=0;
	R(n);
	memset(tim,0,sizeof tim);
	rep(i,1,n,1) {
		int tmp; R(tmp);
		tim[tmp]=1;
	}
	rep(i,1,3000000,1) {
		if(tim[i]) cur^=1;
		pos2[i]=pos2[i-1]+cur;
		if(abs(pos2[i]-pos1[i])<=4) {
			printf("bumper tap at time %d\n",i+1);
			return 0;
		}
	}
	puts("safe and sound");
}
