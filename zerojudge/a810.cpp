/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535898;
using namespace std;
typedef long long LL;
const LL INF =0x7fffffffffffffff;
LL gcd(LL a,LL b)
{
	if(!(a%b)) return b;
	return gcd(b,a%b);
}
LL LCM(LL a,LL b)
{
	if(a<b)	swap(a,b);
	if(b==0) return 0;
	a/=gcd(a,b);
	if(a> INF/b) return INF;
	return a*b;
}
LL NUM(LL a, LL x, LL y, LL l)
{
    LL ans = ((x==0ll) ? 0ll : a/x);
    ans += ((y==0ll) ? 0ll : a/y);
    ans -= ((l==0ll) ? 0ll : a/l);
   
     return ans;
}

int main()
{
    LL a,b,x,y,l,ans;
    int zero;
    
    scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
    
    zero = ((a<0ll && b>0ll) || (a==0ll) || (b==0ll));
    x = abs(x); y = abs(y);
    l = LCM(x,y);
    if( a==0ll && b>0ll ) a++;
    if( b==0ll && a<0ll ) b--;

    if( a<0ll && b<0ll)
        ans = NUM(-a,x,y,l) - NUM(-b-1,x,y,l) + zero;
    else
        if( a>0ll && b>0ll )
            ans = NUM(b,x,y,l) - NUM(a-1,x,y,l) + zero;
        else
            ans = NUM(b,x,y,l) + NUM(-a,x,y,l) + zero;

    printf("%lld\n", ans);

    return 0;
}