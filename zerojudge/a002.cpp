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
int a,b;
int main(int argc, char const *argv[])
{
	while(cin>>a>>b)
	{
		cout<<b+a<<endl;
	}
	return 0;
}