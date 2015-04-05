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
int sum,a,b;
int main(int argc, char const *argv[])
{
	cin>>a>>b;
	sum=a*10+b;
	cout<<sum/19<<endl;
	return 0;
}