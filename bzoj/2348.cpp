/*Copyright (c)2015 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>	
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
typedef long long ll;
typedef double lf;
const int N = 100005;
const lf eps = 1e-8;
 
int n, a[N];
ll ans;
int i,j;
int main()
{
	cin>>n;
	for ( i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for ( i=j = 0; i < n; ++i)
	{
		while(a[j]+eps<0.9*a[i])
			++j;
		ans+=i-j;
	}
	printf("%lld\n",ans);
	return 0;
}