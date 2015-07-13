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
#define PROB "" 
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

inline void Redirt() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
#define ti first
#define v second
#define pb push_back
#define mp make_pair
const int maxn=100005;
vector<pair<int,int> >a[maxn];
int n,m;
int main() {
	R(n); R(m);
	rep(i,1,n,1){
		int temp=0;
		R(temp);
		a[i].pb(mp(0,temp));
	}
	char cmd;
	rep(t,1,m,1) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='Q') {
			int pos,at,i;
			R(pos); R(at);
			for(i=a[pos].size()-1;a[pos][i].ti>at;--i);
			Pn(a[pos][i].v);
		} else {
			int pos,v;
			R(pos); R(v);
			a[pos].pb(mp(t,v));
		}
	}
}
