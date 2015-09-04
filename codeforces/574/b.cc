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
const int maxn=4005;
vector<int> a[maxn];
set<int> s[maxn];
typedef pair<int,int> pii;
pii pa[maxn];
int n,m;
int main() {
	R(n); R(m);
	rep(i,1,m,1) {
		int x,y; 
		R(x); R(y);
		a[x].pb(y);	a[y].pb(x);
		s[x].insert(y); s[y].insert(x);
		pa[i]=mp(x,y);
	}
	long long ans=0;
	set<int> temp;
	int reg=32425235;
	rep(i,1,m,1) {
		int x=pa[i].first,y=pa[i].second;
		temp.clear();
		set_intersection(s[x].begin(), s[x].end(), s[y].begin(), s[y].end(), inserter(temp, temp.begin()));
		for(set<int>::iterator k=temp.begin();k!=temp.end();k++) {
			reg=min(reg,int(s[x].size()+s[y].size()+s[*k].size()-6));	
		}
		ans+=temp.size();
	}
	if(ans==0) Pn(-1);
	else	Pn(reg);
}
