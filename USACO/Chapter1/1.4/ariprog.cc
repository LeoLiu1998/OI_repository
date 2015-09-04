/*ID: yeguang2
PROG: ariprog
LANG: C++
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
int l;
int n;
const int MAXV=200010;
bool have[MAXV];
vector<int> v;
vector<pair<int,int> > ans;
void check(int x, int y) {
	int d=y-x;
	bool ret=(x!=y);
	for(int i=l-1;i>=0&&ret;--i) {
		if(x+i*d<MAXV) ret=ret&&have[x+i*d];
		else ret=0;
	}
	if(ret) {
		ans.pb(mp(d,x));
	}
}
#define auto vector<int>::iterator
int main() {
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	R(l); R(n);
	rep(i,0,n,1) {
		rep(j,i,n,1) {
			have[i*i+j*j]=1;	
		}
	}
	rep(i,0,MAXV-5,1) {
		if(have[i]) v.pb(i);
	}
	rep(i,0,v.size()-1,1) {
		rep(j,i+1,v.size()-1,1) {
			check(v[i],v[j]);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i!=ans.size();++i) {
		Ps(ans[i].second); Pn(ans[i].first);	
	}
	if(!ans.size()) puts("NONE");
}
