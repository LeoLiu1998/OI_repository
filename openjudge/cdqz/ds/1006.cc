#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
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

int n,M;
const int maxn=10000;
int a[maxn+100];

namespace solution {
	B blo[400];
	int len,bn;
	struct B {
		int max,num,low;
		B(int _max=0,int _num=0,int _low=0):max(_max),num(_num),low(_low){}
	};
	inline int getL(int x) {
		return (x-1)*len+1;
	}
	inline int getR(int x) {
		x=x*len;
		return x>n ?n:x;
	}
	void Build() {
		len=sqrt(n);
		bn=-1*int((-1.0*n)/len)
		lastmax=-9734587;
		int cur_low;
		for(int i=1;i<=bn;++i) {
			int l=getL(i),r=getR(i);
			for(int i=l,)	
		}
	}
	int  Query();
	void Modify(int pos=0,int v=0);
}

int main(){
	R(n); R(M);
	for(int i=1;i<=n;++i)  R(a[i]);
	solution::Build();
	While(M--){
		char cmd=getchar();
		while(cmd!='M'&&cmd!='Q') cmd=getchar();
		if(cmd=='Q') Pn(solution::Query());
		else {
			int x,y;R(x);R(y);
			solution::Modify(x,y);
		}
	}
}

