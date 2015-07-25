/*
ID: yeguang2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#define PROB "namenum" 
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void Redirect() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
set <string> dic;
void getDic(){
//	freopen("dict.txt","r",stdin);
	ifstream DicF;
	DicF.open("dict.txt");
	string temp;
	while(DicF>>temp) {
//		cout<<temp<<endl;
		dic.insert(temp);
	}
	DicF.close();
}
string Map[10];
char cur[100];
string ans;
string test;
int len;
char now[100];
int choose[20];
bool flag;
bool check(){
	for(int i=0;i<len;++i) {
		now[i]=Map[cur[i]-'0'][choose[i]];	
	}
	test=now;
//	cout<<test<<"      !"<<endl;
	if(dic.count(test)) {
		cout<<test<<endl;
		return 1;
	}
	return 0;
}
void solve(int k) {
	if(k==len) {
		if(check()) {
			flag=1;
		}
		return;
	}
	for(int i=0;i<3;++i) {
		choose[k]=i;
		solve(k+1);
	}
	return ;
}
int main(){
	getDic();
	Redirect();
	Map[2]="ABC"; Map[3]="DEF"; Map[4]="GHI"; Map[5]="JKL"; Map[6]="MNO"; Map[7]="PRS"; Map[8]="TUV"; Map[9]="WXY";
	scanf("%s",cur);
	len=strlen(cur);
	solve(0);
	if(!flag){
		ans="NONE";
		cout<<ans<<endl;
	}
}
