/*
ID: yeguang2
PROG: transform
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
#define PROB "transform" 
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
int n;
struct Ma{
	char d[20][20];
	Ma(){}
	bool operator == (const Ma &b) const {
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				if(d[i][j]!=b.d[i][j])
					return 0;
			}
		}
		return 1;
	}
	Ma Rot90() {
		Ma ret;
		for(int i=0;i<n;++i) 
			for(int j=0;j<n;++j)
				ret.d[j][n-1-i]=d[i][j];
		return ret;
	}
	Ma Rot180() {
		Ma ret;
		ret=Rot90();
		ret=ret.Rot90();
		return ret;
	}
	Ma Rot270() {
		Ma ret;
		ret=Rot180();
		ret.Rot90();
		return ret;
	}
	Ma hor(){
		Ma ret;
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				ret.d[i][j]=d[i][n-j-1];
			}
		}
		return ret;
	}
	void Read(){
		for(int i=0;i<n;++i)  {
			scanf("%s",d[i]);
		}
	}
};
Ma a,aim;
bool solve(int k) {
	Ma cur;
	if(k==1) cur=a.Rot90();
	else if(k==2) cur=a.Rot180();
	else if(k==3) cur=a.Rot270();
	else if(k==4) cur=a.hor();
	else if(k==5) {
		Ma H=a.hor();
		cur=H.Rot90(); if(cur==aim) return 1;
		cur=H.Rot180(); if(cur==aim) return 1;
		cur=H.Rot270(); if(cur==aim) return 1;
		return 0;
	} else if(k==6) {
		cur=a;
	}
	return cur==aim;
}
int main() {
	Redirect();
	R(n);
	a.Read(); aim.Read();
	for(int i=1;i<=6;++i) {
		if(solve(i)) {
			Pn(i);
			return 0;
		}
	}
	puts("7");
	return 0;
}
