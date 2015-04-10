/*Copyright (c)2014 Ye Guanghao
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

int a[7];
void add()
{
	a[1]++;
	int cnt=1;
	while(a[cnt]==2)
	{
		a[cnt]=0;
		cnt++;
		a[cnt]++;
	}
}
void print()
{
	for (int i = 6; i > 0; --i)
	{
		printf("%d",a[i] );
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	for(int i=1;i<=1<<6;i++)
	{
		print();
		add();
	}
	return 0;
}

