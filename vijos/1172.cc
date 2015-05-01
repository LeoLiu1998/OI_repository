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
int main (){
	long n;int i;
	scanf ("%ld",&n);
	long a[68]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600,32432400,36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600,245044800,294053760,367567200,551350800,698377680,735134400,1102701600,1396755360};
	if (n>1396755360){printf ("1396755360\n");return 0;}
	for (i=0;i<68;i++){
		if (a[i]>n) {
			if (n==0) {
				printf ("0\n");break;
			} else {
				printf ("%ld\n",a[i-1]);break;
			}
		}
	}	
	return 0;
}