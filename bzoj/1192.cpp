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
long long a=1;
long long aim;
int main(int argc, char const *argv[])
{
	cin>>aim;
	for(int i=1;;i++)
	{
		a*=2;
		if(a>aim){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}