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

int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d;     //读入开始、结束时间
	if (d<b) {d+=60;c-=1;}    //判断结束时间的分钟是否小于开始时间的分钟
	f=d-b;e=c-a;      //退位
	cout<<e<<" "<<f<<endl;     //打印
	return 0;
}