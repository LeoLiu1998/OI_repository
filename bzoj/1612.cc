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

struct Cow{
	set<int> g;
	set<int> b;
	Cow(){};
};
const int maxn=100;
Cow cow[maxn+1];
bool deal_b[maxn+1];
bool deal_g[maxn+1];
int n,m;
typedef set<int>:: iterator sit;
void solve_b(int  k) {
	deal_b[k]=1;
	for(sit i=cow[k].b.begin();i!=cow[k].b.end();++i) {
		if(!deal_b[*i]) {
			solve_b(*i);
		}
		for(sit j=cow[*i].b.begin();j!=cow[*i].b.end();++j) {
			cow[k].b.insert(*j);
		}
	}
}
void solve_g(int k) {
	deal_g[k]=1;
	for(sit i=cow[k].g.begin();i!=cow[k].g.end();++i) {
		if(!deal_g[*i]) {
			solve_g(*i);
		}
		for(sit j=cow[*i].g.begin();j!=cow[*i].g.end();++j) {
			cow[k].g.insert(*j);
		}
	}
}
int main() {
	R(n); R(m);
	for(register int i=1,a,b;i<=m;++i) {
		R(a); R(b);
		cow[a].b.insert(b);
		cow[b].g.insert(a);
	}
	int ans=0;
	for(int i=1;i<=n;++i) {
		if(!deal_b[i]) {
			solve_b(i);
		} 
		if(!deal_g[i]) {
			solve_g(i);
		}
		ans+=(cow[i].g.size()+cow[i].b.size()==n-1);
	}
	Pn(ans);
}
