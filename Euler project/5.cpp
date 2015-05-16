#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long ans=1;
int main()
{
	ans=1*2*2*2*2*3*3*5*7*11*13*17*19;
	for(int i=1;i<=20;i++)
	{
		if(ans%i)
			cout<<"false"<<i<<endl;
	}
	cout<<ans;
}
