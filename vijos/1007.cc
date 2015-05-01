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
struct Poi {
	double x,y;
	inline double operator + (const Poi &a)const {
		double ret=0;
		ret+=(x-a.x)*(x-a.x);
		ret+=(y-a.y)*(y-a.y);
		ret=sqrt(ret);
		return ret;
	}
};
const int maxn=105;
Poi poi[maxn];
double ans=0;
int main(int argc, char const *argv[])
{

	int n;
	double r;
	R(n);
	scanf("%lf",&r);
	ans+=pi;
	ans*=2*r;
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf",&poi[i].x,&poi[i].y);
	}
	for (int i = 0; i < n; ++i){
		ans+=(poi[i%n]+poi[(i+1)%n]) ;
	}
	printf("%.2f\n",ans);
	return 0;
}