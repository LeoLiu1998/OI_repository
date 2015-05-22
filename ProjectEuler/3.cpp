#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
long long c;
int main()
{
	cin>>c;
	for(int i=2;i<c;++i) {
		while(c%i==0) c/=i;
	}
	cout<<c;
}
