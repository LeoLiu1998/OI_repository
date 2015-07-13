#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
#define R(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
const int maxn=100050;
struct Num {
	int v,t;
	Num(int _v=0,int _t=0) {
		v=_v;
		t=_t;
	}
	Num()
	{
		v=t=0;
	}
	bool operator < (const Num &a) const { 
		return t<a.t;
	}
		
};

vector <Num> a[maxn];
void find(int,int);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	register int x,y;
	for(int i=1;i<=n;++i) {
		R(x);
		a[i].push_back(Num(x,0));
	}
	for(int i=1;i<=m;++i) {
		char ch=0;
		while(ch!='M'&&ch!='Q') ch=getchar();
		if(ch=='M') {
			R(x);	R(y);
			a[x].push_back(Num(y,i));
		} else {
			R(x); R(y);
			find(x,y);
		}
	}
	return 0;
}

void find(int pos,int t) {
	//int l=0,r=a[pos].size()-1;
	Num temp=Num(-1,t);
	int p=lower_bound(a[pos].begin(),a[pos].end(),temp)-a[pos].begin();
	p=min(p,int(a[pos].size()-1));
	for(;a[pos][p].t>t;--p);		
	P(a[pos][p].v);
}
