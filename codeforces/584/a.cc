//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
int t;
int main() {
	R(n);
	R(t);
	if(n==1&&t==10) {
		Pn(-1);
		return 0;
	} 
	if(t==10) {
		printf("1");
		n--;
		while(n--) {
			printf("%d",0);
		}
		return 0;
	}
	while(n--) {
		printf("%d",t);
	}
}
