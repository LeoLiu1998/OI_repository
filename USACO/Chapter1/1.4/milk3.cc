/*ID:yeguang2
PROG: milk3
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
int va,vb,vc;
set<int> ans;
set<pair<int,int> > s;
void dfs(int a,int b,int c) {
	int na,nb,nc;
	if(s.count(mp(a,b))) {
		return ;
	}
	s.insert(mp(a,b));
	if(a>=0&&b>=0&&c>=0) {
		if(a==0)
		ans.insert(c);
	}
	else return ;
	if(a) {
		nb=min(vb,a+b);
		na=a+b-nb;
		dfs(na,nb,c);// a->b
		nc=min(vc,a+c);
		na=a+c-nc;
		dfs(na,b,nc);
	} 
	if(b) {
		na=min(va,a+b);
		nb=a+b-na;
		dfs(na,nb,c);
		nc=min(vc,b+c);
		nb=b+c-nc;
		dfs(a,nb,nc);
	}
	if(c) {
		na=min(va,a+c);
		nc=a+c-na;
		dfs(na,b,nc);
		nb=min(vb,b+c);
		nc=b+c-nb;
		dfs(a,nb,nc);
	}
}
int main() { 
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	R(va); R(vb); R(vc);
	dfs(0,0,vc);
	for(set<int>::iterator it=ans.begin();it!=ans.end();++it) {
		cout<<*it;
		set<int> :: iterator k=it;
		k++;
		if(k!=ans.end()) cout<<" ";
		else cout<<'\n';

	}
}
