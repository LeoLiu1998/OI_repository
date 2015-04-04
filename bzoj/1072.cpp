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
const double pi=3.1415926535898;
using namespace std;
int a[20];
int x,y;
int len;
int  ans;
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T;
	while(T--)
	{
		ans=0;
		scanf("%d%d",&x,&y);
		l=divide(x);
		while(next_permutation(a+0,a+len))
		{
			if(!getnum()%y)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}