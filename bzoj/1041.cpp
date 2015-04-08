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

long long R,ans;

long long gcd(long long x,long long y){return x%y==0? y:gcd(y,x%y);}

bool check(long long y,double x)
{
	if(x==floor(x))
	{
		long long x1=(long long)floor(x);
		if(gcd(x1*x1,y*y)==1&&x1*x1!=y*y)
			return true;
	}
	return false;
}

int main()
{
	scanf("%I64d",&R);
	for(long long d=1;d<=sqrt(2*R);d++)
	{
		if((2*R)%d==0)
		{
			for(long long a=1;a<=(long long)sqrt(2*R/(2*d));a++)
			{
				double b=sqrt(((2*R)/d)-a*a);
				if(check(a,b))ans++;
			}
			if(d!=(2*R)/d)
			{
				for(long long a=1;a<=(long long)sqrt(d/2);a++)
				{
					double b=sqrt(d-a*a);
					if(check(a,b))
						ans++;
				}
			}
		}
	}    
	cout<<ans*4+4;
	
	return 0;
}
