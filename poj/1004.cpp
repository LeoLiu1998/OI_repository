//Copyright (c)2014 Ye Guanghao
//This sourcecode is licensed under GPLv3
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
using namespace std;
double temp;
int main()
{
    double ans=0;
    while (cin>>temp)
    	ans+=temp;
	ans/=12.0;
	printf("$%.2f",ans);
	return 0;
}
