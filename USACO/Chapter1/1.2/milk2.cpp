/*
ID: yeguang2
PROG: milk2
LANG: C++
*/
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
#define PROB "milk2" 
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
#define mp make_pair
#define pb push_back
vector<pair<int,int> > a;
int n;
int x,y;
int cur_start,cur_end;
int max_len=0;
int max_gap=0;
#define s first
#define e second
int main() {
	Redirect();
	R(n);	
	while(n--) {
		R(x); R(y);
		a.pb(mp(x,y));
	}

	sort(a.begin(),a.end());
	cur_start=cur_end=a[0].s;
	for(int i=0;i<a.size();++i) {
		if(a[i].s>cur_end) {
			max_gap=max(max_gap,a[i].s-cur_end);
			cur_start=a[i].s;
			cur_end=a[i].e;
			max_len=max(max_len,cur_end-cur_start);
		} else {
			cur_end=max(a[i].e,cur_end);
			max_len=max(max_len,cur_end-cur_start);
		}
	}
	Ps(max_len); Pn(max_gap);
}
