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
double dfs(double w,double h,int n)
{
	if (n==1) return max(w/h,h/w);
	double ans=1e+20;
	for (int a=1;a<=n-1;a++)
	{
		int b=n-a;
		ans=min(ans,max(dfs(w*a/n,h,a),dfs(w*b/n,h,b)));
		ans=min(ans,max(dfs(w,h*a/n,a),dfs(w,h*b/n,b)));
	}
	return ans;
}

int main()
{
	double w,h;
	int n;
	scanf("%lf%lf%d",&w,&h,&n);
	printf("%.6lf\n",dfs(w,h,n));

	return 0;
}