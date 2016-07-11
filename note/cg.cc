//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
	Point operator - (const Point &b) const {
		return Point(x-b.x,y-b.y);
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x,y+b.y);
	}
	int operator ^ (const Point &b) const {
		return x*b.y-y*b.x;
	}
	double operator * (const Point &b) const {
		return x*b.x+y*b.y;
	}
};
bool toLeft(Point a, Point b, Point x) {
	return ((b-a)^(x-a)) > 0;
}
bool inTriangle(Point a, Point b, Point c, Point x) {
	bool abL=toLeft(a,b,x);
	bool bcL=toLeft(b,c,x);
	bool caL=toLeft(c,a,x);
	return (abL==bcL)&&(bcL==caL);
}
Point origin(0,0);
const int maxn=100050;
int n;
bool cmp(const Point &a, const Point &b) {
	return atan2(a.x-origin.x,a.y-origin.y)<atan2(b.x-origin.x,b.y-origin.y);
}
vector<Point> extremePoint(int size,Point p[]) {
	bool *isExtreme=new bool[size+10];
	memset(isExtreme,1,sizeof(bool) * (size+10));
	for(int i=1;i<=size;++i) {
		for(int j=i+1;j<=size;++j) {
			for(int k=j+1;k<=size;++k) {
				for(int x=1;x<=size;++x) {
					if(x==i||x==j||x==k||(!isExtreme[x])) continue;
					if(inTriangle(p[i],p[j],p[k],p[x])) isExtreme[x]=0;
				}
			}
		}
	}
	vector<Point> ret;
	for(int i=1;i<=size;++i) {
		if(isExtreme[i]) ret.pb(p[i]);
		else origin=p[i];
	}
	sort(ret.begin(),ret.end(),cmp);	
	origin=Point(0,0);
	return ret;
}
double Circum(vector<Point> p) {
	double ret=0;
	for(int i=1;i<p.size();++i) {
		ret+=hypot(p[i].x-p[i-1].x,p[i].y-p[i-1].y);
	}
	ret+=hypot(p[p.size()-1].x-p[0].x,p[p.size()-1].y-p[0].y);
	return ret;
}
Point point[maxn];

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		scanf("%lf%lf",&point[i].x,&point[i].y);
	}
	double ans=Circum(extremePoint(n,point));
	printf("%.1f\n",ans);
}

