//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
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
struct Rec{
	int x,y;
	Rec(int _x=0,int _y=0):x(_x),y(_y){if(x>y) swap(x,y);}
	void Read(){
		R(x); R(y);
		if(x>y) swap(x,y);
	}
};
Rec big,a,b,c1,c2,c3,c4;
bool check(Rec cur) {
	if(cur.x<=big.x&&cur.y<=big.y) return 1;
	return 0;
}
int main() {
	big.Read(); a.Read(); b.Read();
	c1=Rec(a.x+b.x,max(a.y,b.y));
	c2=Rec(a.y+b.x,max(a.x,b.y));
	c3=Rec(a.x+b.y,max(a.y,b.x));
	c4=Rec(a.y+b.y,max(a.x,b.x));
	if(check(c1)||check(c2)||check(c3)||check(c4)) {
		puts("YES");
	} else {
		puts("NO");
	}
}
