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
int a[20];
int len;
int ans;
int y;
int init();
long long getnum();
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--)
	{

		ans=0;
		len=init();
		sort(a+1,a+len+1);
		scanf("%d",&y);
		do{
			if(!(getnum()%y))
				ans++;
		}while(next_permutation(a+1,a+len+1));
		printf("%d\n",ans);
	}
	return 0;
}

int init()
{
	register char ch;
	int cnt=1;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch<='9' && ch>='0')
	{
		a[cnt]=ch-'0';
		cnt++;
		ch=getchar();
	}
	return cnt-1;
}

long long getnum()
{
	long long ret=0;
	for(int i=1;i<=len;i++)
	{
		ret*=10;
		ret+=a[i];
	}
	return ret;
}