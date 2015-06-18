/*Copyright (c)2015 YeGuanghao
 *This source-code is licensed under GPLv3
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
inline void  R(int &x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   x*=f;
}
#define P(x) printf("%d\n",x)
int tot=0;
int odd_num=0;
int even_num;
int choose_num;
int n,lef,temp;
int main()
{
	R(n); R(lef);
	for(int i=1;i<=n;++i) {
		R(temp);
		tot+=temp;
		odd_num+=temp%2;
	}
	choose_num=n-lef;
	even_num=n-odd_num;
	if(!(k%2)) {
		puts("Stannis");
	} else {
		
	}
	return 0;
}
