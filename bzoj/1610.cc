#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){}
};
inline double k(Point a,Point b) {
	return ((double(a.y)-b.y))/(a.x-b.x);
}
const int maxn=205;
Point p[maxn];
const int Keps=1e-8;
vector <double> ans;
int n;
#define R(x) scanf("%d",&x);
#define Pd(x) printf("%f\n",x);
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(p[i].x); R(p[i].y);
	}
	for(int i=1;i<n;++i) {
		for(int j=i+1;j<=n;++j) {
			ans.push_back(k(p[i],p[j]));	
//			Pd(k(p[i],p[j]));
		}
	}
	int Ans=0; 
	sort(ans.begin(),ans.end());
	double last=ans[0];
	Ans++;
	for(int i=1;i<ans.size();++i) {
		if(fabs(ans[i]-last)>Keps) {
			Ans++;
			last=ans[i];
		}
	}
	printf("%d\n",Ans);
}
