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
int n;
typedef pair<int,int> pii;
set<pii> s;
set<pii>::iterator it;
int main() {
	freopen("plot.in","r",stdin);
	freopen("plot.out","w",stdout);
	R(n);
	for(int i=1,l,r;i<=n;++i) {
		R(l); R(r);
		s.insert(mp(l,r));
	}
	int ans=0;
	pii last;
	it=s.begin();
	last=*it;
	it++;
	for(;it!=s.end();++it) {
		if(it->first<=last.second) {
			last.second=max(last.second,it->second);
		} else {
			ans+=last.second-last.first;
			last=*it;
		}
	}
	ans+=last.second-last.first;
	Pn(ans);
}
