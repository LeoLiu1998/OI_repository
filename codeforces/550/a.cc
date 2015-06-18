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
const int maxn=100500;
char s[maxn];
char s1[maxn];
int len;
bool haveAB,haveBA;
int main()
{
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<=len;++i) {
		s1[i]=s[i];
	}
	for(int i=0;i<=len;++i) {
		if(s[i]=='A') {
			if(s[i+1]=='B') {
				s[i]=s[i+1]='0';
				haveAB=1;
				break;
			}
			if(s[i+1]!='A')
				i++;
		}
	}
	for(int i=0;i<=len;++i) {
		if(s[i]=='B') {
			if(s[i+1]=='A') {
				s[i]=s[i+1]='0';
				haveBA=1;
				break;
			}
			if(s[i+1]!='B')
				i++;
		}
	}
	if(haveAB&&haveBA) {puts("YES");return 0;}
	if(!(haveAB||haveBA)) {puts("NO");return 0;}
	haveAB=haveBA=0;
	for(int i=0;i<=len;++i) {
		if(s1[i]=='B') {
			if(s1[i+1]=='A') {
				s1[i]=s1[i+1]='0';
				haveBA=1;
				break;
			}
			if(s1[i+1]!='B')
				i++;
		}
	}
	for(int i=0;i<=len;++i) {
		if(s1[i]=='A') {
			if(s1[i+1]=='B') {
				s1[i]=s1[i+1]='0';
				haveAB=1;
				break;
			}
			if(s1[i+1]!='A')
				i++;
		}
	}
	if(haveAB&&haveBA){puts("YES");return 0;}
	puts("NO");
}
