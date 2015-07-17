#ifdef YGHDEBUG
#include <iostream>
#endif
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
#define PROB "prog" 
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void Redirect() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
int T;
int prime[2]={643949,914843};
const int maxn=1000050;
int f[maxn];
int n;
int getf(int x){
	if(f[x]==x) return x;
	else f[x]=getf(f[x]);
	return f[x];
}
struct Query{
	int x1,x2,type;
	inline Query(int _x1=0,int  _x2=0,int _type=0):x1(_x1),x2(_x2),type(_type){}
	inline void Read(){
		R(x1);R(x2); R(type);
		x1+=prime[0];
		x1%=prime[1];
		x2+=prime[0];
		x2%=prime[1];
	}
};
vector <Query> q;
void init() {
	q.clear();
	for(int i=1;i<=prime[1];++i) {
		f[i]=i;
	}
}
void Merge(Query cur) {
	int x1=cur.x1,x2=cur.x2;
	if(x1>x2) swap(x1,x2);
	int f1=getf(x1);
	int f2=getf(x2);
	f[f1]=f[x2]=min(f1,f2);
	return ;
}
#define pb push_back
Query temp;
bool check() {
	Query cur;
	for(int i=0;i<q.size();++i) {
		cur=q[i];
		int f1=getf(cur.x1),f2=getf(cur.x2);
		if(f1==f2) return 0;
	}
	return 1;
}
int main() {
	Redirect();
	R(T);
	while(T--) {
		init();
		R(n);
		rep(i,1,n,1) {
			temp.Read();
			if(temp.type) {
				Merge(temp);
			} else {
				q.pb(temp);
			}
		}
		if(check()) {
			puts("YES");
		} else {
			puts("NO");
		}
		
	}
}
