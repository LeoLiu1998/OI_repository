/*Copyright (c)2015 Ye Guanghao
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
#define R(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
const double pi=3.1415926535898;
using namespace std;
int main(int argc, char const *argv[])
{
	int k;
	R(k);
	while(k--){
		int y,m,d;
		R(y);
		R(m);
		R(d);
		if(((m==9||m==1)&&d==30)||!((m+d)%2))
			puts("YES");
		else
			puts("NO");
	};
	return 0;
}