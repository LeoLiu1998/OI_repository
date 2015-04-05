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

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	if(n==1)
		cout<<1;
	else
		cout<<(min(k,n-k+1)<<1);
	return 0;
}