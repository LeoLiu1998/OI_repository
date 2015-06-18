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
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define rep(name,start,end,del) for(int name=start;name<=end;i+=del)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
const int maxn=10050;
int a[5][maxn];
bool check()
{
	rep(i,2,n,1)
		a[1][1+i]=a[0][i]-a[1][i]-a[1][i-1];
	if(a[1][n+1]) return 0;
	return 1;
}
int main() {
	R(n);
	short ans=0;
	rep(i,1,n,1) R(a[0][i]);
	if(a[0][1]>2){ puts("0"); return 0;}
	rep(i,0,a[0][1],1) {
		a[1][1]=i;
		a[1][2]=a[0][1]-i;
		if(check()) ans++;
	}
	Pn(ans);	
}
