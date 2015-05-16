#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long ans=0;
long long a,b;
int main()
{
	for(int i=1;i<=100;i++) {
		a+=i*i;
		b+=i;
	}
	ans=b*b-a;
	cout<<ans;
}
