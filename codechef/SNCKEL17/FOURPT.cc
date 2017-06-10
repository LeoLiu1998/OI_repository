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
#define double long double
const double eps=1e-10;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
pii p[10];
struct Point{
    double x, y;
};
struct Line{
    double a, b, c;
};
bool Legal(Point a) {
	return (fabs(a.x)<1e6)&&(fabs(a.y)<1e6);
}
Line getLine(Point p1, Point p2){
    Line tmp;
    tmp.a = p1.y - p2.y;
    tmp.b = p2.x - p1.x;
    tmp.c = p1.x*p2.y - p2.x*p1.y;
    return tmp;
}
 
bool parallel(Line l1, Line l2){
    return abs(l1.a*l2.b - l2.a*l1.b) < eps;
}
 
bool lineEqual(Line l1, Line l2){
    if(!parallel(l1, l2)) return false;
    return (abs(l1.a*l2.c - l2.a*l1.c) < eps && abs(l1.b*l2.c - l2.b*l1.c) < eps) ;
}
 
Point getIntersect(Line l1, Line l2){
    Point tmp;
    tmp.x = (l1.b*l2.c - l2.b*l1.c) / (l1.a*l2.b - l2.a*l1.b);
    tmp.y = (l1.c*l2.a - l2.c*l1.a) / (l1.a*l2.b - l2.a*l1.b);
    return tmp;
}
int Calc(pii a,pii b) {
	return a.fi*b.se-a.se*b.fi;
}
bool Check(pii a,pii b,pii c) {
	pii la=mp(b.fi-a.fi,b.se-a.se);
	pii lb=mp(c.fi-b.fi,c.se-b.se);
	if(!Calc(la,lb)) {
		return 1;
	}
	return 0;
}
vector<pii> s;
pair<pii,pii> LR(int a,int b, int c) {
	s.clear(); s.pb(p[a]); s.pb(p[b]); s.pb(p[c]);
	return mp(s[0],s[2]);
}
void Print(pii a) {
	Ps(a.fi); Ps(a.se);
}
pii SEG(pii a,pii b) {
	return mp(b.fi-a.fi,b.se-a.se);
}
ll dis2(pii a,pii b) {
	return (ll)(b.se-a.se)*(b.se-a.se)+(ll)(b.fi-a.fi)*(b.fi-a.fi);
}
bool vis[4];
Point pp[10];
bool cmp(pii a,pii b) {
	if(a.se==b.se) {
		return a.fi>b.fi;
	}
	return a.se<b.se;
}
int main() {
	int T;
	R(T);
	while(T--) {
		for(int i=1;i<=4;++i) {
			R(p[i].fi); R(p[i].se);
		}
		sort(p+1,p+5);
		for(int i=1;i<=4;++i) {
			pp[i].x=p[i].fi;
			pp[i].y=p[i].se;
		}
		pii la=SEG(p[1],p[2]);
		pii lb=SEG(p[3],p[4]);
		Line l1,l2,l3,l4;
		l1=getLine(pp[1],pp[2]);
		l2=getLine(pp[3],pp[4]);
		l3=getLine(pp[1],pp[4]);
		l4=getLine(pp[2],pp[3]);
		if(lineEqual(l1,l2)) {
			printf("YES ");
			Print(p[1]); Print(p[3]); Print(p[4]);
			puts("");
			continue;
		}
		if((Calc(la,lb)==0)&&(dis2(p[1],p[2])==dis2(p[3],p[4]))) {
			puts("NO");
			continue;
		}
		//printf("YES ");
		Point is1=getIntersect(l1,l2);
		//Point is2=getIntersect(l3,l4);
		if(Legal(is1)) {
			printf("YES %.12Lf %.12Lf ",is1.x,is1.y);	
			Print(p[1]);
			Print(p[4]);
		} else {
			//printf("%.8f %.8f ",is2.x,is2.y);
			sort(p+1,p+5,cmp);
			rep(i,1,4,1) {
				pp[i].x=p[i].fi;
				pp[i].y=p[i].se;
			}
			l3=getLine(pp[1],pp[2]);
			l4=getLine(pp[3],pp[4]);
			is1=getIntersect(l3,l4);
			if(Legal(is1)) {
				printf("YES %.12Lf %.12Lf ",is1.x,is1.y);
				Print(p[1]);
				Print(p[4]);
			}
		}
		printf("NO");
		puts("");
		/*for(int i=1;i<=4;++i) {
			vis[i]=1;
			for(int j=i+1;j<=4;++j) {
				vis[j]=1;
				for(int k=j+1;k<=4;++k)	 {
					vis[k]=1;
					if(Check(p[i],p[j],p[k])) {
						printf("YES ");
						for(int q=1;q<=4;++q) {
							if(!vis[q]) {
								Print(p[q]);
							}
						}
						pair<pii,pii> Ans=LR(i,j,k);
						Print(Ans.fi); Print(Ans.se);
						puts("");
						goto NEX;
					}
					vis[k]=0;
				}
				vis[j]=0;
			}
			vis[i]=0;
		}*/
NEX:
		continue;
	}
}

