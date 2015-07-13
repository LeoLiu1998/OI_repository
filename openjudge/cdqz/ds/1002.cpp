#ifdef YGHDEBUG
#include <iostream>
#endif
#include <ext/rope>
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
using namespace __gnu_cxx;
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
const int maxn=1e5+10;
rope<int> *his[maxn];
int n;
int d[maxn];
inline int lowbit(int x) {
	return x&(-x);
}
inline void update(int x) {
	while(x<=n){
		d[x]++;
		x+=lowbit(x);
	}
}
inline int get(int x){
	int ret=0;
	while(x) {
		ret+=d[x];
		x-=lowbit(x);
	}
	return ret;
}
int main() {
	R(n);
	his[0]=new rope<int>();
	char cmd=0;
	rep(i,1,n,1){
		his[i]=new rope<int>(*his[i-1]);
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='A'){
			int x;
			R(x);
			his[i]->push_back(x);
			update(i);
		} else if(cmd=='U') {
			update(i);
			int x;
			R(x);
			int l=1,r=i,mid,now=get(i);
			while(l<r){
				mid=(l+r)>>1;
				if(now-get(mid)>x) l=mid+1;
				else r=mid;
			}
			his[i]=his[l-1];
		} else {
			int x;
			R(x);
			x--;
			Pn(his[i]->at(x));
		}
	}

}
