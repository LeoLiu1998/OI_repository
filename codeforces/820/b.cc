//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
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
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9

using namespace std;
typedef pair<double, double> pdd;
const double pi = acos(-1);

inline double format(double a) {
	return fabs(a)<1e-7?0:a;
}
int n,r,t;
pdd point[300050];
double dis2(pdd x,pdd y) {
	return (x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se);
}
inline double Calc(pdd x,pdd y,pdd z) {
	double rad=dis2(x,y)+dis2(y,z)-dis2(x,y)/2;
	rad/=sqrt(dis2(x,y));
	rad/=sqrt(dis2(y,z));
	return rad/3.1415926535*180;
}
inline double Calc(int x,int y,int z) {
	return Calc(point[x],point[y],point[z]);
}
pii ans;
double a;
double cur_ans=LLONG_MAX;
int main2() {
	int  n1=2, n2=1;
	pdd  p1, p2;
	scanf("%d%d", &n,&a);
	//scanf("%lf%lf%lf%lf", &p1.first, &p1.second, &p2.first, &p2.second);
	p1=mp(0,0);
	p2=mp(0,1);
	if(n1 > n2) swap(n1, n2), swap(p1, p2);
	pdd m, o;
	m.first = (p1.first + p2.first)/2;
	m.second = (p1.second + p2.second)/2;
	o.first = m.first + (p2.second - p1.second) / tan(pi * (n2-n1) / n) / 2;
	o.second = m.second - (p2.first - p1.first) / tan(pi * (n2-n1) / n) / 2;
	point[n1].first = p1.first -= o.first, point[n1].second = p1.second -= o.second;
	double sinn = sin(pi*2/n), coss = cos(pi*2/n);
	pdd tmp = p1;
	for(int j = n1 + 1; ; j++) {
		if(j > n) j -= n;
		if(j == n1) break;
		point[j].first = tmp.first*coss + tmp.second*sinn;
		point[j].second = -tmp.first*sinn + tmp.second*coss;
		tmp = point[j];
	}
	for(int i=2; i<=n; ++i) {
		int l=i+1,r=n;
		while(r-l>1) {
			int wxh,mwxh;
			wxh=(l+r)>>1;
			mwxh=(wxh+r)>>1;
			double am=Calc(i,1,wxh);
			double amm=Calc(i,1,mwxh);
			if(fabs(amm-a)<fabs(am-a)) {
				r=mwxh;
			} else {
				l=wxh;
			}
		}
		double lv=Calc(i,1,l),rv=Calc(i,1,r);
		if(cur_ans>fabs(a-lv)) {
			cur_ans=fabs(a-lv);
			ans=mp(i,l);
		}
		if(cur_ans>fabs(a-rv)) {
			cur_ans=fabs(a-rv);
			ans=mp(i,r);
		}
	}
	Ps(ans.fi);
	Ps(1);
	Pn(ans.se);
}
using namespace std;
inline void splay(int &v) {
	v=0;
	char c=0;
	int p=1;
	while(c<'0' || c>'9') {
		if(c=='-')p=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') {
		v=(v<<3)+(v<<1)+c-'0';
		c=getchar();
	}
	v*=p;
}
#define pi acos(-1.0)
struct Point {
	double x,y;
} p[111111],p1,p2,p3,p4;
Point pp[111111];
double check(double a) {
	return fabs(a)<eps?0:a;
}
double x[111111],y[111111];
int ans1,ans2,ans3;
double dis(int a,int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double an(int a,int b,int c) {
	double A=dis(b,c);
	double B=dis(a,c);
	double C=dis(a,b);
	double cosb=(A*A+C*C-B*B)/(2*A*C);
	return acos(cosb)*180/pi;
}
int main() {
	int  n1=2, n2=1;
	pdd p11,p21;
	R(n);
	scanf("%f",&a);
	pdd m, o;
	m.first = (p11.first + p21.first)/2;
	m.second = (p11.second + p21.second)/2;
	o.first = m.first + (p21.second - p11.second) / tan(pi * (n2-n1) / n) / 2;
	o.second = m.second - (p21.first - p11.first) / tan(pi * (n2-n1) / n) / 2;
	point[n1].first = p11.first -= o.first, point[n1].second = p11.second -= o.second;
	double sinn = sin(pi*2/n), coss = cos(pi*2/n);
	pdd tmp = p11;
	for(int j = n1 + 1; ; j++) {
		if(j > n) j -= n;
		if(j == n1) break;
		point[j].first = tmp.first*coss + tmp.second*sinn;
		point[j].second = -tmp.first*sinn + tmp.second*coss;
		tmp = point[j];
	}
	double yjq;
	r=1,t=2;
	p1.x=1,p1.y=0,p2.x=0,p2.y=0;
	yjq=1.0/n*pi;
	if(t-r>n/2)yjq+=3*pi/2;
	else yjq-=pi/2;
	p3.x=(p1.x+p2.x)/2;
	p3.y=(p1.y+p2.y)/2;
	p4.x=p3.x-(p3.y-p1.y)*tan(yjq);
	p4.y=p3.y+(p3.x-p1.x)*tan(yjq);
	r--;
	t--;
	pp[r]=p1;
	yjq=2.0/n*pi;
	for(int i=r+1;; i++) {
		if(i%n==r)break;
		pp[i%n].x=p4.x+(pp[(i-1+n)%n].x-p4.x)*cos(-yjq)-(pp[(i-1+n)%n].y-p4.y)*sin(-yjq);
		pp[i%n].y=p4.y+(pp[(i-1+n)%n].x-p4.x)*sin(-yjq)+(pp[(i-1+n)%n].y-p4.y)*cos(-yjq);
	}
	for(int i=0; i<n; i++) {
		x[i+1]=check(pp[i].x);
		y[i+1]=check(pp[i].y);
	}
	double ansq=1e18;
	for(int i=n; i>=3; i--) {
		int l=2,r=i-1;
		while(l!=r) {
			int wxh=l+r>>1;
			if(an(1,i,wxh)<a)l=wxh+1;
			else r=wxh;
		}
		if(fabs(an(1,i,l)-a)<ansq) {
			ansq=fabs(an(1,i,l)-a);
			ans1=1,ans2=i,ans3=l;
		}
	}
	Ps(ans1); Ps(ans2); Pn(ans3);//printf("%d %d %d",ans1,ans2,ans3);
}
