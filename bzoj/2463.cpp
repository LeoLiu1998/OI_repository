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

int main(int argc, char const *argv[])
{
	int n;
  	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		if(n%2==0) printf("Alice\n");
 		else printf("Bob\n");
	}
	return 0;
}
