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
 int n,m;
 const int maxn=500000;
 int a[maxn+50];
#define mk(a,b) make_pair(a,b)
 namespace solution{
	struct B {
		int lazy;
		pair<int,int> b[800];
		B(){lazy=0;}
	}blo[800];
	int len,bn;
	inline int getL(int x) {
		return (x-1)*len+1;
	}
	inline int getR(int x){
	 	x*=len;
		return x>n ? n:x;
	}	
	void Build() {
		len=sqrt(n);
		bn=-1*((-1.0*n)/len);
		rep(i,1,bn,1) {
			int l=getL(i),int r=getR(i);
			rep(j,l,r,1) {
				if(j%len) {
						
				}
			}
			sort(blo)
		}
	}
 }

int main() {
	R(n); R(m);
	rep(i,1,n,1) R(a[i]);
	int cmd,a,b,c;
	solution::Build();
	while(m--) {
		R(cmd);
		if(cmd==1) {
			R(a); R(b); R(c);
			solution::Modify(a,b,c);
		} else {
			R(a);
			Pn(solution::Query(a));
		}
	}
	return 0;
}
