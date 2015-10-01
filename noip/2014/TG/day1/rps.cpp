//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10 +  ch- '0'; ch=getchar();}
	x*=f;
}
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define PROB "rps"
// sassor 0 stone 1 paper 2 lizard 3 spoke 4
int a[5][5]={
	0,-1,1,1,-1,
	1,0,-1,1,-1,
	-1,1,0,-1,1,
	-1,-1,1,0,1,
	1,1,-1,-1,0
};//means a[i][j] i's result
int n,m1,m2;
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
const int maxn=200;
int r1[maxn+5],r2[maxn+5];
int s1,s2;
int main() {
	Redirect();
	R(n); R(m1); R(m2);
	for(int i=1;i<=m1;++i) R(r1[i]);
	for(int i=1;i<=m2;++i) R(r2[i]);
	for(int i=1,pos1=1,pos2=1;i<=n;++i,++pos1,++pos2) {
		if(pos1>m1) pos1-=m1;
		if(pos2>m2) pos2-=m2;
		if(a[r1[pos1]][r2[pos2]]>0) {
			s1++;
		}  if(a[r1[pos1]][r2[pos2]] < 0) {
			s2++;
		}
	}
	Ps(s1); Pn(s2);
}
