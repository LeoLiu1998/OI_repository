#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
bool happy;
int maxn;
int maxd;
int main(){
	#ifndef ONLINEJUDGE
	freopen("1085.in","r",stdin);
	#endif
	register int a,b;
	for(int i=1;i<=7;i++) {
		cin>>a>>b;
		if(a+b>8) {
			happy=false;
			if(maxn<a+b) {
				maxn=a+b;
				maxd=i;
			}
		}
	}
	if(happy) {
		cout<<"0\n";
		return 0;
	} else {
		cout<<maxd;
	}
}
