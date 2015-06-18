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
//inline int  R(int &x)
//{
 //   x=0;int f=1;char ch=getchar();
   // while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   // while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  // x*=f;
//}
#define R(x) scanf("%lf",&x)
#define P(x) printf("%d\n",x)
struct MA {
	double a[5][5];
	MA() {
		memset(a,0,sizeof(a));
	}
};
MA ma,mb,ms;
double del;
double x1,x2,y,y2;
int main() {
	R(ma.a[1][1]); R(ma.a[1][2]); R(ma.a[2][1]); R(ma.a[2][2]);
	x1=ma.a[1][1]+ma.a[1][2];
	x2=ma.a[2][1]+ma.a[2][2];
	y=ma.a[1][1]+ma.a[2][1];
	y2=ma.a[1][2]+ma.a[2][2];
	del=(x1+y2)+(y-x1);
	if(del==0) {
		puts("0");
		return 0;
	}
	del=x1*y2/del;
	mb.a[1][2]=del;
	mb.a[1][1]=x1-del;
	mb.a[2][1]=y-mb.a[1][1];
	mb.a[2][2]=y2-del;
	printf("%.9lf\n",fabs(ma.a[1][2]-del));
}
