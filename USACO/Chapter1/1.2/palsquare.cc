/*ID: yeguang2
PROG: palsquare
LANG: C++
*/
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define PROB  "palsquare"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect(){
	freopen(PROB ".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
int BASE;
int num[20];
int convert(int k){
	int cnt=-1;
	memset(num,0,sizeof(num));
	while(k){
		num[++cnt]=k%BASE;
		k/=BASE;
	}
	return cnt;
}
int a[20];
string ma="0123456789ABCDEFGHI";
void pri(int k){
	int cnt=-1;
	memset(a,0,sizeof(a));
	while(k){
		a[++cnt]=k%BASE;
		k/=BASE;
	}
	for(int i=cnt;i>=0;--i){
		cout<<ma[a[i]];
	}
}
void check(int cur) {
	int sqr=cur*cur;
	int len=convert(sqr);
	for(int i=0,j=len;i<=len&&j>=0;i++,j--){
		if(num[i]!=num[j])	return ;
	}
	pri(cur);cout<<" ";pri(cur*cur); 
	puts("");
}
int main(){
	Redirect();
	R(BASE);
	for(int i=1;i<=300;++i) {
		check(i);
	}
	return 0;
}
