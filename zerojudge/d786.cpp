/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
const double pi=3.1415926535898;
using namespace std;
double sum;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		int n;
		scanf("%d",&n);
		register int temp;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%.2f\n",sum/n );
	}
	return 0;
}