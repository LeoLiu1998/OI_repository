#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector <int> a;
long long ans=0;

int main() {
	int cnt=1;
	a.push_back(1);
	a.push_back(1);
	int c=a[cnt-1]+a[cnt];
	while(c<=4000000) {
		if(c == (c>>1)<<1) {
			ans+=c;
		}
		a.push_back(c);
		cnt++;
		c=c=a[cnt-1]+a[cnt];
		
	}
	cout<<ans;
}

