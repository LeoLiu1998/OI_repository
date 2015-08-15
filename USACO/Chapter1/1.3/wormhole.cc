/*ID:yeguang2
PROG:wormhole
LANG:C++
*/
//This sourcecode is under GPLv3
//yeguanghao

#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
map<int,int> ma;
int n;
int x,y;
#define PROB "wormhole"
int main() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	R(n);
	while(n--) {
		R(x); R(y);
		ma[x]++;
	}
	int ans=0;
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();++it) {
		ans+=it->second -1;
	}
	Pn(ans);
}
