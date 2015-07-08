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
const double kEps=1e-8;
struct Vector{
	double x,y;
	Vector(double _x=0,double _y=0):x(_x),y(_y){}	
	void Get(){
		cin>>x>>y;
	}
};
typedef struct Vector Point;
Point a,b,c,e,f,p,r,q;
Point oneThird(Point m,Point n) {
	Point ret((m.x*2+n.x)/3,(m.y*2+n.y)/3);
	return ret;
}
inline double  operator * (Vector a,Vector b) {
	return a.x*b.y+a.y*b.y;
}
inline double  operator ^ (Vector a,Vector b) {//det
	return a.x*b.y-b.x*a.y;
}
int main(){
	int T;
	R(T);
	while(T--) {
		a.Get();
		b.Get();
		c.Get();
	}
	d=oneThird(b,c);
	f=oneThird(a,b);
	e=oneThird(c,a);
}
