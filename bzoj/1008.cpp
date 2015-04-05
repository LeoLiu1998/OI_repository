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
const int F=100003;
long long n,m;
long long sqr(long long a){return a*a;}
long long pow(long long a,long long b)
{
    if (b==1) return a;
    if (b==0) return 1;
    long long p=sqr(pow(a,b/2))%F;
    if (b%2) p=(p*a)%F;
    return p;
}
int main()
{
    scanf("%lld%lld",&m,&n);
    cout<<(pow(m,n)%F-((m%F*pow(m-1,n-1))%F)+F)%F<<endl;
	return 0;
}