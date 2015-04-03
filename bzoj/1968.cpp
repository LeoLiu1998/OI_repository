/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define ONLINEJUDGE
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

int n;
int ans;
int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		ans+=n/a;
	printf("%d\n",ans);
	return(0);
}
