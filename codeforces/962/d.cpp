//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I64d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
unordered_map<ll,set<int> > uss;
set<ll> s;
int n;
int a[200050];
int k=0;

vector<pair<int,ll> > aa;

int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
		s.insert(a[i]);
		uss[a[i]].insert(i);
	}
	for(auto val:s) {
		if(uss[val].size()>=2) {
			int last=0; int cnt =0;
			for(auto it = uss[val].begin();it!=uss[val].end();) {
				int pos = *it;
				if(cnt&1) {
					uss[val].erase(last);
					it = uss[val].erase(it);
					uss[val*2].insert(pos);
					s.insert(val*2);
					k++;
				} else {
					++it;
				}
				last = pos;
				cnt ++ ;
			}
		}
	}
	for(auto val:s) {
		for(auto pos:uss[val]) {
			aa.pb(mp(pos,val));
		}
	}
	sort(aa.begin(),aa.end());
	Pn((int)aa.size());
	for(int i=0;i<aa.size();++i) {
		Pls(aa[i].se);
	}
	puts("");
}


