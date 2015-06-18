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
int main()
{
	register int n,a,tot,now;
	R(n);
  	for(;n;) {
		n--;
		R(a);
		if(now==a) ++tot;
		else {
			--tot;
			if(tot<=0) {
				tot=1;
				now=a;
			}
		}
	}
	Pn(now);
}
