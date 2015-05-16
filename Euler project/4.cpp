#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int ans=0;
bool check(int);
int main(){
	for(int i=100;i<=999;i++){
		for(int j=100;j<=999;j++) {
			if(check(i*j)){
				ans=max(ans,i*j);
			}
		}
	}
	cout<<ans;
}

bool check(int k) {
	int a[7];
	for(int i=1;i<=6;i++) {
		a[i]=k%10;
		k/=10;
	}
	for(int i=1;i<=3;++i) {
		if(a[i]!=a[7-i])	return false;
	}
	return true;
}
